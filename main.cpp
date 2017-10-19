#include "mainwindow.h"
#include "CoreApp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //CoreApp app(w);
    CoreApp::getObject(w);
    w.show();

    return a.exec();
}
