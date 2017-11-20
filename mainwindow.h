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
#include "peerbox.h"

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
    PeerBox* addPeerUI(PeerInfo *peer);
    void addLayouts();
    void populateTasks(QUuid uid);

private:
    void createGroupBoxes();
    void setServerGroup();
    void setTasksGroup(QUuid uid);
    void setPeersGroup();
    StatusSignal *signal;
    QLabel *statusLabel;
    QPushButton * connectButton;
    QWidget *centerWidget;
    QGridLayout *mainLayout;
    QGridLayout *serverLayout;
    QGridLayout *tasksLayout;
    QGridLayout *peersLayout;
    qint16 totalPeers = 0;
    QGroupBox *serverGroupBox;
    QGroupBox *tasksGroupBox;
    QGroupBox *peersGroupBox;
    Ui::MainWindow *ui;
    UDPBroadcaster *discoverer;
};

#endif // MAINWINDOW_H
