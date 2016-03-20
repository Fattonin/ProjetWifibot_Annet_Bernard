#ifndef ENVOI_H
#define ENVOI_H

#include <QThread>
#include <QTcpSocket>

class envoi : public QThread
{

private:
    QTcpSocket *s;
    bool arret;

public:
    envoi(QObject *parent,QTcpSocket *soc);
    ~envoi();
    void run();
    quint16 crc16(QByteArray buffer);
};

#endif // ENVOI_H
