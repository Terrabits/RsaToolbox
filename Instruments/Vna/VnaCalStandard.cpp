

#include "VnaCalStandard.h"
using namespace RsaToolbox;

#include <QTextStream>

/*!
 * \class RsaToolbox::VnaCalStandard
 * \ingroup VnaGroup
 * \brief \c %CalStandard represents an RF calibration standard and its
 *        associated properties
 *
 * A \c %CalStandard can be one or two port, of different connector
 * types and genders, it can be VNA port-specific, it can be defined
 * by a touchstone file or by a lumped-element model, and is also
 * limited to a specific frequency range.
 *
 * A \c %CalStandard can be given a label (optional) to uniquely identify
 * it.
 *
 * \note In order to prevent ambiguity, Rohde \& Schwarz VNAs
 * require standards with two ports to order connector genders and vna
 * ports a specific way. For example, a mixed gender thru standard
 * must be defined such that:
   \code
    calStandard.gender1() == MALE_GENDER;
    calStandard.gender2() == FEMALE_GENDER;
   \endcode
 * Similarly, port specific standards must list the lower-numbered port
 * as \c port1 and the higher-numbered port as \c port2. While CalStandard
 * does not enforce this, failure to abide by these guidelines will cause
 * instrument errors when using the RsaToolbox::Vna CalKit interface.
 *
 * For a list of supported standard types, see RsaToolbox::CalStandardType.
 *
 * \sa RsaToolbox::CalStandardType, Connector, Vna::CalKit(), Vna::Calibration
 */

/*!
 * \brief Default constructor
 *
 * This constructor provides an uninitialized CalStandard object.
 * This object is of type RsaToolbox::UNKNOWN_STANDARD_TYPE. All
 * properties of the resulting object must be set after
 * construction.
 * \sa setType(), setConnector(), setPort()
 */
VnaCalStandard::VnaCalStandard() {
    clear();
}

/*!
 * \brief Constructor for single-port calibration standard
 *
 * This constructor creates a single-port %CalStandard object with
 * \c connector type and gender. The properties of the \c type
 * standard are uninitialized and must be set afterward. See
 * \c setTouchstoneFile() or one of the set model
 * functions such as \c setOpenModel().
 *
 * The following standards are single port:
   <tt><br>
    RsaToolbox::OPEN_STANDARD_TYPE<br>
    RsaToolbox::SHORT_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT2_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT3_STANDARD_TYPE<br>
    RsaToolbox::MATCH_STANDARD_TYPE<br>
    RsaToolbox::SLIDING_MATCH_STANDARD_TYPE<br>
    RsaToolbox::REFLECT_STANDARD_TYPE<br>
    </tt>
 *
 * \param type Type of calibration standard
 * \param connector Connector type and gender
 * \sa CalStandard::CalStandard(CalStandardType type, uint port)
 */
VnaCalStandard::VnaCalStandard(Type type, Connector connector) {
    clear();
    _type = type;
    _connector1 = connector;
}

/*!
 * \brief Constructor for port-specific single-port calibration standard
 *
 * This constructor creates a single-port %CalStandard object that
 * can be used only with VNA port \c port. The properties of the
 * \c type standard are uninitialized and must be set afterward.
 * See \c setTouchstoneFile() or one of the set model
 * functions such as \c setOpenModel().
 *
 * The following standards are single port:
   <tt><br>
    RsaToolbox::OPEN_STANDARD_TYPE<br>
    RsaToolbox::SHORT_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT2_STANDARD_TYPE<br>
    RsaToolbox::OFFSET_SHORT3_STANDARD_TYPE<br>
    RsaToolbox::MATCH_STANDARD_TYPE<br>
    RsaToolbox::SLIDING_MATCH_STANDARD_TYPE<br>
    RsaToolbox::REFLECT_STANDARD_TYPE<br>
    </tt>
 *
 * \param type Type of calibration standard
 * \param port Intended VNA port
 * \sa CalStandard::CalStandard(CalStandardType type, Connector connector)
 */
VnaCalStandard::VnaCalStandard(Type type, uint port) {
    clear();
    _type = type;
    _port1 = port;
}

