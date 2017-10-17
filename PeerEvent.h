#ifndef PEEREVENT_H
#define PEEREVENT_H

#include <QObject>
#include <QTime>
#include <QUuid>
#include <QString>

class PeerEvent : public QObject
{
public:
    PeerEvent(QObject *parent = 0);
    ~PeerEvent();
    QUuid getUid();
    void setUid(QUuid uid);
    QString getTitle();
    void setTitle(QString title);
    QString getDesc();
    void setDesc(QString desc);
    QTime startTime;
    QTime endTime;

private:
    QString title;
    QString desc;
};

#endif // PEEREVENT_H
