#include "game_state.h"
#include <QSize>
#include "choose_leader.h"

game_state::game_state()
{
}



int game_state::rowCount(const QModelIndex &parent) const
{
    int sz =this->gamers.size();
#if MVC_DEBUG
    qWarning("game_state::rowCount is %d",sz);
#endif
    return sz;
}

int game_state::columnCount(const QModelIndex &parent) const

{
    int sz =this->turn.size();
#if MVC_DEBUG
    qWarning("game_state::columnCount %d",sz);
#endif
    return turn.size();
}


QVariant game_state::data (const QModelIndex &index, int role) const
{
    if (role == Qt::SizeHintRole)
           return QVariant (QSize(25,25));

    if (role != Qt::DisplayRole)
        return QVariant();

    gamer_state gs = turn.at(index.column()).at(index.row());
    game_turn tr = turn.at(index.column());
    unsigned int pc = 0;

    if ( tr.agreement)
        pc |= pic(agreed_mood);

    if ( tr.disagreement)
        pc |= pic(disagreed_mood);

    if ( tr.success)
        pc |= pic(success_mood);

    if ( tr.fail)
        pc |= pic(failed_mood);

    if (tr.fail_cnt)
        pc |= tr.fail_cnt << 8;

    if (tr.cnt_participants())
        pc |= tr.cnt_participants() << 12;


    if ( gs.is_leader)
        pc |= pic(leader);

    if ( gs.is_agreed)
        pc |= pic(agreed);

    if ( gs.is_disagreed)
        pc |= pic(disagreed);

    if ( gs.is_nominate)
        pc |= pic(nominated);

    if ( gs.mission_successed)
        pc |= pic(win_participant);

    if ( gs.mission_failed)
        pc |= pic(lose_participant);

    return QVariant (pc);
    return QVariant(index.column() + index.row()*20);
}


QVariant game_state::headerData ( int section, Qt::Orientation orientation, int role) const
{

    if (role != Qt::DisplayRole)
        return QVariant();

    if ( orientation == Qt::Vertical)
    {
        return QVariant (this->gamers.at(section));
    }

    if ( orientation == Qt::Horizontal)
    {
        if ((this->turn.size() == 0) || section >= turn.size())
            return QVariant ();

        if (this->turn.at(section).is_setting_leader())
            return QVariant (tr("Leader"));

        if (this->turn.at(section).is_nomination())
            return QVariant (tr("Nominating"));

        if (this->turn.at(section).is_voting())
            return QVariant (tr("Voting"));

        if (this->turn.at(section).is_executing())
            return QVariant (tr("Executing"));

    }

    return QVariant (QString::fromLocal8Bit(("fucked up")));
}



bool game_state::set_gamers(QStringList gamers_l)
{
    beginInsertRows(QModelIndex(), gamers.size(), gamers_l.size()-1);

    gamers.append(gamers_l);

    sz = gamers.size();

    endInsertRows();

    update_all();

    return 1;
}


bool game_state::new_leader(int number)
{
    if (gamers.size() < number)
        return 0;

    else
    {
        beginInsertColumns(QModelIndex(), turn.size(),turn.size());

        game_turn gt(this->sz);
        gt.set_leader(number);
        turn.push_back(gt);

        endInsertColumns();

        update_all();

        return 1;
    }
}



bool game_turn::set_leader(int leader)
{
    for (int i =0; i < this->size(); i++)
    {
        if (i == leader)
        {
            this->operator [](i).is_leader  = 1;
        }
    }

}

bool game_turn::is_nomination() const
{
    for (int i =0; i < this->size(); i++)
    {
        if (this->operator [](i).is_nominate  == 1)
        {
            return 1;
        }
    }
    return 0;
}

bool game_turn::is_setting_leader() const
{
    for (int i =0; i < this->size(); i++)
    {
        if (this->operator [](i).is_leader  == 1)
        {
            return 1;
        }
    }
    return 0;
}


bool game_turn::is_voting() const
{
    for (int i =0; i < this->size(); i++)
    {
        if ((this->operator [](i).is_agreed)  == 1 || (this->operator [](i).is_disagreed))
        {
            return 1;
        }
    }
    return 0;
}


