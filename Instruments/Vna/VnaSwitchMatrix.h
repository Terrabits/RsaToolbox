#ifndef VnaSwitchMatrix_H
#define VnaSwitchMatrix_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaSwitchMatrix : public QObject
{
private: Q_OBJECT

public:
    explicit VnaSwitchMatrix(QObject *parent = 0);
    VnaSwitchMatrix(const VnaSwitchMatrix &other);
    VnaSwitchMatrix(Vna *vna, uint index, QObject *parent = 0);

    // METHODS

    void operator=(VnaSwitchMatrix const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    uint _index;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaSwitchMatrix_H
