#ifndef ENVOI_H
#define ENVOI_H


class envoi
{

private slots:
    QByteArray data();
public:
    envoi();
    void go();
    quint16 crc16(QByteArray buffer);
};

#endif // ENVOI_H
