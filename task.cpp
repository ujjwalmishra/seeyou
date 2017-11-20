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
    qDebug() << "0.5";
    task = new TaskInfo(app->getPeerInfo().peerid);
    task->setTaskName(taskName);
    app->setLatestTask(task);
    broadcaster = new UDPBroadcaster();
    broadcaster->setMessageType("e");
    qDebug() << "1";
    app->setLatestTask(task);
    broadcaster->broadcastDatagram();
}


