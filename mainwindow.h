#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QGroupBox>
#include "UDPBroadcaster.h"
#include "PeerInfo.h"
#include "PeerData.h"
#include <QVector>
#include <QWidget>
#include <QPushButton>
#include <QBrush>
#include <QLabel>
#include "Event.h"
#include "statussignal.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool setCheckBox( bool flag);
    bool setProgressBar(bool flag);
    Ui::MainWindow getUIObject();
    void initBroadCaster();
    const char *statusText;
    QBrush brush;
    void addLayouts();

public slots:
    void addTask();

private:
    void createGroupBoxes();
    void setServerGroup();
    void setTasksGroup();
    void setPeersGroup();
    StatusSignal *signal;
    QLabel *statusLabel;
    QPushButton * connectButton;
    QWidget *centerWidget;
    QGridLayout *mainLayout;
    QGridLayout *serverLayout;
    QGridLayout *tasksLayout;
    QGridLayout *peersLayout;

    QGroupBox *serverGroupBox;
    QGroupBox *tasksGroupBox;
    QGroupBox *peersGroupBox;
    Ui::MainWindow *ui;
    UDPBroadcaster *discoverer;
};

#endif // MAINWINDOW_H
