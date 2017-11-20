
#include <QDataStream>
#include "taskinfo.h"
#include <stdlib.h>
#include <QDebug>

TaskInfo::TaskInfo()
{

}

TaskInfo::TaskInfo(QUuid uid)
{
    peerid = uid;
}

TaskInfo::~TaskInfo()
{

}

void TaskInfo::setTaskName(QString name)
{
    taskName = name;
}

void TaskInfo::setPeerId(QUuid pid)
{
    peerid = pid;
}


QDataStream& operator<<(QDataStream &out, TaskInfo &s)
{
    out << s.peerid << s.taskName;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, TaskInfo &s)
{
    s = TaskInfo();
    in >> s.peerid >> s.taskName;
    return in;
}


