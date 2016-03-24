#include "ConnectionTypeComboBox.h"
using namespace RsaToolbox;


ConnectionTypeComboBox::ConnectionTypeComboBox(QWidget *parent) :
    QComboBox(parent)
{
    QStringList items;
    items << "TCPIP" << "GPIB" << "USB";
    addItems(items);
}

ConnectionType ConnectionTypeComboBox::currentType() {
    QString text = currentText();
    if (text == "TCPIP")
        return ConnectionType::VisaTcpConnection;
    if (text == "GPIB")
        return ConnectionType::VisaGpibConnection;
    if (text == "USB")
        return ConnectionType::VisaUsbConnection;
    // Else
    return ConnectionType::NoConnection;
}
void ConnectionTypeComboBox::setCurrentType(ConnectionType type) {
    if (type == currentType())
        return;

    if (type == ConnectionType::VisaTcpConnection)
        setCurrentText("TCPIP");
    else if (type == ConnectionType::VisaGpibConnection)
        setCurrentText("GPIB");
    else if (type == ConnectionType::VisaUsbConnection)
        setCurrentText("USB");
    else
        setCurrentIndex(-1); // UNKNOWN
}

