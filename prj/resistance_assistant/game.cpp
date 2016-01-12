#include "game.h"
#include "ui_game.h"
#include "choose_leader.h"
#include "nominate.h"
#include "approve.h"
#include "execute.h"
#include <QHeaderView>
#include "resistheaderview.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    this->setObjectName("game");

    this->setStyleSheet(
                                        "QWidget#game { "
                                     "border-image: url(./resistance-02.jpg) no-repeat; background-image:url(./resistance-02.jpg);"
                                     "}"
                                     );

   this->setStyleSheet ("background-color: rgba(210,200, 220, 70%); ");



    this->ui->pushButton_approve->setStyleSheet("background-color: rgba(255, 255, 255, 70%); ");
    this->ui->pushButton_execute->setStyleSheet("background-color: rgba(255, 255, 255, 70%); ");
    this->ui->pushButton_new_lead->setStyleSheet("background-color: rgba(255, 255, 255, 70%); ");
    this->ui->pushButton_nominate->setStyleSheet("background-color: rgba(255, 255, 255, 70%); ");


    this->ui->tableView->setModel(&gs);
    this->ui->tableView->setItemDelegate(&this->delegate);

  //  QHeaderView * vhview = new QHeaderView(Qt::Horizontal);

    QHeaderView * vhview = new ResistHeaderView;
    this->ui->tableView->setHorizontalHeader(vhview);



    //QHeaderView * hdview =  new QHeaderView  (this->ui->tableView->horizontalHeader());


    QStringList ls;
    ls.append("Alice");
    ls.append("Bob");


  //  gs.set_gamers(ls);


    this->update();
    this->show();

}

game::~game()
{
    delete ui;
}

void game::on_pushButton_new_lead_clicked()
{

    choose_leader  lead (this,gs.gamers,1);

    if ( QDialog::Rejected ==lead.exec())
    {
        return;
    }

    gs.new_leader(lead.leader_num_out);

     ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void game::on_pushButton_nominate_clicked()
{

    nominate  nom (this,gs.gamers);

    if ( QDialog::Rejected ==nom.exec())
    {
        return;
    }


    gs.nominate(nom.out_nominate);
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

}

void game::on_pushButton_approve_clicked()
{
    approve appr(gs.gamers,this);

    if ( QDialog::Rejected ==appr.exec())
    {
        return;
    }
    gs.approve(appr.agr_disagr,appr.is_confirmed());
     ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void game::on_pushButton_execute_clicked()
{
    execute exec(gs.gamers,gs.last_nominated(),this);

    if ( QDialog::Rejected ==exec.exec())
    {
        return;
    }

    gs.execute(exec.last_nominated(),exec.win_lose(),exec.fail_cnt());

     ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void game::on_pushButton_clicked()
{
    gs.turn_back();
}
