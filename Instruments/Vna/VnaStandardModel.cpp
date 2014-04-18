

// Rsa
#include "VnaStandardModel.h"
using namespace RsaToolbox;

/*!
 * \class RsaToolbox::VnaStandardModel
 * \ingroup VnaGroup
 * \brief The \c %VnaStandardModel class
 * is a data type used to represent a
 * VNA calibration standard that is
 * defined by a lumped-element model.
 */

VnaStandardModel::VnaStandardModel()
{
    eLength_m = 0;
    loss_dB_per_sqrt_Hz = 0;
    Z0_Ohms = 0;
    C0_fF = 0;
    C1_fF_per_GHz = 0;
    C2_fF_per_GHz2 = 0;
    C3_fF_per_GHz3 = 0;
    L0_pH = 0;
    L1_pH_per_GHz = 0;
    L2_pH_per_GHz2 = 0;
    L3_pH_per_GHz3 = 0;
    R_Ohms = 0;
}

void VnaStandardModel::operator=(VnaStandardModel const &other) {
    eLength_m = other.eLength_m;
    loss_dB_per_sqrt_Hz = other.loss_dB_per_sqrt_Hz;
    Z0_Ohms = other.Z0_Ohms;
    C0_fF = other.C0_fF;
    C1_fF_per_GHz = other.C1_fF_per_GHz;
    C2_fF_per_GHz2 = other.C2_fF_per_GHz2;
    C3_fF_per_GHz3 = other.C3_fF_per_GHz3;
    L0_pH = other.L0_pH;
    L1_pH_per_GHz = other.L1_pH_per_GHz;
    L2_pH_per_GHz2 = other.L2_pH_per_GHz2;
    L3_pH_per_GHz3 = other.L3_pH_per_GHz3;
    R_Ohms = other.R_Ohms;
}

bool RsaToolbox::operator==(VnaStandardModel const &left, VnaStandardModel const &right) {
    if (left.eLength_m != right.eLength_m)
        return(false);
    if (left.loss_dB_per_sqrt_Hz != right.loss_dB_per_sqrt_Hz)
        return(false);
    if (left.Z0_Ohms != right.Z0_Ohms)
        return(false);
    if (left.C0_fF != right.C0_fF)
        return(false);
    if (left.C1_fF_per_GHz != right.C1_fF_per_GHz)
        return(false);
    if (left.C2_fF_per_GHz2 != right.C2_fF_per_GHz2)
        return(false);
    if (left.C3_fF_per_GHz3 != right.C3_fF_per_GHz3)
        return(false);
    if (left.L0_pH != right.L0_pH)
        return(false);
    if (left.L1_pH_per_GHz != right.L1_pH_per_GHz)
        return(false);
    if (left.L2_pH_per_GHz2 != right.L2_pH_per_GHz2)
        return(false);
    if (left.L3_pH_per_GHz3 != right.L3_pH_per_GHz3)
        return(false);
    if (left.R_Ohms != right.R_Ohms)
        return(false);
    // else
    return(true);
}
bool RsaToolbox::operator!=(VnaStandardModel const &left, VnaStandardModel const &right) {
    return(!operator==(left, right));
}
