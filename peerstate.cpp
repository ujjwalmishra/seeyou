

#include "peerstate.h"
#include <stdlib.h>


PeerState::PeerState(QObject *parent)
{
    eventCount(0);
    state(initializing);
}

PeerState::setEventCount(int count)
{
    eventCount = count;
}

PeerState::setState(enum states stte)
{
    state = stte;
}
