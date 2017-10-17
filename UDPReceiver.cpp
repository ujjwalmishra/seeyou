#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>
#include "PeerInfo.h"
#include "UDPReceiver.h"

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

void Receiver::init()
{
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

void Receiver::processPendingDatagrams()
{
//! [2]


    while (udpSocket->hasPendingDatagrams()) {
//        Peer peer;
//        QByteArray datagram;
//        datagram.resize(udpSocket->pendingDatagramSize());
//        QDataStream in(&datagram, QIODevice::ReadOnly);
//        udpSocket->readDatagram(datagram.data(), datagram.size());
//        in >> peer;
//      //  statusLabel->setText(tr("Received datagram: \"%1\"")
//      //                     .arg(datagram.data()));
    }

//! [2]
}
