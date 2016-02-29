#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void connexion_OK();
    void deconnexion();
    void on_B_conect_clicked();
    void on_B_envoi_clicked();
    void lecture();

    void on_dial_sliderPressed();

private:
    QTcpSocket *soc;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
