#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QImage>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QWidget>
#include <QListView>
#include <QModelIndex>
#include <QFileDialog>
#include "actoradd.h"
#include "game.h"

#include "gamers_model.h"

#define STYLE "background-color: rgba(255, 255, 255, 70%);"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Resistance)
{

    ui->setupUi(this);


    md = new gamers_model ();

    connect(this,SIGNAL(app_exit()),SLOT(close()));

    //qWarning ("%s",)

    //ui->centralWidget->setStyleSheet("background-image: url(./resistance-02.jpg)");

    ui->centralWidget->setObjectName("main");

    ui->centralWidget->setStyleSheet(
                "QWidget#main { "
                "border-image: url(./resistance-02.jpg) no-repeat;"
                "}"



                );
    ui->listView ->setStyleSheet ("background-color: rgba(255, 255, 255, 70%); ");

    ui->pushButton_new_gamer->setStyleSheet ("background-color: rgba(255, 255, 255, 70%);");
    ui->pushButton_dlete_gamer->setStyleSheet ("background-color: rgba(255, 255, 255, 70%);");
    ui->pushButton_start_game->setStyleSheet("background-color: rgba(255, 255, 255, 70%);");

    ui->listView->setModel(md);
    Actor_Delegate * AD = new Actor_Delegate;
    ui->listView->setItemDelegate(AD);
    ui->listView->show();
    ui->listView->update();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_activated()
{
    QMessageBox::about(this,QObject::trUtf8("Resistance assistant"),QObject::trUtf8("Made by Ivanov V.A. 2013 Aug"));
}

void MainWindow::on_pushButton_new_gamer_clicked()
{
#if DEBUG
    qWarning("Button_new_gamer_clicked");
#endif
    this->ui->listView->model()->insertRow (0);
}



void MainWindow::on_pushButton_dlete_gamer_clicked()
{
#if DEBUG
    qWarning("on_pushButton_dlete_gamer_clicked");
#endif
    if (this->ui->listView->model()->rowCount() > 0 )
        this->ui->listView->model()->removeRow(0);
}



void MainWindow::on_actionExit_triggered()
{
    emit app_exit();
}

void MainWindow::on_pushButton_start_game_clicked()
{
    if (this->ui->listView->model()->rowCount() <  5)
    {
        QMessageBox msgBox(QMessageBox::Information,"Resistance error", "There are less than five gamers. Unable to start the game with lesser number of gamers",QMessageBox::NoButton,this);
        msgBox.setStyleSheet(STYLE);
        msgBox.exec();
    }
    else
    {
        this->hide();
        game * I_game = new game;
        I_game->gs.set_gamers(this->md->get_gamers());
        I_game->show();
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFileDialog dg;
    dg.setToolTip(tr("File to save gamers names"));
    dg.setLabelText(QFileDialog::Accept,tr("Save"));
    dg.setLabelText(QFileDialog::LookIn,tr("Save"));
    dg.setWindowTitle("Save gamers names");
    if ( !dg.exec())
    {
        return;
    }
    QFile file(dg.selectedFiles().at(0)) ;

    file.open(QIODevice::WriteOnly);
    QString str = this->md->get_gamers().join(",");
    file.write(str.toLocal8Bit().data(),str.toLocal8Bit().size()+1);
    file.close();
}

void MainWindow::on_actionLoad_triggered()
{
    QFileDialog dg;
    dg.setToolTip(tr("Open file with gamers names"));
    dg.setLabelText(QFileDialog::Accept,tr("Open"));
    dg.setLabelText(QFileDialog::LookIn,tr("Open"));
    dg.setWindowTitle("Open file with gamers names");

    if ( QDialog::Rejected  == dg.exec())
    {
        return;
    }
    QFile file(dg.selectedFiles().at(0)) ;

    if(!file.open(QIODevice::ReadOnly))
        qWarning("failed to open file %s",dg.selectedFiles().at(0).toStdString().c_str());
    else
    {
#if DEBUG
        qWarning("successed to open file %s",dg.selectedFiles().at(0).toStdString().c_str());
#endif
    }
    QString str;

    QByteArray arr = file.readAll();

    str = str.fromLocal8Bit(arr );

    md->set_gamers( str.split(","));
    file.close();

}