/*!
 * \brief Constructor for a two-port calibration standard
 *
 * This constructor creates a two-port %CalStandard object with
 * connectors \c connector1 and \c connector2. The properties of the
 * \c type standard are uninitialized and must be set afterward.
 * See \c setTouchstoneFile() or one of the set model
 * functions such as \c setThruModel().
 *
 * The following standards are two-port:
   <tt><br>
    RsaToolbox::THRU_STANDARD_TYPE<br>
    RsaToolbox::LINE_STANDARD_TYPE<br>
    RsaToolbox::LINE2_STANDARD_TYPE<br>
    RsaToolbox::LINE3_STANDARD_TYPE<br>
    RsaToolbox::ATTENUATION_STANDARD_TYPE<br>
    RsaToolbox::SYMMETRIC_NETWORK_STANDARD_TYPE<br>
    </tt>
 *
 * \param type Two-port standard type
 * \param connector1 First connector type and gender
 * \param connector2 Second connector type and gender
 * \sa CalStandard::CalStandard(CalStandardType type, uint port1, uint port2)
 */
VnaCalStandard::VnaCalStandard(Type type, Connector connector1, Connector connector2) {
    clear();
    _type = type;
    _connector1 = connector1;
    _connector2 = connector2;
}

/*!
 * \brief Constructor for a port-specific two-port calibration standard
 *
 * This constructor creates a two-port %CalStandard object for use
 * between VNA ports \c port1 and \c port2. The properties of the
 * \c type standard are uninitialized and must be set afterward.
 * See \c setTouchstoneFile() or one of the set model
 * functions such as \c setThruModel().
 *
 * The following standards are two-port:
   <tt><br>
    RsaToolbox::THRU_STANDARD_TYPE<br>
    RsaToolbox::LINE_STANDARD_TYPE<br>
    RsaToolbox::LINE2_STANDARD_TYPE<br>
    RsaToolbox::LINE3_STANDARD_TYPE<br>
    RsaToolbox::ATTENUATION_STANDARD_TYPE<br>
    RsaToolbox::SYMMETRIC_NETWORK_STANDARD_TYPE<br>
    </tt>
 *
 * \param type Two-port standard type
 * \param port1 Intended VNA port 1 connection
 * \param port2 Intended VNA port 2 connection
 */
VnaCalStandard::VnaCalStandard(Type type, uint port1, uint port2) {
    clear();
    _type = type;
    _port1 = port1;
    _port2 = port2;
}

/*!
 * \brief Copy constructor
 * \param other Standard to copy
 */
VnaCalStandard::VnaCalStandard(const VnaCalStandard &other) :
    _type(other._type),
    _label(other._label),
    _port1(other._port1),
    _connector1(other._connector1),
    _port2(other._port2),
    _connector2(other._connector2),
    _isTouchstone(other._isTouchstone),
    _touchstone(other._touchstone),
    _isModel(other._isModel),
    _model(other._model)
{

}

/*!
 * \brief Generates a user-friendly textualization of \c this
 *
 * An example is given below:
   \code
    Connector male35mm(mm_3_5_CONNECTOR, MALE_GENDER);
    CalStandard open(OPEN_STANDARD_TYPE, male35mm);
    open.displayText(); // "Open 3.5 mm Male"
   \endcode
 *
 * \return User-friendly textualization
 * \sa displayType()
 */
QString VnaCalStandard::displayText() const {
    QString text;
    QTextStream stream(&text);
    stream << displayType() << " ";
    if (isPortSpecific()) {
        if (isSinglePort())
            stream << "(P" << _port1 << ")";
        else
            stream << "(P" << _port1
                   << "P" << _port2 << ")";
    }
    else {
        if (isSinglePort())
            stream << _connector1.displayText();
        else
            stream << _connector1.displayText() << "-"
                   << _connector2.displayText();
    }
    stream.flush();
    return(text);
}

/*!
 * \brief Generates a user-friendly textualization of
 * \c this calibration standard type
 *
 * An example is given below:
   \code
    Connector male35mm(mm_3_5_CONNECTOR, MALE_GENDER);
    CalStandard open(OPEN_STANDARD_TYPE, male35mm);
    open.displayType(); // "Open"
   \endcode
 *
 * \return User-friendly textualization of \c type()
 * \sa type(), displayText()
 */
