#ifndef EXECUTE_H
#define EXECUTE_H

#include <QDialog>
#include <QStringList>
#include <QVector>
#include <QCheckBox>
namespace Ui {
class execute;
}

class execute : public QDialog
{
    Q_OBJECT
    
public:
    explicit execute(QStringList game, QVector <bool> nominated,QWidget *parent = 0);

    QVector <bool> last_nominated ();
    bool win_lose ();
    int fail_cnt ();

    ~execute();

private slots:
    void on_line (void);
    
private:
    Ui::execute *ui;
    QVector <QCheckBox*> chck;
};

#endif // EXECUTE_H
