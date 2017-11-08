#include "peerbox.h"
#include <QPainter>

PeerBox::PeerBox(QWidget *parent)
    : QWidget(parent)
{

}

void PeerBox::init(QString name){
    peername = name;
    addButtons();
    connect(viewPeerButton, SIGNAL(clicked()), this, SLOT(viewPeer()));
    connect(removePeerButton, SIGNAL(clicked()), this, SLOT(removePeer()));
}

void PeerBox::addButtons(){
    gridLayout = new QHBoxLayout();
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    viewPeerButton = new QPushButton(tr("View"));
    removePeerButton = new QPushButton(tr("Remove"));
    gridLayout->addWidget(viewPeerButton);
    gridLayout->addWidget(removePeerButton);
    gridLayout->setSpacing(4);
    gridLayout->setContentsMargins(0, 0, 0 ,0 );
    this->setLayout(gridLayout);

}

void PeerBox::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, 100, 50), 1, 10);
    QPen pen(Qt::black, 1);
    p.setPen(pen);
    p.fillPath(path, Qt::red);
    p.drawPath(path);
}

void PeerBox::removePeer(){

}

void PeerBox::viewPeer(){

}
