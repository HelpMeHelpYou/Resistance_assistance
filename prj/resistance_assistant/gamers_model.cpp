#include "gamers_model.h"
#include <QVariant>
#include <QItemDelegate>
#include <QString>

gamers_model::gamers_model()
{
}



int gamers_model::rowCount (const QModelIndex &) const
{
#if   MVC_DEBUG
    qWarning ("gamers_model::rowCount is %d",gamers.size());
#endif
    return this->gamers.size();
}

QVariant gamers_model::data(const QModelIndex &index, int role) const
{
    if ( (role != Qt::DisplayRole)  && (role != Qt::EditRole) )
    {
        return QVariant();
    }

    if (index.row() >= gamers.size())
    {
        return QVariant();
    }
#if MVC_DEBUG
    qWarning ("gamers_model::data with retrun val %s",gamers.at(index.row()).toLocal8Bit().data());
#endif
    return this->gamers.at(index.row());
}


bool gamers_model::setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole)
{
    if (role != Qt::EditRole)
    {
        return 0;
    }

    if (gamers.size()< index.row())
    {
        gamers.append(value.toString());
    }
    else
    {
        int i = index.row();
        QString str = value.toString();
        gamers[i] =  str;
    }
    return 1;

}


Qt::ItemFlags gamers_model::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}


bool gamers_model::insertRows(int row, int count, const QModelIndex & parent)
{
    this->beginInsertRows(parent,row,row+count);

#if MVC_DEBUG
    qWarning("gamers_model::insertRows %d %d",row, count);
#endif
    gamers.insert(row,QString("new gamer"));
    this->endInsertRows();
    return 1;

}

bool gamers_model::removeRows(int row, int count, const QModelIndex &parent)
{
#if    MVC_DEBUG
    qWarning("gamers_model::removeRows %d %d",row, count);
#endif
    this->beginRemoveRows(parent,row,row+count);

    gamers.removeAt(row);
    this->endRemoveRows();
    return 1;


}


const QStringList gamers_model::get_gamers()
{
    return gamers ;

}

void gamers_model::set_gamers(QStringList gamers_l)
{
    beginInsertRows(this->index(0,0),0,gamers_l.size());
    this->gamers = gamers_l;
    endInsertRows();
    emit this->dataChanged(this->index(0,0),this->index(0,this->gamers.size()));
}