QString VnaCalStandard::displayType() const {
    switch(_type) {
    case Type::Open:
        return("Open");
    case Type::Short:
        return("Short");
    case Type::Match:
        return("Match");
    case Type::Thru:
        return("Thru");
    case Type::OffsetShort1:
        return("Offset Short 1");
    case Type::OffsetShort2:
        return("Offset Short 2");
    case Type::OffsetShort3:
        return("Offset Short 3");
    case Type::SlidingMatch:
        return("Sliding Match");
    case Type::Reflect:
        return("Reflection");
    case Type::Line1:
        return("Line");
    case Type::Line2:
        return("Line 2");
    case Type::Line3:
        return("Line 3");
    case Type::Attenuation:
        return("Attenuation");
    case Type::SymmetricNetwork:
        return("Symmetric Network");
    default:
        return("Unknown Standard");
    }
}

/*!
 * \brief Compares type of \c this to \c type for equality
 * \param type Type to compare to
 * \return \c true if \c this is a standard of type \c type,
 * returns \c false otherwise
 */
bool VnaCalStandard::isType(Type type) const {
    return(_type == type);
}

/*!
 * \brief Compares type of \c this to \c type for inequality
 * \param type Type to compare to
 * \return \c true if \c this is not a standard of type \c type,
 * returns \c false otherwise
 */
bool VnaCalStandard::isNotType(Type type) const {
    return(!isType(type));
}

/*!
 * \brief Tests gender of single-port calibration standard
 * \param gender Gender to compare to
 * \return \c true if \c this is a single-port standard of
 * gender \c gender, returns \c false otherwise
 */
bool VnaCalStandard::isGender(Connector::Gender gender) const {
    if (isPortSpecific())
        return false;
    else
        return(isSinglePort() && _connector1.gender() == gender);
}

/*!
 * \brief Tests gender of two-port calibration standard
 * \param gender1
 * \param gender2
 * \return \c true if \c this is a two-port standard of
 * genders \c gender1 and \c gender2, returns \c false otherwise
 */
bool VnaCalStandard::isGender(Connector::Gender gender1, Connector::Gender gender2) const {
    if(isSinglePort() || isPortSpecific())
        return false;

    if (_connector1.isGender(gender1) && _connector2.isGender(gender2))
        return true;
    if (_connector1.isGender(gender2) && _connector2.isGender(gender1))
        return true;


    return false;
}

/*!
 * \brief Tests for male gender single-port calibration standard
 * \return \c true if male, single-port calibration standard,
 * \c false otherwise
 */
bool VnaCalStandard::isMale() const {
    return(isSinglePort() && isNotPortSpecific() && isGender(Connector::Gender::Male));
}

/*!
 * \brief Tests for female gender single-port calibration standard
 * \return \c true if female, single-port calibration standard,
 * \c false otherwise
 */
bool VnaCalStandard::isFemale() const {
    return(isSinglePort() && isNotPortSpecific() && isGender(Connector::Gender::Female));
}

/*!
 * \brief Tests for a port-specific calibration standard
 * \return \c true if calibration standard is port-specific,
 * \c false otherwise
 */
bool VnaCalStandard::isPortSpecific() const {
    if (isSinglePort() && _port1 != 0)
        return true;

    if (isTwoPort() && _port1 != 0 && _port2 != 0)
        return true;

    //else
    return false;
}

/*!
 * \brief Tests for a single-port calibration standard for VNA port \c port
 * \return \c true if calibration standard is single-port and specific
 * to VNA port \c port, \c false otherwise
 */
bool VnaCalStandard::isPortSpecific(uint port) const {
    if (isSinglePort() && _port1 == port)
        return true;

    //else
    return false;
}

/*!
 * \brief Tests for a two-port calibration standard for VNA ports
 * \c port1 and \c port2
 *
 * \return \c true if calibration standard is two-port and specific
 * to VNA ports \c port1 and \c port2, \c false otherwise
 */
