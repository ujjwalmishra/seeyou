#include "task.h"
#include "CoreApp.h"
#include "UDPBroadcaster.h"
#include <QUuid>
#include <QDebug>

Task::Task(QWidget *parent)
    : QWidget(parent)
{

}

void Task::setTaskType(TaskEnum task)
{
    taskName = task.getString();
    init();
}

void Task::setUid(QUuid uid)
{
    uid = uid;
}

TaskEnum* Task::getTaskType()
{
    return new TaskEnum(taskName);
}

void Task::init()
{
    layout = new QHBoxLayout();
    layout->setMargin(0);
    layout->setAlignment(Qt::AlignTop);
    addButton = new QPushButton(taskName);
    addButton->setFixedWidth(100);
    layout->addWidget(addButton);
    connect(addButton, SIGNAL(clicked()), this, SLOT(addTask()));
    this->setLayout(layout);
}

void Task::addTask()
{
    CoreApp *app = CoreApp::getObject();
    QUuid uid = app->getPeerInfo().peerid;
    task = new TaskInfo(uid);
    task->setTaskName(taskName);
    app->setLatestTask(task);
    QVector<TaskInfo> selfTasks = app->peerTasks.value(uid.toString());
    selfTasks.append(*task);
    app->peerTasks.insert(uid.toString(), selfTasks);
    QList<QString> ids = app->peerTasks.keys();
//    for(auto key: ids) {
//        qDebug() << key;
//         QVector<TaskInfo> selfTasks = app->peerTasks.value(key);
//        qDebug() << "size";
//        qDebug() << selfTasks.last().taskName;
//    }
    broadcaster = new UDPBroadcaster();
    broadcaster->setMessageType("e");
    app->setLatestTask(task);
    broadcaster->broadcastDatagram();
}


