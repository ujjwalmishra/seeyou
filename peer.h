#ifndef PEERS_H
#define PEERS_H
#include "peerstate.h"
#include <QUuid>
#include <QObject>
#include <QDataStream>

class Peer: public QObject
{

public:
    Peer(QObject* parent = 0);
    void generatePeerId();
    void setPeerState(PeerState& state);
    PeerState getPeerState();
    QDataStream & operator<<(QDataStream &out, const Peer &s);
    QDataStream & operator>>(QDataStream &in, Peer &s);


public:
    QUuid peerid ;
    PeerState* state;
};

#endif // PEERS_H
