

#include "Connector.h"
using namespace RsaToolbox;

/*!
 * \class RsaToolbox::Connector
 * \brief Handles connector type and gender
 *
 * Rohde \& Schwarz Vector Network Analyzers come with a default
 * list of connector types. In addition, user-defined connector
 * types are possible. The \c Connector class enables both
 * system- and user-defined connector types to be handled by
 * the same code without special treatment.
 *
 * Convenience functions such as \c isMale() and
 * \c getMatingConnector() are provided for processing
 * connectors.
 *
 * Several display functions are provided for generating
 * user-friendly text representations such as \c displayType(),
 * \c displayGender() and \c displayText().
 *
 * Several static functions are also provided for handling a
 * QVector of Connector objects.
 * \sa RsaToolbox::Connector::Type, RsaToolbox::ConnectorGender
 */

/*!
 * \brief Default constructor
 *
 * The default constructor creates an object of
 * \c RsaToolbox::UNKNOWN_CONNECTOR type and
 * \c RsaToolbox::NEUTRAL_GENDER.
 */
Connector::Connector() :
    _gender(Gender::Neutral),
    _mode(Mode::Tem),
    _permittivity(1.0),
    _impedance_Ohms(50.0),
    _cutoffFrequency_Hz(0.0)
{

}

/*!
 * \brief Copy constructor
 *
 * Creates a \c %Connector object with the same properties
 * as \c other.
 *
 *
 * \param other %Connector to copy
 */
Connector::Connector(const Connector &other) :
    _type(other._type),
    _gender(other._gender),
    _mode(other._mode),
    _permittivity(other._permittivity),
    _impedance_Ohms(other._impedance_Ohms),
    _cutoffFrequency_Hz(other._cutoffFrequency_Hz)
{

}

/*!
 * \brief Constructor for a connector with properties
 * \c type and \c gender
 *
 * \note For a connector with one of the system-defined
 * connector types, see the
 * \c Connector::Connector(Type type, ConnectorGender gender)
 * constructor.
 *
 * \param customType User-defined connector type
 * \param gender Connector gender
 */
Connector::Connector(QString type, Gender gender) :
    _type(type),
    _gender(gender),
    _mode(Mode::Tem),
    _permittivity(1.0),
    _impedance_Ohms(50.0),
    _cutoffFrequency_Hz(0.0)
{

}

bool Connector::isUndefined() const {
    return _type.isEmpty();
}

/*!
 * \brief Creates a user-friendly text display of the
 * \c Connector properties
 *
 * For a female 3.5 mm connector the result is:
 * <tt> "3.5 mm Female" </tt>
 *
 * \return User-friendly text representation
 */
QString Connector::displayText() const {
    if (isUndefined()) {
        return "Undefined connector";
    }
    else {
        return(_type + " " + displayGender());
    }
}

/*!
 * \brief Returns the connector gender as user-friendly text
 *
 * Possible return values are:
   <tt><br>
    "Male"<br>
    "Female"<br>
    "Neutral"<br>
   </tt>
 *
 * \return Gender as text
 */
QString Connector::displayGender() const {
    switch(_gender) {
    case Gender::   Male: return("Male");
    case Gender:: Female: return("Female");
    case Gender::Neutral: return("Neutral");
                 default: return("Unknown Gender");
    }
}

/*!
 * \brief Returns a single-character gender abbreviation
 *
 * Possible return values are <tt> "M", "F" or "N"</tt> for
 * male-, female- and neutral-gender connectors, respectively.
 *
 * \return Gender abbreviation
 */
QString Connector::genderAbbreviation() const {
    switch(_gender) {
    case Gender::Male: return("M");
    case Gender::Female: return("F");
    case Gender::Neutral: return("N");
    default: return("?");
    }
}

/*!
 * \brief Performs a connector type comparison with \c other
 *
 * Returns true if \c this and \c other are the same
 * connector type. For user-defined connector types, the
 * string representing the type are compared.
 *
 * \note User-defined types are case-sensitive.
 *
 * \param other Connector to compare
 * \return Result of connector type comparison
 * \sa isNotType()
 */
bool Connector::isType(const Connector &other) const {
    return _type.toLower() == other._type.toLower();
}

/*!
 * \brief Compares gender with \c gender for equality
 * \param gender Gender to compare
 * \return  Result of gender comparison
 */
bool Connector::isGender(Gender gender) const {
    return _gender == gender;
}

/*!
 * \brief Determines if connector is male gender
 * \return \c true if connector is male.
 */
bool Connector::isMale() const {
    return _gender == Gender::Male;
}

/*!
 * \brief Determines if connector is female gender
 * \return \c true if connector is female.
 */
bool Connector::isFemale() const {
    return _gender == Gender::Female;
}

/*!
 * \brief Determines if connector type is gender-specifc
 * \return \c true if connector type has specific genders
 */
