#ifndef SELFSTATEUPDATER_H
#define SELFSTATEUPDATER_H

#include "states.h"
#include "peer.h"

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

