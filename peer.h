#ifndef PEERS_H
#define PEERS_H
#include "peerstate.h"
#include <QUuid>
#include <QObject>
#include <QDataStream>

class Peer
{

public:
    Peer();
    Peer(QUuid uid);
    ~Peer();
    void generatePeerId();
    void setPeerState(PeerState& state);
    PeerState getPeerState();
    friend QDataStream & operator<<(QDataStream &out, const Peer &s);
    friend QDataStream & operator>>(QDataStream &in, Peer &s);


public:
    QUuid peerid ;
    PeerState* state;
};

#endif // PEERS_H
