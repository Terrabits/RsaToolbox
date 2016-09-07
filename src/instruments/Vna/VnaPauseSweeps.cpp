#include "VnaPauseSweeps.h"
using namespace RsaToolbox;

// Qt
#include <QDebug>

VnaPauseSweeps::VnaPauseSweeps(Vna *vna, bool pause, bool resumeOnDestruction):
    _vna(vna),
    _paused(false),
    _shouldResume(resumeOnDestruction)
{
    if (pause) {
        this->pause();
    }
}

VnaPauseSweeps::~VnaPauseSweeps()
{
    if (_paused && _shouldResume) {
        resume();
    }
}

void VnaPauseSweeps::pause() {
    if (_paused)
        return;

    _channels.clear();
    _continuous.clear();

    _channels = _vna->channels();
    const uint numberOfChannels = _channels.size();
    _continuous.resize(numberOfChannels);
    for (uint i = 0; i < numberOfChannels; i++) {
        uint c = _channels[i];
        _continuous[i] = _vna->channel(c).isContinuousSweep();
        _vna->channel(c).manualSweepOn();
    }
    _paused = true;
}

void VnaPauseSweeps::resume() {
    if (!_paused)
        return;

    removeNonExistentChannels();

    for (int i = 0; i < _channels.size(); i++) {
        if (_continuous[i]) {
            const uint c = _channels[i];
            _vna->channel(c).continuousSweepOn();
        }
    }
    _paused = false;
}
void VnaPauseSweeps::resumeOnDestruction(bool resume) {
    _shouldResume = resume;
}

void VnaPauseSweeps::removeNonExistentChannels() {
    QVector<uint> currentChannels = _vna->channels();
    int i = 0;
    while (i < _channels.size()) {
        const uint c = _channels[i];
        if (!currentChannels.contains(c)) {
            _channels.removeAt(i);
            _continuous.removeAt(i);
        }
        else {
            i++;
        }
    }
}
