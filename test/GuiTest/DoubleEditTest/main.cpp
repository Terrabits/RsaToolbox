

// RsaToolbox
#include <DoubleEdit.h>
using namespace RsaToolbox;

// Qt
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DoubleEdit edit;
    edit.setDecimalPlaces(1);
    edit.setUnitAbbrev("Ω");
    edit.interpretMKeyAsMilli();
    edit.setMinimum(1.0, SiPrefix::Femto);
    edit.show();
    return app.exec();
}
