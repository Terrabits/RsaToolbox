#ifndef VnaSet_H
#define VnaSet_H


// RsaToolbox
#include "Definitions.h"
// Etc

// Qt
#include <QObject>
#include <QScopedPointer>


namespace RsaToolbox {
class Vna;

class VnaSet : QObject
{
private: Q_OBJECT

public:
    explicit VnaSet(QObject *parent = 0);
    VnaSet(const VnaSet &other);
    VnaSet(Vna *vna, QString name, QObject *parent = 0);
    ~VnaSet();

    void select();
    void save(QString &filePathName);

    void operator=(VnaSet const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;

    QString _name;
    
    bool isFullyInitialized() const;
    
};
}

#endif // VnaSet_H
