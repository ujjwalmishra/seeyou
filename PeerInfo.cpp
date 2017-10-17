
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

PeerInfo::~PeerInfo()
{

}

void PeerInfo::generatePeerId()
{
    if(peerid.isNull())
    {
        peerid = QUuid::createUuid();
    }
}

//void PeerInfo::setPeerState(PeerState& stte)
//{
//    //state = &stte;
//}

QDataStream& operator<<(QDataStream &out, const PeerInfo &s)
{
    out << s.peerid;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, PeerInfo &s)
{
    s = PeerInfo();
    in >> s.peerid;
    return in;
}

