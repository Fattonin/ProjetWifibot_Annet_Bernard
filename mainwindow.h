#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "envoi.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent2 = 0);
    ~MainWindow();

private slots:

    void connexion_OK();
    void deconnexion();
    void on_B_conect_clicked();
    void on_dial_sliderPressed();
    void on_dial_sliderReleased();

    void on_pushButton_clicked();

private:
    QTcpSocket *soc;
    envoi *e;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
