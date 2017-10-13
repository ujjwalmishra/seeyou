#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "statereciever.h"

Receiver::Receiver(QWidget *parent)
    : QWidget(parent)
{

//! [0]
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
//! [0]

//! [1]
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
//! [1]

}

void Receiver::processPendingDatagrams()
{
//! [2]
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
      //  statusLabel->setText(tr("Received datagram: \"%1\"")
      //                     .arg(datagram.data()));
        qDebug() << datagram.data();
    }
//! [2]
}
