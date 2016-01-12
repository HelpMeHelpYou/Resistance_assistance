#include "nominate.h"
#include "ui_nominate.h"
#include <QCheckBox>


nominate::nominate(QWidget *parent,QStringList gamers) :
    QDialog(parent),
    ui(new Ui::nominate)
{
    ui->setupUi(this);


    QString str;

    bg = new QButtonGroup(this);
    bg->setExclusive(0);

    //foreach (str,gamers)
    for (int i = 0; i < gamers.size() ; i++)
    {
        str = gamers.at(i);
                QCheckBox * but = new QCheckBox (str,this);
                ui->groupBox->layout()->addWidget(but);
                bg->addButton(but,i);


    }

    out_nominate.fill(0,gamers.size());


    QObject::connect(bg,SIGNAL(buttonPressed(int)),this,SLOT(button_pressed(int)));

}

void nominate::button_pressed(int i)
{
    bool temp =    this->bg->button(i)->isDown();
    out_nominate.operator[](i) = temp;
}



nominate::~nominate()
{
    delete ui;
}
