#ifndef PEERSTATE_H
#define PEERSTATE_H

#include "states.h"

class PeerState
{

public:
    PeerState();
    void setState(states state);
    void setEventCount(int count);

private:
    enum states state;
    int eventCount;
};
//! [0]

#endif // PEERSTATE_H
