
#include <QDataStream>
#include "peer.h"
#include <stdlib.h>


Peer::Peer(QObject *parent):QObject(parent)
{
    generatePeerId();

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

QDataStream & Peer::operator<<(QDataStream &out, const Peer &s)
{
    //out << s.ID << s.Name;
    return out;
}

// istream, >> overloading
QDataStream & Peer::operator>>(QDataStream &in, Peer &s)
{
    s = Peer();
    //in >> s.ID >> s.Name;
    return in;
}


