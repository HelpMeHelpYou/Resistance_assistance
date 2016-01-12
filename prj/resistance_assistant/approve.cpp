#include "approve.h"
#include "ui_approve.h"
#include <QSpacerItem>

approve::approve(QStringList gamers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::approve)
{
    ui->setupUi(this);

    int i;
    for ( i = 0; i < gamers.size(); i++)
    {
        QLabel * lb = new QLabel ( gamers.at(i));
        ui->gridLayout->addWidget(lb,i+1,0);

        QRadioButton * rb  = new QRadioButton;
        ui->gridLayout->addWidget(rb,i+1,1);


        QButtonGroup * bg = new QButtonGroup;
        bg->addButton(rb);

        rb  = new QRadioButton;
        ui->gridLayout->addWidget(rb,i+1,2);
        bg->addButton(rb);

        rb->setChecked(1);

        this->agreed_disagreed.push_back(rb);

        agr_disagr.push_back(0);

        QObject::connect(bg,SIGNAL(buttonClicked(int)),this,SLOT(renew_state()));

    }

    i++;

    ui->radioButton_2->setChecked(1);

    ui->gridLayout->addItem(new QSpacerItem (1,1, QSizePolicy::Minimum,QSizePolicy::Expanding),i,0);

}



approve::~approve()
{
    delete ui;
}

void approve::renew_state (void)
{
    int i,k =0;
    for (i = 0 ; i < this->agreed_disagreed.size(); i++)
    {
        agr_disagr.operator [](i) = !agreed_disagreed.at(i)->isChecked();
        if (!agreed_disagreed.at(i)->isChecked())
        {
            k++;
        }
    }

    if ( k*1.0/i > 0.5000001)
        ui->radioButton->setChecked(1);

    else
        ui->radioButton_2->setChecked(1);
}


bool approve::is_confirmed()
{
    return ui->radioButton->isChecked();
}
