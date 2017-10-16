
#include <QDataStream>
#include "peer.h"
#include <stdlib.h>


Peer::Peer()
{
    generatePeerId();

}

Peer::Peer(QUuid uid)
{
    peerid = uid;
}

Peer::~Peer()
{

}

void Peer::generatePeerId()
{
    if(peerid.isNull())
    {
        peerid = QUuid::createUuid();
    }
}

void Peer::setPeerState(PeerState& stte)
{
    state = &stte;
}

QDataStream& operator<<(QDataStream &out, const Peer &s)
{
    out << s.peerid;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, Peer &s)
{
    //s = Peer();
    QUuid uid;
    in >> uid;
    s= Peer(uid);
    //in >> s.ID >> s.Name;
    return in;
}


