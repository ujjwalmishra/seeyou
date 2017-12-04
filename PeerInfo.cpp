
#include <QDataStream>
#include "PeerInfo.h"
#include <stdlib.h>
#include <QDebug>

PeerInfo::PeerInfo()
{

}

PeerInfo::PeerInfo(QUuid uid)
{
    peerid = uid;
}


void PeerInfo::generatePeerId()
{
    if(peerid.isNull())
    {
        peerid = QUuid::createUuid();
    }
}

void PeerInfo::setPeerState(PeerState stte)
{
    state = stte;
}

void PeerInfo::setPeerTCPIP(QString ip)
{
    tcpip = ip;
}

void PeerInfo::setPeerName(QString name)
{
    username = name;
}

PeerState PeerInfo::getPeerState()
{
    return state;
}

QDataStream& operator<<(QDataStream &out, PeerInfo &s)
{
    out << s.peerid << s.state << s.tcpip << s.username;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, PeerInfo &s)
{
    s = PeerInfo();
    in >> s.peerid >> s.state >> s.tcpip >> s.username;
    return in;
}


