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
    ~PeerInfo();
    PeerInfo(QUuid uid);
    void generatePeerId();
    void setPeerState(PeerState state);
    void setPeerTCPIP(QString ip);
    void setPeerName(QString name);
    PeerState getPeerState();
    friend QDataStream & operator<<(QDataStream &out, PeerInfo &s);
    friend QDataStream & operator>>(QDataStream &in, PeerInfo &s);


public:
    QUuid peerid;
    QString username;
    PeerState state;
    QString tcpip;
};

#endif // PEERS_H
