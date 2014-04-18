

// RsaToolbox includes
#include "General.h"
#include "VnaTimeDomain.h"
#include "VnaChannel.h"
#include "Vna.h"
using namespace RsaToolbox;

// Qt includes
// #include <Qt>

/*!
 * \class RsaToolbox::VnaTimeDomain
 * \ingroup VnaGroup
 * \brief The \c %VnaTimeDomain class
 * controls the conversion to the time
 * domain of a particular trace.
 */

VnaTimeDomain::VnaTimeDomain(QObject *parent) :
    QObject(parent)
{
    placeholder.reset(new Vna());
    _vna = placeholder.data();
    _trace.reset(new VnaTrace());
    _traceName = QString();
}

VnaTimeDomain::VnaTimeDomain(const VnaTimeDomain &other)
{
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();

    }
}
VnaTimeDomain::VnaTimeDomain(Vna *vna, VnaTrace *trace, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(*trace));
    _traceName = trace->name();
}

VnaTimeDomain::VnaTimeDomain(Vna *vna, QString traceName, QObject *parent) :
    QObject(parent)
{
    _vna = vna;
    _trace.reset(new VnaTrace(vna, traceName));
    _traceName = traceName;
}

bool VnaTimeDomain::isOn() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:STAT?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi) == "1");
}
bool VnaTimeDomain::isOff() {
    return(!isOn());
}
void VnaTimeDomain::on(bool isOn) {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:STAT %2\n";
    scpi = scpi.arg(_trace->channel());
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaTimeDomain::off(bool isOff) {
    on(!isOff);
}

bool VnaTimeDomain::isTimeAxis() {
    return(false);
}
bool VnaTimeDomain::isDistanceAxis() {
    return(false);
}

bool VnaTimeDomain::isBandpassImpulseResponse() {
    return(filterTypeScpi() == "BPAS");
}
void VnaTimeDomain::setBandpassImpulseResponse() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME BPAS\n";
    scpi = scpi.arg(_trace->channel());
    _vna->write(scpi);
}
bool VnaTimeDomain::isLowpassImpulseResponse() {
    if (filterTypeScpi() == "LPAS" && responseTypeScpi() == "IMP")
        return(true);
    // else
        return(false);
}
void VnaTimeDomain::setLowpassImpulseResponse() {
    _trace->select();

    uint channel = _trace->channel();
    QString filterScpi = ":CALC%1:TRAN:TIME LPAS\n";
    filterScpi = filterScpi.arg(channel);
    _vna->write(filterScpi);

    QString responseScpi = ":CALC%1:TRAN:TIME:STIM IMP\n";
    responseScpi = responseScpi.arg(channel);
    _vna->write(responseScpi);

}
bool VnaTimeDomain::isLowpassStepResponse() {
    if (filterTypeScpi() == "LPAS" && responseTypeScpi() == "STEP")
        return(true);
    // else
        return(false);
}
void VnaTimeDomain::setLowpassStepResponse() {
    _trace->select();

    uint channel = _trace->channel();
    QString filterScpi = ":CALC%1:TRAN:TIME LPAS\n";
    filterScpi = filterScpi.arg(channel);
    _vna->write(filterScpi);

    QString responseScpi = ":CALC%1:TRAN:TIME:STIM STEP\n";
    responseScpi = responseScpi.arg(channel);
    _vna->write(responseScpi);
}

double VnaTimeDomain::startValue() {
    QString scpi = ":CALC%1:TRAN:TIME:STAR?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toDouble());
}
void VnaTimeDomain::setStart(double value, SiPrefix prefix) {
    value *= toDouble(prefix);
    QString scpi = ":CALC%1:TRAN:TIME:STAR %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(value);
    _vna->write(scpi);
}
double VnaTimeDomain::stopValue() {
    QString scpi = ":CALC%1:TRAN:TIME:STOP?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toDouble());
}
void VnaTimeDomain::setStop(double value, SiPrefix prefix) {
    value *= toDouble(prefix);
    QString scpi = ":CALC%1:TRAN:TIME:STOP %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(value);
    _vna->write(scpi);
}

