

#include "peer.h"
#include <stdlib.h>


Peer::Peer()
{
    generatePeerId();

}

void Peer::generatePeerId()
{
    if(peerid.isNull())
    {
        peerid = QUuid::createUuid();
    }
}

void Peer::setPeerState(PeerState stt)
{
    state = stt;
}


