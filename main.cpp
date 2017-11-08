#include "mainwindow.h"
#include "CoreApp.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog* loginDialog = new LoginDialog();
    loginDialog->setUsername( "Luca" ); // optional
    int result = loginDialog->exec();
    if(loginDialog->getGo()){
        qDebug() << loginDialog->getUsername();
        MainWindow w;
        CoreApp::getObject(w, loginDialog->getUsername());
        w.show();
        return a.exec();
    }
    else{

        a.quit();
        return 0;
    }

}