bool VnaTimeDomain::isAutomaticDcExtrapolation() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:LPAS:DCSP:CONT?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi) == "1");
}
bool VnaTimeDomain::isManualDcExtrapolation() {
    return(!isAutomaticDcExtrapolation());
}
void VnaTimeDomain::automaticDcExtrapolationOn(bool isOn) {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:LPAS:DCSP:CONT %2\n";
    scpi = scpi.arg(_trace->channel());
    if (isOn)
        scpi = scpi.arg(1);
    else
        scpi = scpi.arg(0);
    _vna->write(scpi);
}
void VnaTimeDomain::manualDcExtrapolationOn(bool isOn) {
    automaticDcExtrapolationOn(!isOn);
}
double VnaTimeDomain::extrapolatedDcValue() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:LPAS:DCSP?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toDouble());
}
void VnaTimeDomain::setExtrapolatedDcValue(double dcValue) {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:LPAS:DCSP %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(dcValue);
    _vna->write(scpi);
}

bool VnaTimeDomain::isResolutionEnhancementOn() {
    return(resolutionEnhancementFactor() != 1.0);
}
bool VnaTimeDomain::isResolutionEnhancementOff() {
    return(!isResolutionEnhancementOn());
}
double VnaTimeDomain::resolutionEnhancementFactor() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:RES:EFAC?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toDouble());
}
void VnaTimeDomain::resolutionEnhancementOff() {
    setResolutionEnhancement(1.0);
}
void VnaTimeDomain::setResolutionEnhancement(double factor) {
    if (factor < 1 || factor > 10)
        _vna->printLine("Warning: Resolution Enhancement Factor must be 1-10, inclusive.");

    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:RES:EFAC %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(formatDouble(factor, 1));
    _vna->write(scpi);
}

bool VnaTimeDomain::isWindow(VnaWindowFunction window) {
    Q_UNUSED(window);
    return(false);
}
VnaWindowFunction VnaTimeDomain::window() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:WIND?\n";
    scpi = scpi.arg(_trace->channel());
    return(toWindow(_vna->query(scpi)));
}
void VnaTimeDomain::setWindow(VnaWindowFunction window) {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:WIND %2\n";
    scpi = scpi.arg(_trace->channel());
    scpi = scpi.arg(toScpi(window));
    _vna->write(scpi);
}

double VnaTimeDomain::slowestRiseTime_s(RiseTimeDefinition definition) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    return(factor/(11*_vna->properties().minimumFrequency_Hz()));
}
double VnaTimeDomain::fastestRiseTime_s(RiseTimeDefinition definition) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    return(factor/(_vna->properties().maximumFrequency_Hz()));
}
double VnaTimeDomain::longestRange_s() {
    uint maxPoints = _vna->properties().maximumPoints();
    double minFrequency = _vna->properties().minimumFrequency_Hz();
    return((maxPoints-1) / (10.0 * minFrequency));
}
double VnaTimeDomain::longestRange_s(double riseTime_s, RiseTimeDefinition definition) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    double stopFrequency_Hz = factor/riseTime_s;
    uint maxPoints = _vna->properties().maximumPoints();
    return((11.0/10.0)*((maxPoints-1)/stopFrequency_Hz));
}
double VnaTimeDomain::shortestRange_s() {
    double maxFrequency = _vna->properties().maximumFrequency_Hz();
    return(11.0/maxFrequency);
}
double VnaTimeDomain::shortestRange_s(double riseTime_s, RiseTimeDefinition definition) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    double stopFrequency = factor/riseTime_s;
    return(11.0/stopFrequency);
}

double VnaTimeDomain::unambiguousRange_s() {
    uint channel = _trace->channel();
    VnaLinearSweep sweep = _vna->channel(channel).linearSweep();
    return(1.0/sweep.spacing_Hz());
}
double VnaTimeDomain::riseTime_s(RiseTimeDefinition definition) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    uint channel = _trace->channel();
    VnaLinearSweep sweep = _vna->channel(channel).linearSweep();
    return(factor/sweep.stop_Hz());
}

void VnaTimeDomain::setupChannel(double riseTime_s, RiseTimeDefinition definition, double unambiguousRange_s) {
    double factor = 1.0/2.0;
    if (definition == RISETIME_20_TO_80)
        factor = 1.0/2.0;
    else if (definition == RISETIME_10_TO_90)
        factor = 1.5/2.0;

    double stopFrequency_Hz = factor/riseTime_s;
    double spacing_Hz = 1/unambiguousRange_s;

    uint channel = _trace->channel();
    _vna->channel(channel).setSweepType(LINEAR_SWEEP);
    setHarmonicGrid(stopFrequency_Hz, spacing_Hz);
}
void VnaTimeDomain::setupTrace() {
    _trace->setFormat(LINEAR_MAGNITUDE_TRACE);
    on();
    setLowpassStepResponse();
    automaticDcExtrapolationOn();
    resolutionEnhancementOff();
    setWindow(HAMMING_WINDOW_FUNCTION);
    setStart(0);
    setStop(unambiguousRange_s());
}

