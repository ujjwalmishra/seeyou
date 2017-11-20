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
    task = new TaskInfo(app->getPeerInfo().peerid);
    broadcaster = new UDPBroadcaster();
    app->setLatestTask(task);
    broadcaster->broadcastDatagram();
}


