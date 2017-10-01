#include "statediscoverer.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QtNetwork>
#include <QtDebug>
#include <iostream>

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
    std::cout << "ding" << endl;
//! [1]
    QByteArray datagram = "Broadcast message " + QByteArray::number(1);
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 45454);
//! [1]

}
