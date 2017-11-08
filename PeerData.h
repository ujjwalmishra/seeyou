#ifndef PEERSTATE_H
#define PEERSTATE_H


#include <QUuid>
#include <QObject>
#include <QVector>
#include "PeerState.h"
#include "PeerEvent.h"


class PeerData: public QObject
{

    Q_OBJECT

public:
    PeerData(QObject *parent = 0);
    ~PeerData();
    void setEventCount(int count);
    void setUid();
    QUuid getUid();
    void addEvent(PeerEvent evnt);


private:
    QUuid uid;
    PeerState state;
    int eventCount;
    QVector<PeerEvent> evnts;
};
#endif // PEERSTATE_H
