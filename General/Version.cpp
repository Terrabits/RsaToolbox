#include "Version.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QStringList>
#include <QVariant>


Version::Version() :
    _major(0),
    _minor(0),
    _bug(0),
    _build(0)
{

}
Version::Version(const QString &version) :
    _major(0),
    _minor(0),
    _bug(0),
    _build(0)
{
    QStringList parts = version.split('.');
    if (parts.isEmpty())
        return;
    if (parts.size() > 4)
        return;

    _major = parts.first().toUInt();
    if (parts.size() == 1)
        return;

    _minor = parts[1].toUInt();
    if (parts.size() == 2)
        return;

    _bug = parts[2].toUInt();
    if (parts.size() == 3)
        return;

    _build = parts[3].toUInt();
}

Version::~Version()
{

}

uint Version::major() const {
    return _major;
}
void Version::setMajor(uint number) {
    _major = number;
}

uint Version::minor() const {
    return _minor;
}
void Version::setMinor(uint number) {
    _minor = number;
}

uint Version::bug() const {
    return _bug;
}
void Version::setBug(uint number) {
    _bug = number;
}

uint Version::build() const {
    return _build;
}
void Version::setBuild(uint number) {
    _build = number;
}

QString Version::toString() const {
    QString v = QVariant(_major).toString();
    v += ".";
    v += QVariant(_minor).toString();

    if (_build != 0) {
        v += ".";
        v += QVariant(_bug).toString();
        v += ".";
        v += QVariant(_build).toString();
        return v;
    }

    if (_bug != 0) {
        v += ".";
        v += QVariant(_bug).toString();
        return v;
    }

    // Else
    return v;
}

bool operator==(const Version &v1, const Version &v2) {
    if (v1.major() != v2.major())
        return false;
    if (v1.minor() != v2.minor())
        return false;
    if (v1.bug() != v2.bug())
        return false;
    if (v1.build() != v1.build())
        return false;

    // Else
    return true;
}
bool operator!=(const Version &v1, const Version &v2) {
    if (v1.major() != v2.major())
        return true;
    if (v1.minor() != v2.minor())
        return true;
    if (v1.bug() != v2.bug())
        return true;
    if (v1.build() != v1.build())
        return true;

    // Else
    return false;
}
bool operator<(const Version &v1, const Version &v2) {
    if (v1.major() < v2.major())
        return true;
    else if (v1.major() > v2.major())
        return false;

    if (v1.minor() < v2.minor())
        return true;
    else if (v1.minor() > v2.minor())
        return false;

    if (v1.bug() < v2.bug())
        return true;
    else if (v1.bug() > v2.bug())
        return false;

    if (v1.build() < v1.build())
        return true;
    else
        return false;
}
bool operator<=(const Version &v1, const Version &v2) {
    return !(v1 > v2);
}
bool operator>(const Version &v1, const Version &v2) {
    if (v1.major() > v2.major())
        return true;
    else if (v1.major() < v2.major())
        return false;

    if (v1.minor() > v2.minor())
        return true;
    else if (v1.minor() < v2.minor())
        return false;

    if (v1.bug() > v2.bug())
        return true;
    else if (v1.bug() < v2.bug())
        return false;

    if (v1.build() > v1.build())
        return true;
    else
        return false;
}
bool operator>=(const Version &v1, const Version &v2) {
    return !(v1 < v2);
}

