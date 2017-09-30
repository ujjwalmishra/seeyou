#ifndef PEERSTATE_H
#define PEERSTATE_H

#include "states.h"

class PeerState : public QDialog
{
    Q_OBJECT

public:
    explicit PeerState(QWidget *parent = Q_NULLPTR);
    enum states setState(enum states state);
    int setEventCount(int count);

private:
    enum states state;
    int eventCount;
};
//! [0]

#endif // PEERSTATE_H
