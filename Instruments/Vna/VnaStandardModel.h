#ifndef VNASTANDARDMODEL_H
#define VNASTANDARDMODEL_H

// Rsa
//

// Qt
#include <QMetaType>

namespace RsaToolbox {

class VnaStandardModel
{
public:
    VnaStandardModel();

    // General uW parameters:
    double eLength_m;
    double loss_dB_per_sqrt_Hz;
    double Z0_Ohms;

    // Lumped element load model:
    double C0_fF;
    double C1_fF_per_GHz;
    double C2_fF_per_GHz2;
    double C3_fF_per_GHz3;
    double L0_pH;
    double L1_pH_per_GHz;
    double L2_pH_per_GHz2;
    double L3_pH_per_GHz3;
    double R_Ohms;

    void operator=(VnaStandardModel const &other);
};

bool operator==(VnaStandardModel const &left, VnaStandardModel const &right);
bool operator!=(VnaStandardModel const &left, VnaStandardModel const &right);
}
Q_DECLARE_METATYPE(RsaToolbox::VnaStandardModel)

#endif // VNASTANDARDMODEL_H
