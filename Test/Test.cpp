#include "Test.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QMessageBox>


void RsaToolbox::pause(QString message) {
    if (message.isEmpty())
        message = "Click ok to continue";

    QMessageBox messageBox;
    messageBox.setWindowTitle("Pause");
    messageBox.setText(message);
    messageBox.setModal(false);
    messageBox.exec();
}
