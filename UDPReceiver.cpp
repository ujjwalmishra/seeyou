#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>
#include "PeerInfo.h"
#include "UDPReceiver.h"
#include "CoreApp.h"
#include "task.h"

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
    app = CoreApp::getObject();
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
        PeerInfo peerInfo;        
        TaskInfo task;
        QString str;
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        udpSocket->readDatagram(datagram.data(), datagram.size());
        in >> str ;
        if (str.compare("p") == 0) {
            in >> peerInfo;
            qDebug() << peerInfo.peerid;
            app->addPeer(&peerInfo);
        }
        if (str.compare("e") == 0) {
            in >> task;
            qDebug() << task.peerid;
            app->updateEvent(&task);
        }
    }

//! [2]
}
