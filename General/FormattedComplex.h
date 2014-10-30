#ifndef FORMATTED_COMPLEX_H
#define FORMATTED_COMPLEX_H


#include "Definitions.h"


namespace RsaToolbox {

class FormattedComplex;
typedef QVector<FormattedComplex> QFormattedComplexRowVector;
typedef QVector<QFormattedComplexRowVector> QFormattedComplexMatrix2D;
typedef QVector<QFormattedComplexMatrix2D> QFormattedComplexMatrix3D;

class FormattedComplex {
public:
    FormattedComplex();
    FormattedComplex(const FormattedComplex &other);

    static FormattedComplex realImaginary(double real, double imaginary);
    static FormattedComplex dBAngle(double dB, double degrees);
    static FormattedComplex magnitudeAngle(double magnitude, double degrees);

    ComplexFormat format() const;
    bool isRealImaginary() const;
    bool isDbDegrees() const;
    bool isMagnitudeDegrees() const;

    double real() const;
    double imaginary() const;
    double dB() const;
    double magnitude() const;
    double angle_deg() const;
    double angle_rad() const;
    ComplexDouble value() const;

    FormattedComplex &operator=(const FormattedComplex &other);

private:
    ComplexFormat _format;
    double _a, _b;
};

}


#endif // FORMATTED_COMPLEX_H
