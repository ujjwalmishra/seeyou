#ifndef PEERBOX_H
#define PEERBOX_H
#include <QWidget>

class PeerBox : public QWidget
{

    Q_OBJECT

    public:
        explicit PeerBox(QWidget *parent = 0);
        void init();

};

#endif // PEERBOX_H
