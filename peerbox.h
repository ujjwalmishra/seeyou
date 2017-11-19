#ifndef PEERBOX_H
#define PEERBOX_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QUuid>

class PeerBox : public QWidget
{

    Q_OBJECT

    public:
        explicit PeerBox(QWidget *parent = 0);
        void init(QString name, QUuid uid);
        void addButtons();
        void showButtons();
        void paintEvent(QPaintEvent *e) override;
        void toggleNotif();

    public slots:
        void updatePeer();
        void removePeer();
        void viewPeer();

    private:
        QPushButton *notifPeerButton;
        QPushButton *viewPeerButton;
        QPushButton *removePeerButton;
        QString peername;
        QHBoxLayout *gridLayout;
        bool updated = false;
        QUuid pUid;

};

#endif // PEERBOX_H
