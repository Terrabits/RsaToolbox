#ifndef VnaReferenceMarker_H
#define VnaReferenceMarker_H


// RsaToolbox
#include "Definitions.h"


// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaTrace;

class VnaReferenceMarker : public QObject
{
    Q_OBJECT

public:
    explicit VnaReferenceMarker(QObject *parent = 0);
    VnaReferenceMarker(const VnaReferenceMarker &other);
    VnaReferenceMarker(Vna *vna, VnaTrace *trace, QObject *parent = 0);
    VnaReferenceMarker(Vna *vna, QString traceName, QObject *parent = 0);
    ~VnaReferenceMarker();

    bool isOn();
    void on(bool isOn = true);
    bool isOff();
    void off(bool isOff = true);

    QString name();
    void setName(QString name);

    double x();
    double y();
    void coordinates(double &x, double &y);
    void setX(double x, SiPrefix prefix = SiPrefix::None);
    void setToMarker(uint markerIndex);

    void operator=(VnaReferenceMarker const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    QString _traceName;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaReferenceMarker_H
