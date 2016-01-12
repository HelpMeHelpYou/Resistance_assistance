#ifndef GAMERS_MODEL_H
#define GAMERS_MODEL_H


#include <QString>
#include <QStringList>
#include <QAbstractListModel>

#include "config.h"



class gamers_model : public QAbstractListModel
{
    Q_OBJECT
public:
    gamers_model();


   //load
    //save

    virtual int rowCount ( const QModelIndex &) const;
    virtual  QVariant data ( const QModelIndex &, int  ) const ;

    virtual bool setData(const QModelIndex &, const QVariant& , int  role );

    virtual Qt::ItemFlags flags(const QModelIndex & /*index*/) const;

virtual bool insertRows ( int , int , const QModelIndex & );

virtual bool removeRows ( int , int , const QModelIndex & );

    QStringList gamers;
};

#endif // GAMERS_MODEL_H
