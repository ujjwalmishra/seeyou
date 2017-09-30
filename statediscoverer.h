#ifndef STATEDISCOVERER_H
#define STATEDISCOVERER_H

#include "peer.h"
#include <QTime>
#include <QTimer>

class StateDiscoverer {

public:
    StateDiscoverer();
    void startDiscovery(int port);
    void setDiscoveryInterval(int interval);
    void initAutoDiscoverer();


private:
    QList<Peer> peers;
    QTime time;
}

#endif // STATEDISCOVERER_H