bool VnaCalStandard::isPortSpecific(uint port1, uint port2) const {
    if (!isTwoPort() || !isPortSpecific())
        return false;


    if (_port1 == port1 && _port2 == port2)
        return true;
    if (_port1 == port2 && _port2 == port1)
        return true;

    return false;
}

/*!
 * \brief Tests for a non-port-specific calibration standard
 * \return \c true if calibration standard is not
 * port-specific, \c false otherwise
 */
bool VnaCalStandard::isNotPortSpecific() const {
    return(!isPortSpecific());
}

/*!
 * \brief Tests for a single-port calibration standard
 * \return \c true if calibration standard is single-port,
 * \c false otherwise
 */
bool VnaCalStandard::isSinglePort() const {
    return isSinglePort(_type);
}
bool VnaCalStandard::isSinglePort(Type type) {
    return (type != Type::Unknown)
            && !isTwoPort(type);
}

/*!
 * \brief Tests for a two-port calibration standard
 * \return \c true if calibration standard is two-port,
 * \c false otherwise
 */
bool VnaCalStandard::isTwoPort() const {
    return isTwoPort(_type);
}
bool VnaCalStandard::isTwoPort(Type type) {
    switch(type) {
    case Type::Thru:
    case Type::Line1:
    case Type::Line2:
    case Type::Line3:
    case Type::Attenuation:
    case Type::SymmetricNetwork:
    case Type::Isolation:
        return true;
    default:
        return false;
    }
}

/*!
 * \brief Compares \c this standard to \c other for equality
 *
 * Two standards are considered to be the same if: <br>
 * <tt>They are of the same type<br>
 * They have the same connections (either port-specific or
 * connector type)</tt>
 *
 * \param other Standard to compare
 * \return \c true if the standards are the same type,
 * \c false otherwise
 */
bool VnaCalStandard::isSameStandardAs(VnaCalStandard other) const {
    if (isNotType(other.type()))
        return false;

    if (isSinglePort()) {
        if (other.isTwoPort())
            return false;

        if (isPortSpecific()) {
            if (other.isNotPortSpecific())
                return false;
            if (port() != other.port())
                return false;
        }
        else {
            if (other.isPortSpecific())
                return false;
            if (gender() != other.gender())
                return false;
        }
    }
    else {
        if (other.isSinglePort())
            return false;

        if (isPortSpecific()) {
            if (other.isNotPortSpecific())
                return false;
            if (other.isPortSpecific(port1(), port2()) == false)
                return false;
        }
        else {
            if (other.isPortSpecific())
                return false;
            if (other.isGender(gender1(), gender2()) == false)
                return false;
        }
    }

    // else
    return true;
}

/*!
 * \brief Tests for an open calibration standard
 * \return \c true if is an open standard, \c false otherwise
 */
bool VnaCalStandard::isOpen() const {
    return(isType(Type::Open));
}

/*!
 * \brief Tests for an open calibration standard that
 * is specific to VNA port \c port
 * \param port VNA port
 * \return true if is a \c port -specific open standard,
 * \c false otherwise
 */
bool VnaCalStandard::isOpen(uint port) const {
    return(isOpen() && isPortSpecific(port));
}

/*!
 * \brief Tests for a male open calibration standard
 * \return \c true if is a male open standard, false otherwise
 */
bool VnaCalStandard::isMaleOpen() const {
    return(isOpen() && isMale());
}

/*!
 * \brief Tests for a female open calibration standard
 * \return \c true if is a female open standard, false otherwise
 */
bool VnaCalStandard::isFemaleOpen() const {
    return(isOpen() && isFemale());
}

/*!
 * \brief Tests for a short calibration standard
 * \return \c true if is a short standard, false otherwise
 */
bool VnaCalStandard::isShort() const {
    return(isType(Type::Short));
}

/*!
 * \brief Tests for a short calibration standard that
 * is specific to VNA port \c port
 * \param port VNA port
 * \return true if is a \c port -specific short standard,
 * \c false otherwise
 */
bool VnaCalStandard::isShort(uint port) const {
    return(isShort() && isPortSpecific(port));
}

/*!
 * \brief Tests for a male short calibration standard
 * \return \c true if is a male short standard, false otherwise
 */
