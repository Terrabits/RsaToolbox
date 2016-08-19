

// RsaToolbox
#include "TestBus.h"
using namespace RsaToolbox;

// C++
#include <cstring>
//#include <cstdio>

// Qt
#include <QString>
#include <QTextStream>
#include <QDebug>

TestBus::TestBus(QObject *parent)
    : GenericBus(parent),
    _bytes(0)
{

}
TestBus::~TestBus() {

}

bool TestBus::isOpen() const {
    return true;
}
bool TestBus::isClosed() const {
    return false;
}

void TestBus::addResponses(const QStringList &responses) {
    for (int i = 0; i < responses.size(); i++) {
        _responses << responses.at(i).toUtf8();
    }
}
bool TestBus::read(char *buffer, uint bufferSize_B) {
    _bytes = -1;
    nullTerminate(buffer, bufferSize_B, 0);

    while (_t)
}
bool TestBus::write(QString scpi) {
    return binaryWrite(scpi.toUtf8());
}
