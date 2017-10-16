#ifndef SELFSTATEUPDATER_H
#define SELFSTATEUPDATER_H

#include "PeerStates.h"
#include "PeerInfo.h"

class StateUpdater
{

public:
    StateUpdater();
    ~StateUpdater();
    void initSelfState();
    void setState(enum states state);
    Peer& getState();

private:
    Peer *peer;
    PeerState *peerState;
};


#endif // PEERSTATE_H

