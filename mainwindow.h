#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>


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
    void lecture();

    void on_comboBox_currentIndexChanged(const QString &arg1);


    void on_dial_valueChanged(int value);

    void on_dial_sliderPressed();

    void on_dial_sliderReleased();

private:
    QTcpSocket *soc;
    QByteArray envoi;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