bool VnaCalStandard::isMaleShort() const {
    return(isShort() && isMale());
}

/*!
 * \brief Tests for a female short calibration standard
 * \return \c true if is a female short standard, false otherwise
 */
bool VnaCalStandard::isFemaleShort() const {
    return(isShort() && isFemale());
}

bool VnaCalStandard::isOffsetShort1() const {
    return isType(Type::OffsetShort1);
}
bool VnaCalStandard::isMaleOffsetShort1() const {
    return isOffsetShort1() && isMale();
}
bool VnaCalStandard::isFemaleOffsetShort1() const {
    return isOffsetShort1() && isFemale();
}

bool VnaCalStandard::isOffsetShort2() const {
    return isType(Type::OffsetShort2);
}
bool VnaCalStandard::isMaleOffsetShort2() const {
    return isOffsetShort2() && isMale();
}
bool VnaCalStandard::isFemaleOffsetShort2() const {
    return isOffsetShort2() && isFemale();
}

bool VnaCalStandard::isOffsetShort3() const {
    return isType(Type::OffsetShort3);
}
bool VnaCalStandard::isMaleOffsetShort3() const {
    return isOffsetShort3() && isMale();
}
bool VnaCalStandard::isFemaleOffsetShort3() const {
    return isOffsetShort3() && isFemale();
}

/*!
 * \brief Tests for a match calibration standard
 * \return \c true if is a match standard, false otherwise
 */
bool VnaCalStandard::isMatch() const {
    return(isType(Type::Match));
}

/*!
 * \brief Tests for a port-specific match calibration standard
 * for VNA port \c port
 * \param port
 * \return \c true if is a match standard for port \c port,
 * false otherwise
 */
bool VnaCalStandard::isMatch(uint port) const {
    return(isMatch() && isPortSpecific(port));
}

/*!
 * \brief Tests for a male match calibration standard
 * \return \c true if is a male match standard, false otherwise
 */
bool VnaCalStandard::isMaleMatch() const {
    return(isMatch() && isMale());
}

/*!
 * \brief Tests for a female match calibration standard
 * \return \c true if is a female match standard, false otherwise
 */
bool VnaCalStandard::isFemaleMatch() const {
    return(isMatch() && isFemale());
}

/*!
 * \brief Tests for a thru calibration standard
 * \return \c true if is a thru standard, false otherwise
 */
bool VnaCalStandard::isThru() const {
    return(isType(Type::Thru));
}

/*!
 * \brief Tests for a male-to-male thru calibration standard
 * \return \c true if is a male-to-male thru standard, false otherwise
 */
bool VnaCalStandard::isThruMM() const {
    return(isThru(Connector::Gender::Male, Connector::Gender::Male));
}

/*!
 * \brief Tests for a male-to-female thru calibration standard
 * \return \c true if is a male-to-female thru standard, false otherwise
 */
bool VnaCalStandard::isThruMF() const {
    return(isThru(Connector::Gender::Male, Connector::Gender::Female));
}

/*!
 * \brief Tests for a female-to-female thru calibration standard
 * \return \c true if is a female-to-female thru standard, false otherwise
 */
bool VnaCalStandard::isThruFF() const {
    return(isThru(Connector::Gender::Female, Connector::Gender::Female));
}

/*!
 * \brief Tests for a port-specific thru calibration standard
 * for VNA ports \c port1 and \c port2
 * \param port1
 * \param port2
 * \return \c true if is a thru standard for ports \c port1 and \c port2,
 * false otherwise
 */
bool VnaCalStandard::isThru(uint port1, uint port2) const {
    return(isThru() && isPortSpecific(port1, port2));
}

/*!
 * \brief Tests for a \c gender1 -to- \c gender2 thru calibration standard
 * \param gender1
 * \param gender2
 * \return \c true if is a \c gender1 -to- \c gender2 thru standard, false otherwise
 */
bool VnaCalStandard::isThru(Connector::Gender gender1, Connector::Gender gender2) const {
    return(isThru() && isGender(gender1, gender2));
}

/*!
 * \brief Indicates whether or not calibration standard is defined
 * by a touchstone file
 * \return \c true if defined by a touchstone file, \c false otherwise
 */