bool Connector::isGendered() const {
    return _gender != Gender::Neutral;
}

/*!
 * \brief Retrieves the connector type of a user-defined connector
 *
 * For a system-defined connector type, the result is an empty
 * string.
 *
 * \return User-defined connector type string, or "" for system-defined connector types.
 * \sa type()
 */
QString Connector::type() const {
    return(_type);
}

/*!
 * \brief Retrieves the gender of the connector
 * \return Gender of the connector
 * \sa RsaToolbox::ConnectorGender
 */
Connector::Gender Connector::gender() const {
    return(_gender);
}

/*!
 * \brief Returns a mate-able connector
 *
 * For gender-specific connector types, the result is a connector
 * of the same type but opposite gender. For gender-neutral
 * connector types, the result is a connector similar to \c this.
 * \return Mate-able connector type
 */
Connector Connector::getMatingConnector() const {
    Connector mate = *this;
    if (!isGendered()) {
        return mate;
    }
    if (isMale()) {
        mate.setFemale();
    }
    else {
        mate.setMale();
    }
    return mate;
}

double Connector::permittivity() const {
    return _permittivity;
}
void Connector::setPermittivity(double permittivity) {
    _permittivity = permittivity;
}

bool Connector::isTemMode() const {
    return _mode == Mode::Tem;
}
bool Connector::isWaveguideMode() const {
    return _mode == Mode::Waveguide;
}
Connector::Mode Connector::mode() const {
    return _mode;
}
void Connector::setTemMode(double impedance_Ohms) {
    _mode = Mode::Tem;
    _impedance_Ohms = impedance_Ohms;
    _cutoffFrequency_Hz = 0;
}
void Connector::setWaveguideMode(double cutoffFrequency_Hz) {
    _mode = Mode::Waveguide;
    _cutoffFrequency_Hz = cutoffFrequency_Hz;
    _impedance_Ohms = 50.0;
}

double Connector::impedance_Ohms() const {
    return _impedance_Ohms;
}
void Connector::setImpedance(double ohms) {
    _impedance_Ohms = ohms;
}

double Connector::cutoffFrequency_Hz() const {
    return _cutoffFrequency_Hz;
}
void Connector::setCutoffFrequency(double frequency_Hz) {
    _cutoffFrequency_Hz = frequency_Hz;
}

/*!
 * \brief Sets the connector type to that of \c type
 *
 * All other properties of \c type are ignored with
 * the exception of it's type.
 *
 * \param type Connector with desired type
 */
void Connector::setType(const Connector &type) {
    _type = type._type;
    _type = type._type;
}

/*!
 * \brief Sets the connector type to \c type
 *
 * \param type System-defined connector type
 * \sa type()
 */
void Connector::setType(QString type) {
    _type = type;
}

/*!
 * \brief Sets the connector gender
 * \param gender Desired gender of \c this
 */
void Connector::setGender(Gender gender) {
    _gender = gender;
}
void Connector::setGenderNeutral() {
    setGender(Gender::Neutral);
}
void Connector::setMale() {
    setGender(Gender::Male);
}
void Connector::setFemale() {
    setGender(Gender::Female);
}

/*!
 * \brief Sets the properties of \c this to those of \c other
 *
 * Both the connector type and gender are set.
 *
 * \param other \c Connector with properties to be used
 * \sa setType(Connector type), setGender()
 */
void Connector::operator=(const Connector &other) {
    _type = other._type;
    _gender = other._gender;
    _permittivity = other._permittivity;
    _mode = other._mode;
    _impedance_Ohms = other._impedance_Ohms;
    _cutoffFrequency_Hz = other._cutoffFrequency_Hz;
}

/*!
 * \brief Compares the type of all \c Connector objects in \c connectors
 *
 * Certain VNA operations require all connector types be the same. For
 * example, TOSM calibration is only available when the system uses
 * connectors of the same type. This function, then, can be useful in
 * determining if TOSM calibration is possible.
 *
 * Example:
   \code
    QVector<Connector> connectors;
    connectors.append(Connector(N_50_OHM_CONNECTOR, MALE_GENDER));
    connectors.append(Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER));
    bool isSameType = isSingleConnectorType(connectors); // This value is true
   \endcode
 *
 * \param connectors
 * \return Homegeneity of the connector type of \c connectors
 */
bool Connector::isSameType(QVector<Connector> &connectors) {
    int num_connectors = connectors.size();

    if (num_connectors == 0)
        return false;

    if (num_connectors == 1)
        return true;

    for (int i = 1; i < num_connectors; i++) {
        if (!connectors.first().isType(connectors[i]))
            return false;
    }

    // else
    return true;
}

