
#include "selfstateupdater.h"
#include <stdlib.h>


StateUpdater::StateUpdater()
{

}

StateUpdater::~StateUpdater()
{
    delete peer;
    delete peerState;
}

void StateUpdater::initSelfState()
{
    peer = new Peer();
    peerState = PeerState::getSInstance();
    peer->setPeerState(*peerState);
}

void StateUpdater::setState(enum states state)
{
    peerState->setState(state);
}


