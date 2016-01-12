#ifndef GAME_TABLE_DELEGATE_H
#define GAME_TABLE_DELEGATE_H

#include <QStyledItemDelegate>

class game_table_delegate  : public QStyledItemDelegate
{
    Q_OBJECT
public:
    game_table_delegate ();


    void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const;
    //QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    //void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

private slots:
  //  void commitAndCloseEditor();
};

#endif // GAME_TABLE_DELEGATE_H
