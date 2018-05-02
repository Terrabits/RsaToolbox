#ifndef VNATRIGGERSOURCE_H
#define VNATRIGGERSOURCE_H

#include <QMetaType>
#include <QString>

namespace RsaToolbox {
    enum /*class*/ VnaTriggerSource {
        FreeRun, // IMMediate
        External,
        Manual,
        Multiple,
        Timed,
        PulseGenerator
    };
}



QString toScpi(RsaToolbox::VnaTriggerSource source);
RsaToolbox::VnaTriggerSource vnaTriggerSourceFromScpi(QString scpi);

Q_DECLARE_METATYPE(RsaToolbox::VnaTriggerSource)

#endif // VNATRIGGERSOURCE_H
