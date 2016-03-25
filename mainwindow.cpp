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
    /*int angle=ui->dial->value();
    int BV=ui->comboBox->currentText();*/
    data();  //inutile
    this->go();
}

void MainWindow::on_dial_sliderReleased()
{
    buffer.clear();
    buffer.append((char)0xff);
    buffer.append((char)0x07);
    buffer.append((char)0x00);
    buffer.append((char)0x00);
    buffer.append((char)0x00);
    buffer.append((char)0x00);
    buffer.append((char)0x50);

    quint16 crc=crc16(buffer);
    buffer.append((char)crc);
    buffer.append((char)(crc>>8));
}

void MainWindow::go()
{
    QTimer *t=new QTimer(this);
    t->setInterval(25);
    connect(t, SIGNAL(timeout()),this,SLOT(envoi()));
    t->start();
}

void MainWindow::data(){

        buffer.clear();
        buffer.append((char)0xff);
        buffer.append((char)0x07);
        buffer.append((char)0x78);
        buffer.append((char)0x00);
        buffer.append((char)0x78);
        buffer.append((char)0x00);
        buffer.append((char)0x50);

        quint16 crc=crc16(buffer);
        buffer.append((char)crc);
        buffer.append((char)(crc>>8));
}

void MainWindow::envoi(){
    soc->write(buffer);
    soc->flush();
}

quint16 MainWindow::crc16(QByteArray buffer) {

    quint16 crc = 0xFFFF;
    quint16 polynome = 0xA001;
    unsigned int parity = 0;
    unsigned int cptBit;
    unsigned int cptOct;

    for (cptOct = 1; cptOct < 7; cptOct++){

        crc ^= (unsigned char) buffer.at(cptOct);

        for (cptBit = 0; cptBit <= 7 ; cptBit++){

            parity = crc;
            crc >>= 1;

            if (parity % 2 == true) crc ^= polynome;
        }
    }

    return crc;
}