bool VnaCalStandard::isTouchstone() const {
    return(_isTouchstone);
}

/*!
 * \brief Indicates whether or not calibration standard is defined by
 * a lumped element model
 * \return \c true if defined by a lumped element model,
 * \c false otherwise
 */
bool VnaCalStandard::isModel() const {
    return(_isModel);
}

/*!
 * \brief Compares the lumped element model of two standards
 *
 * If the standards being compared are of a different type,
 * or either standard is not defined by a lumped element model,
 * this method returns \c false.
 *
 * If the standards are of the same type and are both defined by
 * model, the model parameters are compared for equality and
 * the result is returned.
 *
 * \param other Calibration standard to compare to
 * \return \c true if the two standards are the same type and
 * lumped element model, \c false otherwise
 */
bool VnaCalStandard::isSameModel(const VnaCalStandard &other) const {
    if (!isType(other.type()))
        return false;
    if (!isModel() || !other.isModel())
        return false;
    if (_model != other.model())
        return false;

    return true;
}

/*!
 * \brief Returns the \c type of the calibration standard
 * \return standard type
 */
VnaCalStandard::Type VnaCalStandard::type() const {
    return(_type);
}

/*!
 * \brief Returns the minimum frequency of the calibration
 * standard
 * \return Minimum frequency in Hertz
 */
double VnaCalStandard::minimumFrequency_Hz() const {
    return _model.minimumFrequency_Hz;
}

/*!
 * \brief Returns the maximum frequency of the calibration
 * standard
 * \return Maximum frequency in Hertz
 */
double VnaCalStandard::maximumFrequency_Hz() const {
    return _model.maximumFrequency_Hz;
}

/*!
 * \brief Returns the VNA port of a single-port,
 * port-specific calibration standard
 * \return VNA port
 */
uint VnaCalStandard::port() const {
    return(_port1);
}

/*!
 * \brief Returns VNA port \c port1 of a two-port,
 * port-specific calibration standard
 * \return VNA port 1
 */
uint VnaCalStandard::port1() const {
    return(_port1);
}

/*!
 * \brief Returns VNA port \c port2 of a two-port,
 * port-specific calibration standard
 * \return VNA port 2
 */
uint VnaCalStandard::port2() const {
    return(_port2);
}

/*!
 * \brief Returns the connector of a single-port
 * calibration standard
 * \return %Connector
 */
Connector &VnaCalStandard::connector() {
    return _connector1;
}

/*!
 * \brief Returns \c connector1 of a two-port,
 * calibration standard
 * \return %Connector 1
 */
Connector &VnaCalStandard::connector1() {
    return _connector1;
}

/*!
 * \brief Returns \c connector2 of a two-port,
 * calibration standard
 * \return %Connector 2
 */
Connector &VnaCalStandard::connector2() {
    return _connector2;
}

/*!
 * \brief Returns the connector gender of a single-port
 * calibration standard
 * \return Gender
 */
Connector::Gender VnaCalStandard::gender() const {
    return(_connector1.gender());
}

/*!
 * \brief Returns the gender of \c connector1 of a two-port,
 * calibration standard
 * \return Gender of connector 1
 */
Connector::Gender VnaCalStandard::gender1() const {
    return(_connector1.gender());
}

/*!
 * \brief Returns the gender of \c connector2 of a two-port,
 * calibration standard
 * \return Gender of connector 2
 */
Connector::Gender VnaCalStandard::gender2() const {
    return(_connector2.gender());
}

/*!
 * \brief Returns the label of the calibration standard
 * \return Label
 */
QString VnaCalStandard::label() const {
    return(_label);
}

/*!
 * \brief Returns the path of the touchstone file
 * that defines the calibration standard
 * \return Path to touchstone file
 */
QString VnaCalStandard::touchstone() const {
    return(_touchstone);
}

/*!
 * \brief Sets the calibration standard type
 * \param type Calibration type
 * \sa RsaToolbox::CalStandardType
 */
void VnaCalStandard::setType(Type type) {
    _type = type;
}

/*!
 * \brief Sets a specific VNA port for a single-port calibration
 * standard
 * \param port VNA port
 */
