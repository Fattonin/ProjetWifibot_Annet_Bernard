#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    envoi.resize(9);
    envoi[0] = 0xFF;
    envoi[1] = 0x00;
    envoi[2] = 0x00;
    envoi[3] = 0x00;
    envoi[4] = 0x00;
    envoi[5] = 0x00;
    envoi[6] = 0x00;
    envoi[7] = 0x00;
    envoi[8] = 0x00;
    //paquet= 255,7,120,0 ,120 ,0 , 80;

    soc = new QTcpSocket(this);
    //creation de la socket
    connect(soc, SIGNAL(connected()), this, SLOT(connexion_OK()));
    // signal émis lors de la connexion au serveur
    connect(soc, SIGNAL(disconnected()),this, SLOT(deconnexion()));
    // signal émis lors de la deconnexion au serveur
    connect(soc, SIGNAL(readyRead()),this, SLOT(lecture()));
    // signal émis lorsque des données sont prêtes à être lues



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

void MainWindow :: connexion_OK()
{
    ui->Info->setText("connexion OK");

    soc->write(envoi);
}

void MainWindow::deconnexion()
{
    ui->Info->setText("plus de connexion !");
}


void MainWindow::lecture()
{
   QString tata;// = (QString)(soc->readAll());
  // ui->recu->setText("recu : "+tata);  // on lit une ligne

   QByteArray textRecu = soc->readAll();
   ui->recu->setText("recu : "+textRecu);

    /* QDataStream in(soc);
     QString message;
     QByteArray robot;
     in >> robot;
     message=(QString)robot;
     ui->recu->setText(message);*/
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    if(arg1=="P"){
    //paquet= 255,7,120,0 ,120 ,0 , 80;
    soc->write(paquet); // On envoie le paquet
    }
}

void MainWindow::on_dial_sliderPressed()
{
    on_dial_valueChanged(ui->dial->value());
}


void MainWindow::on_dial_valueChanged(int value)
{
    envoi[0] = 0xFF;
    envoi[1] = 0x01;
    envoi[2] = 0x00;
    envoi[3] = 0x00;
    envoi[4] = 0x00;
    envoi[5] = 0x00;
    envoi[6] = 0x00;
    envoi[7] = 0x00;
    envoi[8] = 0x00;
    soc->write(envoi);
}



void MainWindow::on_dial_sliderReleased()
{
    envoi[0] = 0xFF;
    envoi[1] = 0x00;
    envoi[2] = 0x00;
    envoi[3] = 0x00;
    envoi[4] = 0x00;
    envoi[5] = 0x00;
    envoi[6] = 0x00;
    envoi[7] = 0x00;
    envoi[8] = 0x00;
    soc->write(envoi);
}
