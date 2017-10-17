#ifndef STATEDISCOVERER_H
#define STATEDISCOVERER_H

#include "PeerInfo.h"
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
class QPushButton;
class QTimer;
class QUdpSocket;
QT_END_NAMESPACE

class StateDiscoverer: public QObject
{
Q_OBJECT
public:
    StateDiscoverer();
    void initDiscoverer();

private slots:
//    void startDiscovery(int port);
//    void setDiscoveryInterval(int interval);
//    void initAutoDiscoverer();
    void broadcastDatagram();


private:
    QPushButton *startButton;
    QUdpSocket *udpSocket;
};

#endif // STATEDISCOVERER_H
