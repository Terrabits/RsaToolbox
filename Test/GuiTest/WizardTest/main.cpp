#include <QApplication>

#include <Wizard.h>
using namespace RsaToolbox;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Wizard wizard;
    wizard.show();

    return a.exec();
}