void VnaCalStandard::setPort(uint port) {
    _port1 = port;
}

/*!
 * \brief Sets the Vna ports for a port-specific two-port
 * calibration standard
 *
 * \note The Vna requires a specific port order for two-port
 * calibration standards in order to prevent confusion. For
 * example, a Thru standard specific to Vna ports 3 and 4
 * will always consider Vna port 3 the "first port" (port1)
 * of the calibration standard.  This is automatically enforced
 * in a \c %VnaCalStandard object; reordering occurs
 * as necessary after a call to \c %setConnector.
 *
 * \param port1 The Vna port used with port 1 of the calibration standard
 * \param port2 The Vna port used with port 2 of the calibration standard
 */
void VnaCalStandard::setPorts(uint port1, uint port2) {
    _port1 = port1;
    _port2 = port2;
    sort();
}

/*!
 * \brief Sets the connector for a single-port calibration standard
 * \param connector Connector type and gender
 */
void VnaCalStandard::setConnector(Connector connector) {
    _connector1 = connector;
    _port1 = 0;
}

/*!
 * \brief Sets the connectors for a two-port calibration standard
 *
 * \note The Vna requires a specific gender order for two-port
 * calibration standards in order to prevent confusion. For
 * example, a mixed gender thru standard is always written
 * as Male-Female. This is automatically enforced in a
 * \c %VnaCalStandard object; reordering occurs
 * as necessary after a call to \c %setConnector.
 *
 * \param connector1 Connector type and gender of port1
 * \param connector2 Connector type and gender of port2
 */
void VnaCalStandard::setConnectors(Connector connector1, Connector connector2) {
    setConnector1(connector1);
    setConnector2(connector2);
    sort();

}

/*!
 * \brief Sets the label of the calibration standard
 *
 * The label is usually a unique identifier string, such as
 * the serial number of the standard.
 *
 * \param label Calibration standard label
 */
void VnaCalStandard::setLabel(QString label) {
    _label = label;
}

/*!
 * \brief Sets the path to the touchstone file that defines
 * the calibration standard to \c path.
 * \param path Path to the touchstone file
 */
void VnaCalStandard::setTouchstoneFile(QString path) {
    _isTouchstone = true;
    _touchstone = path;
}

VnaStandardModel &VnaCalStandard::model() {
    return _model;
}
VnaStandardModel VnaCalStandard::model() const {
    return _model;
}
void VnaCalStandard::setModel(const VnaStandardModel &model) {
    _isTouchstone = false;
    _isModel = true;
    _model = model;
}

/*!
 * \brief Resets the calibration standard to the default state.
 *
 * The resulting standard is of type UNKNOWN_STANDARD_TYPE. All
 * settings are lost.
 *
 */
void VnaCalStandard::clear() {
    _type = Type::Unknown;
    _label.clear();

    _port1 = 0;
    _port2 = 0;
    _connector1 = Connector();
    _connector2 = Connector();

    _isModel = false;
    _model = VnaStandardModel();

    _isTouchstone = false;
    _touchstone.clear();
}

/*!
 * \brief Clears port-specific settings
 */
void VnaCalStandard::clearPorts() {
    _port1 = 0;
    _port2 = 0;
}

/*!
 * \brief Clears connector settings
 */
void VnaCalStandard::clearConnectors() {
    _port1 = 0;
    _connector1 = Connector();

    _port2 = 0;
    _connector2 = Connector();
}

/*!
 * \brief Sets the settings of the object on the left-hand side
 * of the = operator to that of the object on the right-hand side
 * \param other Object to take settings from
 */
void VnaCalStandard::operator =(const VnaCalStandard &other) {
    _type = other._type;
    _label = other._label;

    _port1 = other._port1;
    _connector1 = other._connector1;

    _port2 = other._port2;
    _connector2 = other._connector2;

    _isTouchstone = other._isTouchstone;
    _touchstone = other._touchstone;

    _isModel = other._isModel;
    _model = other._model;
}

QStringList VnaCalStandard::displayText(const QVector<VnaCalStandard> &standards) {
    QStringList displays;
    foreach (VnaCalStandard std, standards) {
        displays.append(std.displayText());
    }
    return(displays);
}

