#ifndef APPROVE_H
#define APPROVE_H

#include <QDialog>
#include <QStringList>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVector>


namespace Ui {
class approve;
}

class approve : public QDialog
{
    Q_OBJECT
    
public:
    explicit approve(QStringList gamers, QWidget *parent = 0);
    ~approve();
    
    QVector <bool> agr_disagr;

    bool is_confirmed ();


private:


    Ui::approve *ui;

    QVector <QRadioButton *> agreed_disagreed;



private slots:
     void renew_state(void);

};

#endif // APPROVE_H
