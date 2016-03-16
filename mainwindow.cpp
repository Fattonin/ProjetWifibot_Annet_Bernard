#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent2) : QMainWindow(parent2), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soc = new QTcpSocket(this);
    //creation de la socket
    connect(soc, SIGNAL(connected()), this, SLOT(connexion_OK()));
    // signal émis lors de la connexion au serveur
    connect(soc, SIGNAL(disconnected()),this, SLOT(deconnexion()));
    // signal émis lors de la deconnexion au serveur
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_conect_clicked()
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    ui->Info->setText("Tentative de connexion en cours...");
    soc->connectToHost(ui->IP_Text->text(), ui->Port_Num->value()); // On se connecte au serveur demandé

    if(!soc->waitForConnected(2000))
    {
        ui->Info->setText("Erreur : "+soc->errorString());
    }
}

void MainWindow::on_pushButton_clicked()
{
    soc->disconnectFromHost();
}

void MainWindow :: connexion_OK()
{
    ui->Info->setText("connexion OK");

}

void MainWindow::deconnexion()
{
    ui->Info->setText("plus de connexion !");
}

void MainWindow::on_dial_sliderPressed()
{
    e=new envoi(this,soc);  //pblm
    e->start();
}

void MainWindow::on_dial_sliderReleased()
{
    delete e;
}



