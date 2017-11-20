#ifndef TASK_H
#define TASK_H
#include <QWidget>
#include <QUuid>
#include <QPushButton>
#include "CoreApp.h"
#include "UDPBroadcaster.h"
#include "tasksenum.h"
#include "taskinfo.h"

class Task : public QWidget
{

    Q_OBJECT

    public:
        explicit Task(QWidget *parent = 0);
        void setTaskType(TaskEnum task);
        void setUid(QUuid uid);
        TaskEnum* getTaskType();

    public slots:
        void addTask();

    public:
        QUuid uid;
        QString taskName;

    private:
        QPushButton *addButton;
        QHBoxLayout *layout;
        void init();
        CoreApp *app;
        TaskInfo *task;
        UDPBroadcaster *broadcaster;

};
#endif // TASK_H
