#include "mainwindow.h"
#include "CoreApp.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDialog;
    loginDialog.setUsername( "Luca" ); // optional
   // int result = loginDialog->exec();
    if(true){
   //if(loginDialog->getGo()){
        MainWindow w;
        CoreApp::getObject(w, std::move(loginDialog.getUsername()));
        w.show();
        return a.exec();
    }
    else{

        a.quit();
        return 0;
    }

}
