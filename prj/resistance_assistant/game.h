#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "game_state.h"
#include "game_table_delegate.h"


namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT
    
public:
    explicit game(QWidget *parent = 0);
    ~game();

    game_state gs;
     Ui::game *ui;

private slots:
      void on_pushButton_new_lead_clicked();

      void on_pushButton_nominate_clicked();

      void on_pushButton_approve_clicked();

      void on_pushButton_execute_clicked();

      void on_pushButton_clicked();

private:



    game_table_delegate delegate;

};

#endif // GAME_H
