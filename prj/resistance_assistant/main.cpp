#include "mainwindow.h"
#include <QApplication>
#include "game.h"
#include <approve.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