// Private
void VnaCalStandard::setConnector1(Connector connector1) {
    _connector1 = connector1;
    _port1 = 0;
}

void VnaCalStandard::setConnector2(Connector connector2) {
    _connector2 = connector2;
    _port2 = 0;
}

void VnaCalStandard::sort() {
    if (isSinglePort())
        return;

    if (isNotPortSpecific()) {
        RsaToolbox::sort(_connector1, _connector2);
    }
    else {
        RsaToolbox::sort(_port1, _port2);
    }
}

/*!
 * \relates VnaCalStandard
 * \brief Sorts two connectors by gender
 *
 * \note The Vna requires a specific gender order for two-port
 * calibration standards in order to prevent confusion. For
 * example, a mixed gender thru standard is always written
 * as Male-Female.
 *
 * \param connector1
 * \param connector2
 */
void RsaToolbox::sort(Connector &connector1, Connector &connector2) {
    if (connector2.isMale() && connector1.isNotMale()) {
        Connector temp = connector1;
        connector1 = connector2;
        connector2 = temp;
    }
    else if (connector1.isFemale() && connector2.isNotFemale()) {
        Connector temp = connector1;
        connector1 = connector2;
        connector2 = temp;
    }
}

/*!
 * \relates VnaCalStandard
 * \brief Sorts two connector genders
 *
 * \note The Vna requires a specific gender order for two-port
 * calibration standards in order to prevent confusion. For
 * example, a mixed gender thru standard is always written
 * as Male-Female.
 *
 * \param gender1
 * \param gender2
 */
void RsaToolbox::sort(Connector::Gender &gender1, Connector::Gender &gender2) {
    if (gender2 == Connector::Gender::Male && gender2 != Connector::Gender::Male) {
        Connector::Gender temp = gender1;
        gender1 = gender2;
        gender2 = temp;
    }
    else if (gender1 == Connector::Gender::Female && gender2 != Connector::Gender::Female) {
        Connector::Gender temp = gender1;
        gender1 = gender2;
        gender2 = temp;
    }
}

/*!
 * \relates VnaCalStandard
 * \brief Sorts two connector genders
 *
 * \note The Vna requires a specific port order for two-port
 * calibration standards in order to prevent confusion. For
 * example, a Thru standard specific to Vna ports 3 and 4
 * will always consider Vna port 3 the "first port" (port1)
 * of the calibration standard.
 *
 * \param port1
 * \param port2
 */
void RsaToolbox::sort(uint &port1, uint &port2) {
    if (port1 > port2) {
        uint temp = port1;
        port1 = port2;
        port2 = temp;
    }
}

/*!
 * \relates VnaCalStandard
 * \brief Equality operator for CalStandard objects
 *
 * The == operator compares each property of the %CalStandard objects
 * for equality. If any property is different, this function returns
 * \c false. If all properties are identical, this function returns
 * \c true.
 *
 * \param right Right-hand object
 * \param left Left-hand object
 * \return \c true if objects are equal; \c false otherwise
 * \sa RsaToolbox::operator!=(const CalStandard &right, const CalStandard &left)
 */
bool RsaToolbox::operator==(const VnaCalStandard &right, const VnaCalStandard &left) {
    if (right.isSameStandardAs(left) == false)
        return false;

    if (right.isTouchstone() != left.isTouchstone())
        return false;

    if (left.isModel() != left.isModel())
        return false;

    if (right.model() != left.model())
        return false;

    return true;
}

/*!
 * \relates VnaCalStandard
 * \brief Inequality operator for CalStandard objects
 *
 * The != operator compares each property of the %CalStandard objects
 * for inequality. If any property is different, this function returns
 * \c true. If all properties are identical, this function returns
 * \c false.
 *
 * \param right Right-hand object
 * \param left Left-hand object
 * \return \c true if objects are unequal; \c false otherwise
 * \sa RsaToolbox::operator==(const CalStandard &right, const CalStandard &left)
 */
bool RsaToolbox::operator!=(const VnaCalStandard &right, const VnaCalStandard &left) {
    return(!(right == left));
}

