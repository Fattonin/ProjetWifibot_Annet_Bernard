#include "mainwindow.h"
#include "fenetrecam2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    fenetreCam2 cam;
    cam.show();
    return a.exec();
}
