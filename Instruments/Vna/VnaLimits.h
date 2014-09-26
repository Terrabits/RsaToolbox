#ifndef VnaLimits_H
#define VnaLimits_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaTrace;

class VnaLimits : QObject
{
private: Q_OBJECT

public:
    explicit VnaLimits(QObject *parent = 0);
    VnaLimits(const VnaLimits &other);
    VnaLimits(Vna *vna, VnaTrace *trace, QObject *parent = 0);
    VnaLimits(Vna *vna, QString traceName, QObject *parent = 0);

    bool isOn();
    bool isOff();
    void on(bool isOn = true);
    void off(bool isOff = true);
    bool isPass();
    bool isFail();

    bool isVisible();
    bool isHidden();
    void show(bool isVisible = true);
    void hide(bool isHidden = true);

    void setUpper(QString trace, double xOffset, double yOffset);
    void setUpper(QRowVector frequencies_Hz, QRowVector values);
    void setLower(QString trace, double xOffset, double yOffset);
    void setLower(QRowVector frequencies_Hz, QRowVector values);
    void deleteAll();

    void operator=(VnaLimits const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    uint _channel;
    
    bool isFullyInitialized() const;
};
}

#endif // VnaLimits_H
