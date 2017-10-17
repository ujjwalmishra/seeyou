#include "UDPBroadcaster.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QtNetwork>
#include <QtDebug>
#include <iostream>
#include <QBuffer>
#include "PeerInfo.h"

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
//    Peer peer;
//    peer.generatePeerId();
//    qDebug() << peer.peerid ;
    QByteArray datagram;
//    QDataStream out(&datagram, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_1);
//    out << peer;


    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
//! [1]

}
