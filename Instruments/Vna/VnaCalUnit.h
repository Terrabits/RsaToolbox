#ifndef VnaCalUnit_H
#define VnaCalUnit_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaCalUnit : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCalUnit(QObject *parent = 0);
    VnaCalUnit(const VnaCalUnit &other);
    VnaCalUnit(Vna *vna, QString id, QObject *parent = 0);

    // METHODS

    void operator=(VnaCalUnit const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QString _id;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaCalUnit_H
