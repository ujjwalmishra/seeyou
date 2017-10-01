#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statediscoverer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    discoverer = new StateDiscoverer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::setCheckBox( bool flag)
{
    Qt::CheckState state=flag?Qt::Checked:Qt::Unchecked;
    ui->checkBox->setCheckState(state);

    return true;
}

bool MainWindow::setProgressBar(bool flag)
{
    int value=flag?100:0;
    ui->progressBar->setValue(value);

    return true;
}

void MainWindow::initBroadCastPeerState()
{
    connect(ui->pushButton, SIGNAL( clicked() ), discoverer, SLOT( broadcastDatagram() )  );
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
