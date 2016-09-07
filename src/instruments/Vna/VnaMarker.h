#ifndef VnaMarker_H
#define VnaMarker_H


// RsaToolbox
#include "Definitions.h"


// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;
class VnaTrace;

class VnaMarker : public QObject
{
    Q_OBJECT

public:
    explicit VnaMarker(QObject *parent = 0);
    VnaMarker(const VnaMarker &other);
    VnaMarker(Vna *vna, VnaTrace *trace, uint index, QObject *parent = 0);
    VnaMarker(Vna *vna, QString traceName, uint index, QObject *parent = 0);
    ~VnaMarker();

    QString name();
    void setName(QString name);

    bool isDeltaOn();
    bool isDeltaOff();

    void deltaOn(bool isOn = true);
    void deltaOff(bool isOff = true);

    double y();
    double x();
    void coordinates(double &x, double &y);
    void setX(double x, SiPrefix prefix = SiPrefix::None);

    void searchForMax();
    void searchForMin();
    void searchFor(double y);
    void searchRightFor(double y);
    void searchRightForPeak();
    void searchLeftFor(double y);
    void searchLeftForPeak();
    void setReferenceMarker();

    // Calculate:
    void measureBandpassFilter();

    void operator=(VnaMarker const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QScopedPointer<VnaTrace> _trace;
    QString _traceName;
    uint _index;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaMarker_H
