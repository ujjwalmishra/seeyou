
#include <QDataStream>
#include "peer.h"
#include <stdlib.h>
#include <QDebug>

Peer::Peer()
{

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
    s = Peer();
    in >> s.peerid;
    return in;
}

