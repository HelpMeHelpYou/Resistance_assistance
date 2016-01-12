#include "execute.h"
#include "ui_execute.h"
#include <QLabel>
#include <QCheckBox>

execute::execute(QStringList gamers, QVector<bool> nominated, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::execute)
{
    ui->setupUi(this);

    for ( int i = 0; i < gamers.size(); i++)
    {
        QLabel * lb = new QLabel (gamers.at(i));
        QCheckBox * chk = new QCheckBox;

        chk->setChecked(nominated.at(i));

        ui->gridLayout_3->addWidget(lb,i,0);
        ui->gridLayout_3->addWidget(chk,i,1);

        this->chck.append(chk);

    }

    ui->spinBox->setValue(gamers.size());
    ui->buttonBox->buttons().takeFirst()->setDisabled(1);
    QObject::connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(on_line()));
     QObject::connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(on_line()));
}

execute::~execute()
{
    delete ui;
}

void execute::on_line(void)
{
    ui->buttonBox->buttons().takeFirst()->setDisabled(0);

}

QVector <bool> execute::last_nominated()
{
    QVector <bool> rc;

    for (int i = 0; i < chck.size(); i++)
    {
        rc.push_back(this->chck.at(i)->isChecked());
    }

    return rc;

}

bool execute::win_lose()
{
    return this->ui->radioButton->isChecked();

}

int execute::fail_cnt()

{

        return this->ui->spinBox_2->value();


}
