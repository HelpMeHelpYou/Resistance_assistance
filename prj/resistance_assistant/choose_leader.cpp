#include "choose_leader.h"
#include "ui_choose_leader.h"
#include <QRadioButton>
#include <QButtonGroup>

choose_leader::choose_leader(QWidget *parent, QStringList gamers, int num) :
    QDialog(parent),
    ui(new Ui::choose_leader)
{
    ui->setupUi(this);

    QString str;

    bg = new QButtonGroup(this);

    for (int i = 0; i < gamers.size() ; i++)
    {
        str = gamers.at(i);
                QRadioButton * but = new QRadioButton (str,this);
                ui->groupBox->layout()->addWidget(but);
                bg->addButton(but,i);

                if (i== num)
                {
                    but->setChecked(1);

                }
    }

    leader_num_out = num;

    bg->button(num)->setDown(1);

    QObject::connect(bg,SIGNAL(buttonPressed(int)),this,SLOT(pressed_button_new_leader(int)));

}

choose_leader::~choose_leader()
{
    delete ui;
}


void choose_leader::pressed_button_new_leader(int num)
{
    this->leader_num_out = num;

}
