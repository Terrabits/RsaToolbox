#ifndef VNAUNDOTEST_H
#define VNAUNDOTEST_H

#include <VnaTestClass.h>
#include <QObject>

class VnaUndoTest : public RsaToolbox::VnaTestClass
{
    Q_OBJECT
public:
    explicit VnaUndoTest(QObject *parent = 0);
    explicit VnaUndoTest(RsaToolbox::ConnectionType type, const QString &address, QObject *parent = 0);

private slots:
    void directoryHandlingTest();

};

#endif // VNAUNDOTEST_H
