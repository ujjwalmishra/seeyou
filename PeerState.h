#ifndef STATES_H
#define STATES_H

#include <QDataStream>

enum class PeerState
{
    INITIALIZED, SHUT, MUTATED
};

QDataStream & operator<<(QDataStream &out, PeerState &s);
QDataStream & operator>>(QDataStream &in, PeerState &s);

#endif // STATES_H
//istream& operator >> (istream& in, RACE& race)
//{
//    unsigned u = 0;
//    in >> u;
//    //TODO: check that u is a valid RACE value
//    race = static_cast<RACE>(u);
//    return in;
//}

//ostream& operator << (ostream& out, RACE race)
//{
//    //TODO: check that race is a valid RACE value
//    unsigned u = race;
//    out << u;
//    return out;
//}
