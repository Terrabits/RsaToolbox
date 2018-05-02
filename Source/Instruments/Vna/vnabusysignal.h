#ifndef VNABUSYSIGNAL_H
#define VNABUSYSIGNAL_H

#include <QString>

namespace RsaToolbox {

enum /*class*/ VnaBusySignal {
    Auto,
    Sweep,
    Segment,
    PartialPoint,
    Point
};
}

QString toScpi(RsaToolbox::VnaBusySignal signal);
RsaToolbox::VnaBusySignal vnaBusySignalFromScpi(QString scpi);

#endif // VNABUSYSIGNAL_H