bool game_turn::is_executing() const
{
    for (int i = 0 ; i < this->size(); i++)
    {

        if ((this->operator [](i).mission_failed)  == 1 || (this->operator [](i).mission_successed))
        {
            return 1;
        }
    }
    return 0;

}

bool game_state::nominate(QVector<bool> games)
{
    if (gamers.size() != games.size())
        return 0;

    else
    {
        beginInsertColumns(QModelIndex(), turn.size(),turn.size());

        game_turn gt(this->sz);
        gt.nominate(games);
        turn.push_back(gt);

        endInsertColumns();

        update_all();

        return 1;
    }

}

bool game_turn::nominate(QVector<bool> vec)
{
    for ( int i = 0; (i < vec.size()) && (i < this->size()) ; i++)
    {
        this->operator [](i).is_nominate = vec.at(i);

    }
    return 1;
}


bool game_state::approve(QVector<bool> aproved,bool agreement)
{

    if (gamers.size() != aproved.size())
        return 0;


    else
    {
        beginInsertColumns(QModelIndex(), turn.size(),turn.size());

        game_turn gt(this->sz);
        gt.approve(aproved, agreement);
        turn.push_back(gt);

        endInsertColumns();

        QModelIndex top = createIndex( 0,turn.size(), 0);
        QModelIndex bottom = createIndex( gamers.size(),turn.size(), 0);

        emit dataChanged(top, bottom);


        return 1;
    }

}

bool game_turn::approve(QVector<bool> vec, bool l_agreement)
{

    for ( int i = 0; (i < vec.size()) && (i < this->size()) ; i++)
    {
        this->operator [](i).is_agreed = vec.at(i);
        this->operator [](i).is_disagreed = !vec.at(i);


    }
    this->agreement = l_agreement;
    this->disagreement = ! l_agreement;

    return 1;


}

QVector <bool> game_state::last_nominated()
{
    QVector <bool> rs;
    rs.resize(this->gamers.size());

    for ( int i = this->turn.size()-1; i >= 0; --i)
    {
        if (turn.operator [](i).is_nomination() )
        {
            game_turn tr = turn.operator [](i);

            for ( int i = 0; i < tr.size(); i++)
            {
                 rs.operator[](i) =tr.operator[](i).is_nominate;
            }
            return rs;
        }

    }

}

game_turn::game_turn ( ){
    fail_cnt =0;

    disagreement = 0;
    agreement =0 ;
    success = 0;
    fail =0 ;
}

game_turn::game_turn (int gamers_count)
{
    fail_cnt = 0;
    disagreement = 0;
    agreement =0 ;
    success = 0;
    fail =0 ;

    {
        this->resize(gamers_count);
    }
}

bool game_state::execute(QVector<bool> participants, bool successed, int fail_cnt)
{

    if (gamers.size() != participants.size())
        return 0;


    else
    {
        beginInsertColumns(QModelIndex(), turn.size(),turn.size());

        game_turn gt(this->sz);
        gt.execute(participants,  successed,fail_cnt);
        gt.success = successed;
        gt.fail = !successed;

        turn.push_back(gt);

        endInsertColumns();

        update_all();

        return 1;
    }

}

bool game_turn::execute(QVector<bool> participants, bool succed,int fail_cnt_l)
{

    for ( int i = 0; (i < participants.size()) && (i < this->size()) ; i++)
    {
        if ( participants.at(i))
        {
            this->operator [](i). mission_successed = succed;
            this->operator [](i).  mission_failed = !succed;
        }
    }

    this->fail_cnt = fail_cnt_l;

    return 1;


}

int  game_turn::cnt_participants()
{
    int k = 0;

    for ( int i = 0;i < this->size() ; i++)
    {
            if ( (this->operator [](i).mission_successed) || (this->operator [](i).mission_failed))
            {
                k++;
            }
    }
       return k;

}

void game_state::turn_back()
{

    if (this->turn.size() == 0)
        return;

        beginRemoveColumns(QModelIndex(), turn.size()-1,turn.size()-1);


        turn.pop_back();
        endRemoveColumns();

        update_all();
}


void game_state::update_all()
{
    QModelIndex top = createIndex( 0,0, 0);
    QModelIndex bottom = createIndex( gamers.size(),turn.size()-1, 0);

    emit dataChanged(top, bottom);

}
