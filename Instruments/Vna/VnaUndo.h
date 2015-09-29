#ifndef VNAUNDO_H
#define VNAUNDO_H


// RsaToolbox
#include "Vna.h"

// Qt
#include <QString>


namespace RsaToolbox {

class VnaUndo
{
public:
    VnaUndo();
    VnaUndo(Vna *vna, bool recallOnDestruction = false);
    ~VnaUndo();

    void setRecallOnDestruction(bool recall);
    void setVna(Vna *vna);

    void save();
    void recall();
    void discard();

private:
    Vna *_vna;
    QString _setName;
    bool _recallOnDestruction;

    static QString generateUniqueName();
    bool isVna();
    bool isSet();
};
} // RsaToolbox


#endif // VNAUNDO_H
