#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UDPBroadcaster.h"
#include "Event.h"
#include <QPainter>
#include "statussignal.h"
#include "peerbox.h"
#include "tasksenum.h"
#include "task.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centerWidget = new QWidget();
    setCentralWidget(centerWidget);
    discoverer = new UDPBroadcaster();
   // addLayouts();
//    connect(ui->addButton, &QPushButton::clicked,
//       this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLayouts()
{
    createGroupBoxes();
    mainLayout = new QGridLayout;
    centerWidget->setLayout(mainLayout);

    mainLayout->addWidget(serverGroupBox, 0, 0, 1, 2);
    mainLayout->addWidget(tasksGroupBox, 1, 0, 4, 1);
    mainLayout->addWidget(peersGroupBox, 1, 1, 4, 1);
    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
    setWindowTitle(tr("See You"));
    setWindowIcon(QIcon(":/Chain_link_icon.png"));
}

void MainWindow::createGroupBoxes()
{
    setServerGroup();
    tasksGroupBox = new QGroupBox(tr("My Tasks"));

    setPeersGroup();
}

void MainWindow::setServerGroup()
{
    serverGroupBox = new QGroupBox(tr("Server Status"));
    serverLayout = new QGridLayout();
    connectButton = new QPushButton(tr("Connect"));
    statusLabel = new QLabel(tr(statusText));
    signal = new StatusSignal;
    signal->setBrush(brush);
    statusLabel->setBuddy(signal);
    serverLayout->addWidget(statusLabel, 0, 0, 1, 1);
    serverLayout->addWidget(signal, 0, 1, 1, 4);
    serverLayout->addWidget(connectButton, 0, 2, 1, 1 );
    serverGroupBox->setLayout(serverLayout);
}

void MainWindow::initBroadCaster()
{
     discoverer->setMessageType("p");
     connect(connectButton, SIGNAL(clicked()), discoverer, SLOT(broadcastDatagram()));
}

void MainWindow::populateTasks(QUuid uid)
{
    setTasksGroup(uid);
}

void MainWindow::setTasksGroup(QUuid uid)
{
    tasksLayout = new QGridLayout();
    tasksLayout->setMargin(0);
    tasksLayout->setAlignment(Qt::AlignTop);
//    for( unsigned int a, b = 0; a < sizeof(all_tasks)/sizeof(all_tasks[0]); a = a + 3, b++ ) {
    int row = 0, col=0;
        for(TaskEnum task : all_tasks) {
            Task *newTask;
            newTask  = new Task();

            newTask->setStyleSheet("QPushButton { border-color: rgb(66, 69, 183);  border-width: 3px;border-style: solid;border-radius: 4px;"
                                     "padding: 2px 2px; margin:10px 0; float:left }");
            newTask->setTaskType(task);
            newTask->setUid(uid);
            newTask->setContentsMargins(2, 2, 2, 2);
            tasksLayout->addWidget(newTask, row, col, 1, 1 );

            col++;
            if(col == 3){
                col = 0;
                row++;
            }
        }

    tasksGroupBox->setLayout(tasksLayout);
}

void MainWindow::setPeersGroup()
{    
    peersGroupBox = new QGroupBox(tr("Online Peers"));
    peersLayout = new QGridLayout();
    peersLayout->setSpacing(0);
    peersGroupBox->setLayout(peersLayout);
}

void MainWindow::addPeerUI(PeerInfo *peer){
    PeerBox *peerBox;
    peerBox = new PeerBox();
    peerBox->init(peer->username, peer->peerid);
    qDebug() << "adding pper";
    peersLayout->addWidget(peerBox, totalPeers , 0, Qt::AlignTop);
    totalPeers++;
}

bool MainWindow::setCheckBox( bool flag)
{
    Qt::CheckState state=flag?Qt::Checked:Qt::Unchecked;
//    ui->statusConnectionBox->setCheckState(state);

    return true;
}

bool MainWindow::setProgressBar(bool flag)
{
    int value=flag?100:0;
//    ui->statusProgressBar->setValue(value);

    return true;
}


Ui::MainWindow MainWindow::getUIObject()
{
    return *ui;
}
