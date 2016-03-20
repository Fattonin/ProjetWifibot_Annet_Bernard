#ifndef FENETRECAM2_H
#define FENETRECAM2_H

#include <QMainWindow>
#include <QWebView>
#include <QUrl>

namespace Ui {
class fenetreCam2;
}

class fenetreCam2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetreCam2(QWidget *parent3 = 0);
    ~fenetreCam2();

private:
    Ui::fenetreCam2 *ui;
    QWebView *webcam;
};

#endif // FENETRECAM2_H
