#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QWebView>
#include <QUrl>


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
    void go();
    void envoi();
    void lets();
    void recoi();
    void remplir(char c1,char c2,char c3);
    quint16 crc16(QByteArray buffer);

    void connexion_OK();
    void deconnexion();
    void on_B_conect_clicked();
    void on_dial_sliderPressed();
    void on_dial_sliderReleased();
    void on_pushButton_clicked();
    void on_dial_sliderMoved(int position);
    void on_menu_tabBarClicked(int index);

private:
    QTcpSocket *soc;
    Ui::MainWindow *ui;
    QByteArray buffer;
    QByteArray data;
    QWebView *webcam;

};

#endif // MAINWINDOW_H
