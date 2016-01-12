#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>


enum pic {
    none =0x0,
    leader = 0x1,
    agreed = 0x2,
    disagreed = 0x3,
    nominated = 0x4,
    win_participant = 0x5,
    lose_participant = 0x6,

    none_mood = 0x0,
    failed_mood = 0x10,
    success_mood = 0x20,
    agreed_mood = 0x30,
    disagreed_mood = 0x40
};


struct gamer_state
{
    bool is_leader;

    bool is_nominate;
    bool is_participant;
    int total_nominate;
    int need_to_fail;

    bool is_agreed;
    bool is_disagreed;

    int  go_mission;
    int  fail_mission;

    bool mission_failed;
    bool mission_successed;

    gamer_state()
    {
        is_participant = FALSE;

        is_leader = FALSE;
        is_leader = FALSE;

        is_nominate = FALSE;
        total_nominate = FALSE;
        need_to_fail = FALSE;

        is_agreed = FALSE;
        is_disagreed = FALSE;

        go_mission = FALSE;
        fail_mission = FALSE;

        mission_failed = FALSE;
        mission_successed = FALSE;

    }

};


class game_turn :  public QVector <gamer_state>
{
public:


    bool disagreement;
    bool agreement;
    bool success;
    bool fail;
    int fail_cnt;

    bool set_leader (int leader);
    bool nominate (QVector <bool>);
    bool approve (QVector <bool>, bool agreement);
    bool execute (QVector <bool> participants, bool succed,int fail_cnt);

    int cnt_participants (void);

    bool is_setting_leader() const;
    bool is_nomination () const;
    bool is_voting() const;
    bool is_executing() const;

    game_turn ();
    game_turn ( int gamers_count);
};






class game_state : public QAbstractTableModel
{
public:
    game_state();

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data (const QModelIndex &index, int role) const;

    QVariant headerData ( int section, Qt::Orientation orientation, int role  ) const ;

    bool set_gamers( QStringList gamers );

    bool new_leader (int number);

    bool nominate ( QVector <bool> games);

    bool approve (QVector < bool> aproved, bool agreement);

    bool execute (QVector <bool> participants, bool succed, int fail_cnt);

    void turn_back ();

    QStringList gamers;

    QVector<bool> last_nominated (void);

private:

  //  QStringList gamers;

    QVector <game_turn> turn;

    void update_all();

    int sz;

};

#endif // GAME_STATE_H
