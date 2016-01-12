#ifndef ACTORADD_H
#define ACTORADD_H

#include <QWidget>
#include <QStyledItemDelegate>

namespace Ui {
class ActorAdd;
}

class ActorAdd : public QWidget
{
    Q_OBJECT
    
public:
    explicit ActorAdd(QWidget *parent = 0);
    ~ActorAdd();
    QString get_name();

public slots:
    void set_data_name (QString);
    
private:
    Ui::ActorAdd *ui;
};



class Actor_Delegate : public QStyledItemDelegate
{
    virtual QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;

  //  virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;


};




#endif // ACTORADD_H
