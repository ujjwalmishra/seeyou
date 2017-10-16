

#include "peerstate.h"
#include <stdlib.h>


PeerState::PeerState(QObject *parent):QObject(parent)
{
    setState(initializing);
    setEventCount(0);
}

PeerState::~PeerState()
{
    delete peerstate;
}

void PeerState::setEventCount(int count)
{
    eventCount = count;
}

void PeerState::initState()
{
    if(peerstate != nullptr)
    {
       peerstate = new PeerState();
    }
}

PeerState* PeerState::getSInstance()
{
    return peerstate;
}

void PeerState::setState(enum states stte)
{
    state = stte;
}
