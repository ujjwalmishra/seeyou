#ifndef TASK_H
#define TASK_H
#include <QWidget>
#include <QUuid>
#include <QPushButton>
#include "CoreApp.h"
#include "UDPBroadcaster.h"
#include "tasksenum.h"

class Task : public QWidget
{

    Q_OBJECT

    public:
        explicit Task(QWidget *parent = 0);
        void setTaskType(TaskEnum task);
        void setUid(QUuid uid);
        TaskEnum getTaskType();

    public slots:
        void addTask();

    public:
        QUuid uid;
        QString taskName;

    private:
        QPushButton *addButton;
        void init();
        CoreApp *app;
        UDPBroadcaster *broadcaster;

};
#endif // TASK_H
