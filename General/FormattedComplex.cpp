#include "FormattedComplex.h"


#include "General.h"
using namespace RsaToolbox;


FormattedComplex::FormattedComplex() {
    _format = REAL_IMAGINARY_COMPLEX;
    _a = _b = 0;
}
FormattedComplex::FormattedComplex(const FormattedComplex &other) {
    _format = other._format;
    _a = other._a;
    _b = other._b;
}
FormattedComplex FormattedComplex::realImaginary(double real, double imaginary) {
    FormattedComplex result;
    result._format = REAL_IMAGINARY_COMPLEX;
    result._a = real;
    result._b = imaginary;
    return result;
}
FormattedComplex FormattedComplex::dBAngle(double dB, double degrees) {
    FormattedComplex result;
    result._format = DB_DEGREES_COMPLEX;
    result._a = dB;
    result._b = degrees;
    return result;
}
FormattedComplex FormattedComplex::magnitudeAngle(double magnitude, double degrees) {
    FormattedComplex result;
    result._format = MAGNITUDE_DEGREES_COMPLEX;
    result._a = magnitude;
    result._b = degrees;
    return result;
}

ComplexFormat FormattedComplex::format() const {
    return _format;
}
bool FormattedComplex::isRealImaginary() const {
    return _format == REAL_IMAGINARY_COMPLEX;
}
bool FormattedComplex::isDbDegrees() const {
    return _format == DB_DEGREES_COMPLEX;
}
bool FormattedComplex::isMagnitudeDegrees() const {
    return _format == MAGNITUDE_DEGREES_COMPLEX;
}

double FormattedComplex::real() const {
    switch(_format) {
    case REAL_IMAGINARY_COMPLEX:
        return _a;
    default:
        return value().real();
    }
}
double FormattedComplex::imaginary() const {
    switch(_format) {
    case REAL_IMAGINARY_COMPLEX:
        return _b;
    default:
        return value().imag();
    }
}
double FormattedComplex::dB() const {
    switch(_format) {
    case DB_DEGREES_COMPLEX:
        return _a;
    case MAGNITUDE_DEGREES_COMPLEX:
        return toDb(_a);
    default:
        return toDb(value());
    }
}
double FormattedComplex::magnitude() const {
    switch(_format) {
    case DB_DEGREES_COMPLEX:
        return toMagnitude(_a);
    case MAGNITUDE_DEGREES_COMPLEX:
        return _a;
    default:
        return toMagnitude(value());
    }
}
double FormattedComplex::angle_deg() const {
    switch(_format) {
    case DB_DEGREES_COMPLEX:
    case MAGNITUDE_DEGREES_COMPLEX:
        return _b;
    default:
        return RsaToolbox::angle_deg(value());
    }
}
double FormattedComplex::angle_rad() const {
    switch(_format) {
    case MAGNITUDE_DEGREES_COMPLEX:
    case DB_DEGREES_COMPLEX:
        return radians(_b);
    default:
        return RsaToolbox::angle_rad(value());
    }
}
ComplexDouble FormattedComplex::value() const {
    switch(_format) {
    case MAGNITUDE_DEGREES_COMPLEX:
        return ComplexDouble(_a * cos(_b * PI/180.0),
                             _a * sin(_b * PI/180.0));
    case DB_DEGREES_COMPLEX:
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
