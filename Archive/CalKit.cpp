

#include "CalKit.h"
using namespace RsaToolbox;


CalibrationKit::CalibrationKit() {
    // De nada?
}
CalibrationKit::CalibrationKit(QString name) {
    _name = name;
}
CalibrationKit::CalibrationKit(QString name, QVector<CalStandard> standards) {
    _name = name;
    _standards = standards;
}

bool CalibrationKit::hasStandard(CalStandardType type, Connector connector) {
    CalStandard std = CalStandard(type, connector);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(true);
    }

    // else
    return(false);
}
bool CalibrationKit::hasStandard(CalStandardType type, uint port) {
    CalStandard std = CalStandard(type, port);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(true);
    }

    // else
    return(false);
}
bool CalibrationKit::hasStandard(CalStandardType type, Connector connector1, Connector connector2) {
    CalStandard std = CalStandard(type, connector1, connector2);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(true);
    }

    // else
    return(false);
}
bool CalibrationKit::hasStandard(CalStandardType type, uint port1, uint port2) {
    CalStandard std = CalStandard(type, port1, port2);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(true);
    }

    // else
    return(false);
}


QString CalibrationKit::name() {
    return(_name);
}
QString CalibrationKit::label() {
    return(_label);
}

double CalibrationKit::minimumFrequency_Hz() {
    double min_freq = 0;
    foreach (CalStandard std, _standards) {
        if (std.minimumFrequency_Hz() > min_freq)
            min_freq = std.minimumFrequency_Hz();
    }
    return(min_freq);
}
double CalibrationKit::maximumFrequency_Hz() {
    double max_freq = 1E30;
    foreach (CalStandard std, _standards) {
        if (std.maximumFrequency_Hz() < max_freq)
            max_freq = std.maximumFrequency_Hz();
    }
    return(max_freq);
}

QVector<CalStandard>& CalibrationKit::standards() {
    return(_standards);
}

CalStandard& CalibrationKit::standard(CalStandardType type, Connector connector) {
    CalStandard std = CalStandard(type, connector);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(_standards[i]);
    }

    // else
    return(CalStandard());
}
CalStandard& CalibrationKit::standard(CalStandardType type, uint port) {
    CalStandard std = CalStandard(type, port);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(_standards[i]);
    }

    // else
    return(CalStandard());
}
CalStandard& CalibrationKit::standard(CalStandardType type, Connector connector1, Connector connector2) {
    CalStandard std = CalStandard(type, connector1, connector2);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(_standards[i]);
    }

    // else
    return(CalStandard());
}
CalStandard& CalibrationKit::standard(CalStandardType type, uint port1, uint port2) {
    CalStandard std = CalStandard(type, port1, port2);
    int num_stds = _standards.size();
    for (int i = 0; i < num_stds; i++) {
        if (_standards[i].isSameStandardAs(std))
            return(_standards[i]);
    }

    // else
    return(CalStandard());
}

void CalibrationKit::AddStandard(CalStandard standard) {
    _standards.append(standard);
}
void CalibrationKit::ClearStandards() {
    _standards.clear();
}

void CalibrationKit::operator =(const CalibrationKit &other) {
    _name = other._name;
    _label = other._label;
    int num_stds = other._standards.size();
    _standards.resize(num_stds);
    for (int i = 0; i < num_stds; i++) {
        _standards[i] = other._standards[i];
    }
}
