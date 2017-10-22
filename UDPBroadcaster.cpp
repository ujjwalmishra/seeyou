#include "UDPBroadcaster.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QtNetwork>
#include <QtDebug>
#include <iostream>
#include <QBuffer>
#include "PeerInfo.h"
#include "CoreApp.h"

UDPBroadcaster::UDPBroadcaster()
{
    udpSocket = new QUdpSocket(this);
}

void UDPBroadcaster::initDiscoverer()
{

}

void UDPBroadcaster::broadcastDatagram()
{
    qDebug() << "Broadcasting";
//! [1]
//    Peer peer;
//    peer.generatePeerId();
//    qDebug() << peer.peerid ;
    CoreApp *app = CoreApp::getObject();
    PeerInfo peerInfo = app->getPeerInfo();
    //qDebug() << peerInfo.peerid;
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_1);
    out << peerInfo;


    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
//! [1]

}
