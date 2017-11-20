#ifndef TASKINFO_H
#define TASKINFO_H
#include "PeerData.h"
#include <QUuid>
#include <QObject>
#include <QDataStream>

class TaskInfo
{

public:
    TaskInfo();
    TaskInfo(QUuid uid);
    ~TaskInfo();
    void setPeerId(QUuid uid);
    void setTaskName(QString name);
    friend QDataStream & operator<<(QDataStream &out, TaskInfo &s);
    friend QDataStream & operator>>(QDataStream &in, TaskInfo &s);


public:
    QUuid peerid;
    QString taskName;
};

#endif // TASKINFO_H
