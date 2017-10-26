#include "mainwindow.h"
#include "CoreApp.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //CoreApp *app =
    CoreApp::getObject(w);
    LoginDialog* loginDialog = new LoginDialog();
    loginDialog->setUsername( "Luca" ); // optional
//    QObject::connect( loginDialog,
//     SIGNAL (acceptLogin(QString&,QString&,int&)),
//     app,
//     SLOT (checkLogin(QString&,QString&)));
    loginDialog->exec();


//    w.show();

    return a.exec();
}
