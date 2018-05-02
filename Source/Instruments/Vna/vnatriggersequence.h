#ifndef VNATRIGGERSEQUENCE_H
#define VNATRIGGERSEQUENCE_H

#include <QMetaType>
#include <QString>

// must be included at the end of VnaTrigger.h
// C++0x... ugh.

RsaToolbox::VnaTrigger::Sequence vnaTriggerSequenceFromScpi(QString scpi);
QString toScpi(RsaToolbox::VnaTrigger::Sequence sequence);

Q_DECLARE_METATYPE(RsaToolbox::VnaTrigger::Sequence)

#endif // VNATRIGGERSEQUENCE_H
