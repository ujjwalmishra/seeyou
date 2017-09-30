#ifndef PEERS_H
#define PEERS_H
#include "peerstate.h"
#include <QUuid>
#include <QObject>

class Peer: public QObject
{

public:
    Peer(QObject* parent = 0);
    void generatePeerId();
    void setPeerState(PeerState& state);
    PeerState getPeerState();


private:
    QUuid peerid ;
    PeerState* state;
};

#endif // PEERS_H