/*!
 * \brief Counts the number of male connectors in \c connectors
 *
 * This function can be useful, for example, when determining
 * the required through standards for TOSM calibration.
 *
   \code
    QVector<Connector> connectors;
    connectors.append(Connector(N_50_OHM_CONNECTOR, MALE_GENDER));
    connectors.append(Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER));
    int males = numberOfMaleConnectors(connectors);
    int females = numberOfFemaleConnectors(connectors);
    bool needsMFStandard = (males > 0 && females > 0); // This is true
   \endcode
 *
 * \param connectors Connectors to count
 * \return Number of male connectors in \c connectors
 * \sa numberOfFemaleConnectors()
 */
int Connector::maleCount(QVector<Connector> &connectors) {
    int males = 0;
    foreach(Connector c, connectors) {
        if (c.isMale())
            males++;
    }
    return(males);
}

/*!
 * \brief Counts the number of female connectors in \c connectors
 *
 * This function can be useful, for example, when determining
 * the required through standards for TOSM calibration.
 *
   \code
    QVector<Connector> connectors;
    connectors.append(Connector(N_50_OHM_CONNECTOR, MALE_GENDER));
    connectors.append(Connector(N_50_OHM_CONNECTOR, FEMALE_GENDER));
    int males = numberOfMaleConnectors(connectors);
    int females = numberOfFemaleConnectors(connectors);
    bool needsMFStandard = (males > 0 && females > 0); // This is true
   \endcode
 *
 * \param connectors Connectors to count
 * \return Number of female connectors in \c connectors
 * \sa numberOfMaleConnectors()
 */
int Connector::femaleCount(QVector<Connector> &connectors) {
    int females = 0;
    foreach(Connector c, connectors) {
        if (c.isFemale())
            females++;
    }
    return(females);
}

/*!
 * \brief Generates user-friendly text for each \c Connector in
 * \c connectors
 *
 * The \c displayText() method for each object in \c connectors is
 * used to generate the result.
 *
 * \param connectors Connectors to textualize
 * \return User-friendly text representation of each \c Connector
 * in \c connectors.
 *
 * \sa displayText()
 */
QStringList Connector::displayText(QVector<Connector> connectors) {
    QStringList displays;
    foreach (Connector c, connectors) {
        displays.append(c.displayText());
    }
    return(displays);
}


/*!
 * \relates Connector
 * \brief Compares \c left and \c right for equality
 *
 * Returns true if \c right and \c left have the
 * same type and gender.
 *
 * Example:
   \code
    Connector one(N_50_OHM_CONNECTOR, MALE_GENDER);
    Connector two(N_50_OHM_CONNECTOR, FEMALE_GENDER);

    bool isEqual = (one == two); // This value is false
   \endcode
 *
 * \note User-defined types are case-sensitive.
 *
 * \param right \c Connector on right-hand side of == operator
 * \param left \c Connector on left-hand side of == operator
 * \return \c true if objects are equal, false otherwise
 * \sa operator!=(const Connector &right, const Connector &left)
 */
bool RsaToolbox::operator==(const Connector &right, const Connector &left) {
    if (right.type() != left.type())
        return false;
    if (right.gender() != left.gender())
        return false;

    // else
    return true;
}

/*!
 * \relates Connector
 * \brief Compares \c left and \c right for inequality
 *
 * Returns true if \c right and \c left do not have the
 * same type and gender.
 *
 * Example:
   \code
    Connector one(N_50_OHM_CONNECTOR, MALE_GENDER);
    Connector two(mm_3_5_CONNECTOR, MALE_GENDER);

    bool isUnequal = (one != two); // This value is true
   \endcode
 *
 * \note User-defined types are case-sensitive.
 *
 * \param right \c Connector on right-hand side of != operator
 * \param left \c Connector on left-hand side of != operator
 * \return \c true if objects are unequal, false otherwise
 ** \sa operator==(const Connector &right, const Connector &left)
 */
bool RsaToolbox::operator!=(const Connector &right, const Connector &left) {
    return !(right == left);
}

QDataStream& RsaToolbox::operator<<(QDataStream &stream, const Connector &connector) {
    stream << connector.type();
    stream << qint32(connector.gender());
    stream << connector.permittivity();
    stream << qint32(connector.mode());
    if (connector.isTemMode()) {
        stream << connector.impedance_Ohms();
    }
    else {
        stream << connector.cutoffFrequency_Hz();
    }
    return stream;
}
QDataStream& RsaToolbox::operator>>(QDataStream &stream, Connector &connector) {
    qint32 _qint32;
    double _double;
    QString _string;

    stream >> _string;
    connector.setType(_string);

    stream >> _qint32;
    connector.setGender(Connector::Gender(_qint32));

    stream >> _double;
    connector.setPermittivity(_double);

    stream >> _qint32;
    stream >> _double;
    if (Connector::Mode(_qint32) == Connector::Mode::Tem){
        connector.setTemMode(_double);
    }
    else {
        connector.setWaveguideMode(_double);
    }
    return stream;
}

