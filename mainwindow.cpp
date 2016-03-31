#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent2) : QMainWindow(parent2), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webcam = new QWebView(this);
    webcam->setGeometry(235,50,340,250);
    webcam->load(QUrl("http://192.168.1.106:8080/javascript_simple.html"));

    soc = new QTcpSocket(this);
    //creation de la socket
    connect(soc, SIGNAL(connected()), this, SLOT(connexion_OK()));
    // signal émis lors de la connexion au serveur
    connect(soc, SIGNAL(disconnected()),this, SLOT(deconnexion()));
    // signal émis lors de la deconnexion au serveur
}

void MainWindow::on_menu_tabBarClicked(int index)
{
    if(index==0){
        webcam->setVisible(true);
    }
    else webcam->setVisible(false);
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
    this->go();
    this->lets();

}

void MainWindow::deconnexion()
{
    ui->Info->setText("plus de connexion !");
}


void MainWindow::on_dial_sliderReleased()
{
    remplir(0,0,0);
}

void MainWindow::remplir(char c1,char c2,char c3){

    buffer.clear();
    buffer.append((char)0xff);
    buffer.append((char)0x07);
    buffer.append(c1);
    buffer.append((char)0x00);
    buffer.append(c2);
    buffer.append((char)0x00);
    buffer.append(c3);

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

void MainWindow::lets()
{
    QTimer *t=new QTimer(this);
    t->setInterval(25);
    connect(t, SIGNAL(timeout()),this,SLOT(recoi()));
    t->start();
}


void MainWindow::envoi(){

    soc->write(buffer);
    soc->flush();
}

void MainWindow::recoi(){

    soc->waitForReadyRead(20);
    data.clear();
    data=soc->read(21); //rpz
    QString deCheval;
    deCheval=data.toHex();
    ui->label->setText(deCheval);

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

void MainWindow::on_dial_sliderMoved(int position)
{
    QString BV=ui->comboBox->currentText();
    int v=ui->verticalSlider->value();

    if(BV=="P"){
        remplir(0,0,0);
    }
    else  if(position<20){
            if(BV=="D"){
                remplir(v,v,16);
            }
            if(BV=="R"){
                remplir(v,v,64);
            }
            }
           else if(position>50 && position<80){  //droite
                    if(BV=="D"){
                        remplir(v,v-(v*(position-50)/30),80);
                    }
                    if(BV=="R"){
                        remplir(v,v-(v*(position-50)/30),0);
                    }
                 }
            else if(position>20 && position<50){  //gauche
                if(BV=="D"){
                 remplir(v-(-v*(position-50)/30),v,80);
                 }
                 if(BV=="R"){
                 remplir(v-(-v*(position-50)/30),v,0);
                }
            }
                 else if(position>80){
                        if(BV=="D"){
                            remplir(v,v,64);
                        }
                        if(BV=="R"){
                            remplir(v,v,16);
                        }
                 }
}


