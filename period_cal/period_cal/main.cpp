#include "maindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainDialog maindialog;
    maindialog.show();

    return app.exec();
}
