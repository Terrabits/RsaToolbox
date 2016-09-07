#ifndef VNAPAUSESWEEPS_H
#define VNAPAUSESWEEPS_H


// RsaToolbox
#include "Vna.h"

// Qt
#include <QVector>


namespace RsaToolbox {

class VnaPauseSweeps
{
public:
    VnaPauseSweeps(Vna *vna, bool pause=true, bool resumeOnDestruction=true);
    ~VnaPauseSweeps();

    void pause();
    void resume();
    void resumeOnDestruction(bool resume = true);

private:
    Vna *_vna;
    bool _paused;
    bool _shouldResume;
    QVector<uint> _channels;
    QVector<bool> _continuous;

    void removeNonExistentChannels();
};
}

#endif // VNAPAUSESWEEPS_H
