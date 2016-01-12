#ifndef CHOOSE_LEADER_H
#define CHOOSE_LEADER_H

#include <QDialog>
#include <QStringList>
#include <QButtonGroup>

namespace Ui {
class choose_leader;
}

class choose_leader : public QDialog
{
    Q_OBJECT
    
public:
    explicit choose_leader(QWidget *parent, QStringList gamers, int nun);
    ~choose_leader();
     int leader_num_out;
    
private:
    Ui::choose_leader *ui;

    QButtonGroup * bg;

private slots:
    void pressed_button_new_leader (int num);
};

#endif // CHOOSE_LEADER_H

