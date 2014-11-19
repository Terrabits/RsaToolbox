#include "FormattedComplex.h"


#include "General.h"
using namespace RsaToolbox;


FormattedComplex::FormattedComplex() {
    _format = ComplexFormat::RealImaginary;
    _a = _b = 0;
}
FormattedComplex::FormattedComplex(const FormattedComplex &other) {
    _format = other._format;
    _a = other._a;
    _b = other._b;
}
FormattedComplex FormattedComplex::realImaginary(double real, double imaginary) {
    FormattedComplex result;
    result._format = ComplexFormat::RealImaginary;
    result._a = real;
    result._b = imaginary;
    return result;
}
FormattedComplex FormattedComplex::dBAngle(double dB, double degrees) {
    FormattedComplex result;
    result._format = ComplexFormat::DecibelDegrees;
    result._a = dB;
    result._b = degrees;
    return result;
}
FormattedComplex FormattedComplex::magnitudeAngle(double magnitude, double degrees) {
    FormattedComplex result;
    result._format = ComplexFormat::MagnitudeDegrees;
    result._a = magnitude;
    result._b = degrees;
    return result;
}

ComplexFormat FormattedComplex::format() const {
    return _format;
}
bool FormattedComplex::isRealImaginary() const {
    return _format == ComplexFormat::RealImaginary;
}
bool FormattedComplex::isDbDegrees() const {
    return _format == ComplexFormat::DecibelDegrees;
}
bool FormattedComplex::isMagnitudeDegrees() const {
    return _format == ComplexFormat::MagnitudeDegrees;
}

double FormattedComplex::real() const {
    switch(_format) {
    case ComplexFormat::RealImaginary:
        return _a;
    default:
        return value().real();
    }
}
double FormattedComplex::imaginary() const {
    switch(_format) {
    case ComplexFormat::RealImaginary:
        return _b;
    default:
        return value().imag();
    }
}
double FormattedComplex::dB() const {
    switch(_format) {
    case ComplexFormat::DecibelDegrees:
        return _a;
    case ComplexFormat::MagnitudeDegrees:
        return toDb(_a);
    default:
        return toDb(value());
    }
}
double FormattedComplex::magnitude() const {
    switch(_format) {
    case ComplexFormat::DecibelDegrees:
        return toMagnitude(_a);
    case ComplexFormat::MagnitudeDegrees:
        return _a;
    default:
        return toMagnitude(value());
    }
}
double FormattedComplex::angle_deg() const {
    switch(_format) {
    case ComplexFormat::DecibelDegrees:
    case ComplexFormat::MagnitudeDegrees:
        return _b;
    default:
        return RsaToolbox::angle_deg(value());
    }
}
double FormattedComplex::angle_rad() const {
    switch(_format) {
    case ComplexFormat::MagnitudeDegrees:
    case ComplexFormat::DecibelDegrees:
        return radians(_b);
    default:
        return RsaToolbox::angle_rad(value());
    }
}
ComplexDouble FormattedComplex::value() const {
    switch(_format) {
    case ComplexFormat::MagnitudeDegrees:
        return ComplexDouble(_a * cos(_b * PI/180.0),
                             _a * sin(_b * PI/180.0));
    case ComplexFormat::DecibelDegrees:
        return ComplexDouble(toMagnitude(_a) * cos(_b * PI/180.0),
                             toMagnitude(_a) * sin(_b * PI/180.0));
    default:
        return ComplexDouble(_a, _b);
    }
}

FormattedComplex &FormattedComplex::operator=(const FormattedComplex &other) {
    _format = other._format;
    _a = other._a;
    _b = other._b;
    return *this;
}
bool operator==(const RsaToolbox::FormattedComplex &lft, const RsaToolbox::FormattedComplex &rt) {
    if (lft.format() != rt.format())
        return false;

    switch (lft.format()) {
    case ComplexFormat::RealImaginary:
        if (lft.real() != rt.real())
            return false;
        if (lft.imaginary() != rt.imaginary())
            return false;
        return true;

    case ComplexFormat::MagnitudeDegrees:
        if (lft.magnitude() != rt.magnitude())
            return false;
        if (lft.angle_deg() != rt.angle_deg())
            return false;
        return true;
    case ComplexFormat::DecibelDegrees:
        if (lft.dB() != rt.dB())
            return false;
        if (lft.angle_deg() != rt.angle_deg())
            return false;
        return true;

    default:
        return false;
    }
}
void FormattedComplex::write(QDataStream &stream) const {
    stream << qint32(_format);
    stream << _a;
    stream << _b;
}
QDataStream& operator<<(QDataStream &stream, const FormattedComplex &fcomplex) {
    fcomplex.write(stream);
    return stream;
}
void FormattedComplex::read(QDataStream &stream) {
    qint32 format;
    stream >> format;
    _format = ComplexFormat(format);
    stream >> _a;
    stream >> _b;
}
QDataStream& operator>>(QDataStream &stream, FormattedComplex &fcomplex) {
    fcomplex.read(stream);
    return stream;
}

