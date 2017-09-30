

#include "peerstate.h"
#include <stdlib.h>


PeerState::PeerState()
{
    setState(initializing);
    setEventCount(0);
}

void PeerState::setEventCount(int count)
{
    eventCount = count;
}

void PeerState::setState(enum states stte)
{
    state = stte;
}
