

#include "peer.h"
#include <stdlib.h>


Peer::Peer(QObject *parent):QObject(parent)
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

void Peer::setPeerState(PeerState& stte)
{
    state = &stte;
}


