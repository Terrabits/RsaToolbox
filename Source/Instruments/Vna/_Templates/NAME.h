#ifndef %NAME%_H
#define %NAME%_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class %NAME% : QObject
{
private: Q_OBJECT

public:
    explicit %NAME%(QObject *parent = 0);
    %NAME%(const %NAME% &other);
    %NAME%(Vna *vna, QObject *parent = 0);

    // METHODS

    void operator=(%NAME% const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    
    bool isFullyInitialized() const;
    
};
}

#endif // %NAME%_H
