#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UDPBroadcaster.h"
#include "Event.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    discoverer = new UDPBroadcaster();
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
    //Event* event = new Event("Untitled Event");
    //events.append(event);
    //ui->verticalLayout->addWidget(event);
}

void MainWindow::initBroadCastPeerState()
{
    connect(ui->connectPushButton, SIGNAL( clicked() ), discoverer, SLOT( broadcastDatagram() )  );
}


Ui::MainWindow MainWindow::getUIObject()
{
    return *ui;
}
