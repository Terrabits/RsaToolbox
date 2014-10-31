#ifndef FORMATTED_COMPLEX_H
#define FORMATTED_COMPLEX_H


#include "Definitions.h"


namespace RsaToolbox {

class FormattedComplex;
typedef QVector<FormattedComplex> FormattedComplexRowVector;
typedef QVector<FormattedComplexRowVector> FormattedComplexMatrix2D;
typedef QVector<FormattedComplexMatrix2D> FormattedComplexMatrix3D;

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

    FormattedComplex& operator=(const FormattedComplex &other);
    void write(QDataStream &stream) const;
    void read(QDataStream &stream);

private:
    ComplexFormat _format;
    double _a, _b;
};
}
bool operator==(const RsaToolbox::FormattedComplex &lft, const RsaToolbox::FormattedComplex &rt);
QDataStream& operator<<(QDataStream &stream, const RsaToolbox::FormattedComplex &fcomplex);
QDataStream& operator>>(QDataStream &stream, RsaToolbox::FormattedComplex &fcomplex);
Q_DECLARE_METATYPE(RsaToolbox::FormattedComplex)


#endif // FORMATTED_COMPLEX_H
