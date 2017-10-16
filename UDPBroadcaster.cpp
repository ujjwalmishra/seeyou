#include "statediscoverer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QtNetwork>
#include <QtDebug>
#include <iostream>
#include <QBuffer>
#include "peer.h"
#include "selfstateupdater.h"

StateDiscoverer::StateDiscoverer()
{
    udpSocket = new QUdpSocket(this);
}

void StateDiscoverer::initDiscoverer()
{

}

void StateDiscoverer::broadcastDatagram()
{
    qDebug() << "Broadcasting";
//! [1]
    Peer peer;
    peer.generatePeerId();
    qDebug() << peer.peerid ;
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_1);
    out << peer;
//    char *temp = new char[20];
//    qDebug() << temp;
//    out.readRawData(temp, 20);
//    qDebug() << temp[1];
//    datagram.append(temp, 20);
//    qDebug() << datagram.at(19);
//    delete [] temp;

    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
//! [1]

}
