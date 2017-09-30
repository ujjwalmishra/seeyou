#ifndef PEERS_H
#define PEERS_H
#include "peerstate.h"
#include <QUuid>


class Peer
{

public:
    Peer();
    void generatePeerId();
    void setPeerState(PeerState state);
    PeerState getPeerState();


private:
    QUuid peerid ;
    PeerState state;
};

#endif // PEERS_H
