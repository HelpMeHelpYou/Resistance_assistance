#ifndef NOMINATE_H
#define NOMINATE_H

#include <QDialog>
#include <QVector>
#include <QButtonGroup>

namespace Ui {
class nominate;
}

class nominate : public QDialog
{
    Q_OBJECT
    
public:
    explicit nominate(QWidget *parent, QStringList gamers);
    QVector <bool> out_nominate;
    ~nominate();
    
private:
    Ui::nominate *ui;

     QButtonGroup * bg;
private slots:
     void button_pressed (int);
};

#endif // NOMINATE_H
