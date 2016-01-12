#include "actoradd.h"
#include "ui_actoradd.h"
#include "config.h"

ActorAdd::ActorAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActorAdd)
{
    this->setWindowFlags(Qt::Dialog);
    this->setWindowModality(Qt::ApplicationModal);
    this->setStyleSheet( "background-color: rgb(175,175,200);" );


    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    ui->pushButton_2->setEnabled(0);

}

ActorAdd::~ActorAdd()
{
    delete ui;
}

void ActorAdd::set_data_name(QString name)
{
#if    MVC_DEBUG
    qWarning("ActorAdd::set_data_name with arg %s",name.toLocal8Bit() .data());
#endif
    this->ui->lineEdit->setText(name);
}

QString ActorAdd::get_name()
{
#if MVC_DEBUG
    qWarning("ActorAdd::get_name");
#endif
    return this->ui->lineEdit->text();
}



QWidget * Actor_Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
#if MVC_DEBUG
    qWarning("Actor_Delegate::createEditor");
#endif
    ActorAdd * widget = new ActorAdd(parent);
    widget->show();
    return    widget;
}


void Actor_Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
#if MVC_DEBUG
    qWarning("Actor_Delegate::setEditorData");
#endif
    QString str =index.model()->data(index,Qt::EditRole).toString();
#if MVC_DEBUG
    qWarning (" Actor_Delegate::setEditorData:: extrcated value is %s",str.toLocal8Bit().data());
#endif
    ((ActorAdd *)editor)->set_data_name(index.model()->data(index,Qt::EditRole).toString());
}

void Actor_Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
#if MC_DEBUG
    qWarning("Actor_Delegate::setModelData");
#endif
    model->setData(index,  ((ActorAdd *)editor)->get_name(),Qt::EditRole);
}



