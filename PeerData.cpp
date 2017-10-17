

#include "PeerData.h"
#include <stdlib.h>


PeerData::PeerData(QObject *parent):QObject(parent)
{
    //setState(initializing);
    setEventCount(0);
}

PeerData::~PeerData()
{
    //delete peerstate;
}

void PeerData::setEventCount(int count)
{
    eventCount = count;
}

//void PeerData::initState()
//{
//    if(peerstate != nullptr)
//    {
//       //peerstate = new PeerState();
//    }
//}

//PeerData* PeerData::getSInstance()
//{
//    return peerstate;
//}

//void PeerState::setState(enum states stte)
//{
//    state = stte;
//}
