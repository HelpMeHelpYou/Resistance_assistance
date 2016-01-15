#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "gamers_model.h"

#include "config.h"

namespace Ui {
class Resistance;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void app_exit();
    
private slots:
    void on_actionAbout_activated();

    void on_pushButton_new_gamer_clicked();

    void on_pushButton_dlete_gamer_clicked();

    void on_actionExit_triggered();


    void on_pushButton_start_game_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:

    gamers_model * md ;
    Ui::Resistance *ui;
};

#endif // MAINWINDOW_H
