

// RsaToolbox
#include <DoubleEdit.h>
using namespace RsaToolbox;

// Qt
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DoubleEdit doubleEdit;
    doubleEdit.show();
    return app.exec();
}
