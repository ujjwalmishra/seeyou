#ifndef PEERSTATE_H
#define PEERSTATE_H
#include <QObject>
#include "states.h"

class PeerState: public QObject
{

public:
    PeerState(QObject* parent = 0);
    ~PeerState();
    void setState(states state);
    void setEventCount(int count);
    void initState();


private:
    enum states state;
    int eventCount;

};
//! [0]
static PeerState* getSInstance();
static PeerState *peerstate;
#endif // PEERSTATE_H
