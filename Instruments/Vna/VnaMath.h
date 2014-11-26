#ifndef VnaMath_H
#define VnaMath_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaTrace;

class VnaMath : QObject
{
    Q_OBJECT

public:
    explicit VnaMath(QObject *parent = 0);
    VnaMath(const VnaMath &other);
    VnaMath(Vna *vna, VnaTrace *trace, QObject *parent = 0);
    VnaMath(Vna *vna, QString traceName, QObject *parent = 0);
    ~VnaMath();

    bool isOn();
    bool isOff();
    void on(bool isOn = true);
    void off(bool isOff = true);
    QString expression();
    void setExpression(QString expression);

    void divideBy(QString trace);

    void operator=(VnaMath const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    uint _channel;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaMath_H
