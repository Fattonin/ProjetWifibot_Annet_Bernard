#include "fenetrecam2.h"
#include "ui_fenetrecam2.h"

fenetreCam2::fenetreCam2(QWidget *parent3) :QMainWindow(parent3),ui(new Ui::fenetreCam2)
{
    ui->setupUi(this);
    webcam = new QWebView(this);
    webcam->setGeometry(5,5,500,350);
    webcam->load(QUrl("http://192.168.1.106:8080/javascript_simple.html"));
}

fenetreCam2::~fenetreCam2()
{
    delete ui;
}
