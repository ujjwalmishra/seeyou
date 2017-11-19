#include "task.h"
#include "CoreApp.h"
#include "UDPBroadcaster.h"
#include <QUuid>

Task::Task(QWidget *parent)
    : QWidget(parent)
{

}

void Task::setTaskType(TaskEnum task)
{
    taskName = task.getString();
    app = CoreApp::getObject();
    init();
}

void Task::setUid(QUuid uid)
{
    uid = uid;
}

TaskEnum Task::getTaskType()
{

}

void Task::init()
{
    addButton = new QPushButton(tr("taskName"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addTask()));
}

void Task::addTask()
{
    broadcaster = new UDPBroadcaster();
    //app->setLatestTask(*this);
    broadcaster->broadcastDatagram();
}

QDataStream& operator<<(QDataStream &out, Task &s)
{
    out << s.uid << s.taskName;
    return out;
}

// istream, >> overloading
QDataStream& operator>>(QDataStream &in, Task &s)
{
    s = new Task();
    in >> s.uid >> s.taskName;
    return in;
}
