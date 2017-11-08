#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UDPBroadcaster.h"
#include "Event.h"
#include <QPainter>
#include "statussignal.h"
#include "peerbox.h"

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
        connect(connectButton, SIGNAL(clicked()),
                discoverer, SLOT(broadcastDatagram()));
}

void MainWindow::setTasksGroup()
{

}

void MainWindow::setPeersGroup()
{    
    peersGroupBox = new QGroupBox(tr("Online Peers"));
    peersLayout = new QGridLayout();
    peersLayout->setSpacing(0);
    peersLayout->setContentsMargins(0,0,0,0);
    peersGroupBox->setLayout(peersLayout);
}

void MainWindow::addPeerUI(PeerInfo *peer){
    PeerBox *peerBox;
    peerBox = new PeerBox();
    peerBox->init(peer->username);
    qDebug() << "adding pper";
    qDebug() << peerBox->size();
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

void MainWindow::addTask()
{
    qDebug() << "Adding new task";
    Event* event = new Event("Untitled Event");
    //events.append(event);
//    ui->verticalLayout->addWidget(event);
}


Ui::MainWindow MainWindow::getUIObject()
{
    return *ui;
}
