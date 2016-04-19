#ifndef VERSION_H
#define VERSION_H


// Qt
#include <Qt>
#include <QString>


namespace RsaToolbox {

class Version
{
public:
    Version();
    Version(const QString &version);
    ~Version();

    uint major() const;
    void setMajor(uint number);

    uint minor() const;
    void setMinor(uint number);

    uint bug() const;
    void setBug(uint number);

    uint build() const;
    void setBuild(uint number);

    QString toString() const;

private:
    uint _major;
    uint _minor;
    uint _bug;
    uint _build;
};
}

bool operator==(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);
bool operator!=(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);
bool operator<(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);
bool operator<=(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);
bool operator>(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);
bool operator>=(const RsaToolbox::Version &v1, const RsaToolbox::Version &v2);


#endif // VERSION_H
