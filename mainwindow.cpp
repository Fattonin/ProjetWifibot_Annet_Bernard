#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

void MainWindow :: connexion_OK()
{
    ui->Info->setText("connexion OK");
}

void MainWindow::deconnexion()
{
    ui->Info->setText("plus de connexion");
}

void MainWindow::on_B_envoi_clicked()
{
    QTextStream texte(soc); // on associe un flux à la socket
    //texte << ui->char_9->text() <<endl;
}

void MainWindow::lecture()
{
    while (soc->canReadLine()) { // tant qu'il y a quelque chose à lire dans la socket
        ui->recu->setText(soc->readLine());  // on lit une ligne
    }
}

void MainWindow::on_dial_sliderPressed()
{

}