// Harmonic grid:
void VnaTimeDomain::adjustChannelFrequencySpacing() {
    QString scpi = ":CALC%1:TRAN:TIME:LPAS KFST\n";
    scpi = scpi.arg(_trace->channel());
}
void VnaTimeDomain::adjustChannelStopFrequency() {
    QString scpi = ":CALC%1:TRAN:TIME:LPAS KDFR\n";
    scpi = scpi.arg(_trace->channel());
    _vna->write(scpi);
}
void VnaTimeDomain::adjustChannelPoints() {
    QString scpi = ":CALC%1:TRAN:TIME:LPAS KSDF\n";
    scpi = scpi.arg(_trace->channel());
    _vna->write(scpi);
}

void VnaTimeDomain::operator=(VnaTimeDomain const &other) {
    if (other.isFullyInitialized()) {
        _vna = other._vna;
        _trace.reset(new VnaTrace(*other._trace.data()));
        _traceName = other._traceName;
    }
    else {
        placeholder.reset(new Vna());
        _vna = placeholder.data();
        _trace.reset(new VnaTrace());
        _traceName = QString();

    }
}

// Private
bool VnaTimeDomain::isFullyInitialized() const {
    if (_vna == NULL)
        return(false);
    if (_vna == placeholder.data())
        return(false);

    //else
    return(true);
}

void VnaTimeDomain::setHarmonicGrid(double stopFrequency_Hz, double spacing_Hz) {
    uint channel = _trace->channel();
    VnaLinearSweep sweep = _vna->channel(channel).linearSweep();

    uint maxPoints = _vna->properties().maximumPoints();
    double minFrequency_Hz = _vna->properties().minimumFrequency_Hz();

    uint totalPoints = floor(stopFrequency_Hz/spacing_Hz + 1, 1);
    spacing_Hz = stopFrequency_Hz/totalPoints;

    uint extraPoints = floor(minFrequency_Hz/spacing_Hz, 1);
    double startFrequency_Hz;
    if (totalPoints - extraPoints > maxPoints) {
        startFrequency_Hz
                = stopFrequency_Hz - spacing_Hz * (maxPoints - 1);
    }
    else {
        startFrequency_Hz
                = spacing_Hz * (extraPoints + 1);
    }

    sweep.setStart(minFrequency_Hz);
    sweep.setStop(stopFrequency_Hz);
    sweep.setStart(startFrequency_Hz);
    sweep.setSpacing(spacing_Hz);
}

// Scpi
QString VnaTimeDomain::filterTypeScpi() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toUpper());
}
QString VnaTimeDomain::responseTypeScpi() {
    _trace->select();

    QString scpi = ":CALC%1:TRAN:TIME:STIM?\n";
    scpi = scpi.arg(_trace->channel());
    return(_vna->query(scpi).toUpper());
}
QString VnaTimeDomain::toScpi(VnaWindowFunction window) {
    switch(window) {
    case REGULAR_WINDOW_FUNCTION: return("RECT");
    case HAMMING_WINDOW_FUNCTION: return("HAMM");
    case HANN_WINDOW_FUNCTION: return("HANN");
    case BOHMAN_WINDOW_FUNCTION: return("BOHM");
    case DOLPH_CHEBYCHEV_WINDOW_FUNCTION: return("DCH");
    default: return("RECT");
    }
}
VnaWindowFunction VnaTimeDomain::toWindow(QString scpi) {
    scpi = scpi.toUpper();
    if (scpi == "RECT")
        return(REGULAR_WINDOW_FUNCTION);
    if (scpi == "HAMM")
        return(HAMMING_WINDOW_FUNCTION);
    if (scpi == "HANN")
        return(HANN_WINDOW_FUNCTION);
    if (scpi ==  "BOHM")
        return(BOHMAN_WINDOW_FUNCTION);
    if (scpi == "DCH")
        return(DOLPH_CHEBYCHEV_WINDOW_FUNCTION);
    // else
        return(REGULAR_WINDOW_FUNCTION);
}
