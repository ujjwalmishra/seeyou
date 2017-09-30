#ifndef PEERSTATE_H
#define PEERSTATE_H
#include <QObject>
#include "states.h"

class PeerState: public QObject
{

public:
    PeerState(QObject* parent = 0);
    void setState(states state);
    void setEventCount(int count);

private:
    enum states state;
    int eventCount;
};
//! [0]

#endif // PEERSTATE_H
