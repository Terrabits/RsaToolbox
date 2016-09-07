#ifndef VnaDiagram_H
#define VnaDiagram_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaDiagram : public QObject
{
    Q_OBJECT

public:
    explicit VnaDiagram(QObject *parent = 0);
    VnaDiagram(const VnaDiagram &other);
    VnaDiagram(Vna *vna, uint index, QObject *parent = 0);
    ~VnaDiagram();

    void select();

    QVector<uint> channels();

    QStringList traces();
    void deleteTraces();

    bool isTitleOn();
    bool isTitleOff();
    void titleOn(bool isOn = true);
    void titleOff(bool isOff = true);
    QString title();
    void setTitle(QString title);

    bool isMaximized();
    void maximize();
    void normalSize();

    void autoscale();
    void setYAxisMinimum(double min);
    void setYAxisMaximum(double max);
    void setYAxis(double min, double max);

    void saveScreenshot(QString filename, ImageFormat format = ImageFormat::Png);
    void saveScreenshotLocally(QString filename, ImageFormat format = ImageFormat::Png);

    void operator=(VnaDiagram const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    uint _index;
    
    bool isFullyInitialized() const;
    QVector<uint> traceIndices(); //?
    
};
}

#endif // VnaDiagram_H
