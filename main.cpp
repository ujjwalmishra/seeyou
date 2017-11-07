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

        MainWindow w;
        CoreApp::getObject(w);
        w.show();
        qDebug() << result;
        qDebug() << "got it here";
        return a.exec();
    }
    else{

        a.quit();
        return 0;
    }

}
