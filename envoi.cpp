#include "envoi.h"
#include <QTimer>


envoi::envoi()
{}

void envoi::go()
{
    QTimer *t=new QTimer(this);
    t->setInterval();
    connect(t, SIGNAL(timeout()),this,SLOT(data()));
    t->start();
}

QByteArray envoi::data(){

    QByteArray buffer;

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

     return buffer;
}

quint16 envoi::crc16(QByteArray buffer) {

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
