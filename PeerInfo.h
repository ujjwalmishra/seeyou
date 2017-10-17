#ifndef PEERS_H
#define PEERS_H
#include "PeerData.h"
#include <QUuid>
#include <QObject>
#include <QDataStream>

class PeerInfo
{

public:
    PeerInfo();
    PeerInfo(QUuid uid);
    ~PeerInfo();
    void generatePeerId();
   // void setPeerState(PeerState& state);
   // PeerState getPeerState();
    friend QDataStream & operator<<(QDataStream &out, const PeerInfo &s);
    friend QDataStream & operator>>(QDataStream &in, PeerInfo &s);


public:
    QUuid peerid;
    PeerState state;
};

#endif // PEERS_H
