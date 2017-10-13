#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statediscoverer.h"
#include "event.h"
#include "statereciever.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), events()
{
    ui->setupUi(this);
    discoverer = new StateDiscoverer();
    connect(ui->addButton, &QPushButton::clicked,
       this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::setCheckBox( bool flag)
{
    Qt::CheckState state=flag?Qt::Checked:Qt::Unchecked;
    ui->statusConnectionBox->setCheckState(state);

    return true;
}

bool MainWindow::setProgressBar(bool flag)
{
    int value=flag?100:0;
    ui->statusProgressBar->setValue(value);

    return true;
}

void MainWindow::addTask()
{
    qDebug() << "Adding new task";
    Event* event = new Event("Untitled Event");
    events.append(event);
    ui->verticalLayout->addWidget(event);
}

void MainWindow::initBroadCastPeerState()
{
    connect(ui->connectPushButton, SIGNAL( clicked() ), discoverer, SLOT( broadcastDatagram() )  );
}

void MainWindow::initReciever()
{
    rcvr = new Receiver();
    rcvr->init();
}

void MainWindow::initPeerState()
{
    pState = new PeerState;
    pState->setState(initializing);
    pState->setEventCount(0);
}

void MainWindow::initPeer() {
    peer = new Peer();
    peer->setPeerState(*pState);
}

Ui::MainWindow MainWindow::getUIObject()
{
    return *ui;
}
