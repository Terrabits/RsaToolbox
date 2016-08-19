#include "About.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    About w;
    w.setAppName("About Window Test");
    w.setVersion("1.0");
    w.setDescription("This application tests the About window");
    w.setContactInfo("My name\nMy location\nMy number\nMy email");
    w.show();
    return a.exec();
}
