#include <QDebug>
#include "PeerState.h"
#include <QDataStream>

QDataStream& operator<<(QDataStream &out, PeerState &s)
{
    unsigned u = static_cast<unsigned>(s);
    out << u;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, PeerState &s)
{
    unsigned u = 0;
    in >> u;
    s = static_cast<PeerState>(u);
    return in;
}
