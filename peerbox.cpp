#include "peerbox.h"
#include <QPainter>
#include <QDebug>

PeerBox::PeerBox(QWidget *parent)
    : QWidget(parent)
{

}

void PeerBox::init(QString name, QUuid uid){
    peername = name;
    pUid = uid;
    addButtons();
    connect(viewPeerButton, SIGNAL(clicked()), this, SLOT(updatePeer()));
    connect(viewPeerButton, SIGNAL(clicked()), this, SLOT(viewPeer()));
    connect(removePeerButton, SIGNAL(clicked()), this, SLOT(removePeer()));
}

void PeerBox::addButtons(){
    gridLayout = new QHBoxLayout();
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    notifPeerButton = new QPushButton(tr("Update"));
    notifPeerButton->setStyleSheet("QPushButton { border-color: rgb(66, 69, 183);  border-width: 3px;border-style: solid;border-radius: 4px;"
                                  "padding: 2px 20px; width:55%; margin:10px }");
    viewPeerButton = new QPushButton(tr("View"));
    viewPeerButton->setStyleSheet("QPushButton { border-color: rgb(66, 69, 183);  border-width: 3px;border-style: solid;border-radius: 4px;"
                                  "padding: 2px 20px; width:55%; margin:10px }");
    removePeerButton = new QPushButton(tr("Remove"));
    removePeerButton->setStyleSheet("QPushButton { border-color: rgb(66, 69, 183);  border-width: 3px;border-style: solid;border-radius: 4px;"
                                  "padding: 2px 20px; width:55%; margin:10px }");
    gridLayout->addWidget(notifPeerButton);
    gridLayout->addWidget(viewPeerButton);
    gridLayout->addWidget(removePeerButton);
    gridLayout->setSpacing(4);
    gridLayout->setContentsMargins(0, 0, 0 ,0 );
    this->setLayout(gridLayout);

}

void PeerBox::paintEvent(QPaintEvent *e){
//      QPainter painter(this);
//      QPen pen(Qt::transparent, 2);
//      painter.setPen(pen);
//      painter.save();
//      switch(updated) {
//      case false:
//          painter.setBackground(Qt::red);
//          painter.setBrush(Qt::red);
//          break;
//      case true:

//          painter.setBrush(Qt::green);
//          break;

//      }
//      painter.drawEllipse(QPointF(12,12), 10, 10);
//      painter.restore();
}

void PeerBox::toggleNotif(){
    notifPeerButton->setStyleSheet("QPushButton { border-color: red;  border-width: 3px;border-style: solid;border-radius: 4px;"
                                   "padding: 2px 20px; width:55%; margin:10px; background-color: white }");
    updated = !updated;
}

void PeerBox::updatePeer(){

}

void PeerBox::removePeer(){
    qDebug() << "removing";
    toggleNotif();
    update();
}

void PeerBox::viewPeer(){

}
