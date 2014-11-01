

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
Connector::Connector() {
    _type = UNKNOWN_CONNECTOR;
    _gender = NEUTRAL_GENDER;
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
Connector::Connector(const Connector &other) {
    _type = other._type;
    _customType = other._customType;
    _gender = other._gender;
}

/*!
 * \brief Constructor for a connector with properties
 * \c type and \c gender
 *
 * \note For a connector with a custom, user-defined type,
 * see the \c
 * Connector::Connector(QString customType, ConnectorGender gender)
 * constructor
 *
 *
 * \param type Connector type
 * \param gender Connector gender
 */
Connector::Connector(Type type, ConnectorGender gender) {
    _type = type;
    _gender = gender;
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
Connector::Connector(QString customType, ConnectorGender gender) {
    _type = CUSTOM_CONNECTOR;
    _customType = customType;
    _gender = gender;
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
    return(displayType() + " " + displayGender());
}

/*!
 * \brief Returns the connector type as user-friendly text
 *
 * For user-defined connector types, the string representing
 * the user-defined type is returned verbatim.
 *
 * \return Connector type as user-friendly text
 */
QString Connector::displayType() const {
    if (isCustomType())
        return(_customType);
    else
        return(displayType(_type));
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
    case MALE_GENDER: return("Male");
    case FEMALE_GENDER: return("Female");
    case NEUTRAL_GENDER: return("Neutral");
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
    case MALE_GENDER: return("M");
    case FEMALE_GENDER: return("F");
    case NEUTRAL_GENDER: return("N");
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
bool Connector::isType(Connector &other) const {
    if (isNotCustomType())
        return(type() == other.type());
    else if (other.isNotCustomType())
        return(false);
    else
        return(customType() == other.customType());
}

/*!
 * \brief Performs a connector type comparison with \c other
 *
 * Returns false if \c this and \c other are the same
 * connector type. For user-defined connector types, the
 * string representing the type are compared.
 *
 * \note User-defined types are case-sensitive.
 *
 * \param other Connector to compare
 * \return Result of connector type comparison for inequality
 * \sa isType()
 */
bool Connector::isNotType(Connector &other) const {
    return(!isType(other));
}

/*!
 * \brief Checks for user-defined (custom) connector type
 * \return true if user-defined connector type
 * \sa isNotCustomType()
 */
bool Connector::isCustomType() const {
    return(_type == CUSTOM_CONNECTOR);
}

/*!
 * \brief Checks if not user-defined (custom) connector type
 * \return \c true if not user-defined connector type
 * \sa isCustomType()
 */
bool Connector::isNotCustomType() const {
    return(!isCustomType());
}

/*!
 * \brief Compares gender with \c gender for equality
 * \param gender Gender to compare
 * \return  Result of gender comparison
 */
bool Connector::isGender(ConnectorGender gender) const {
    return(_gender == gender);
}

/*!
 * \brief Determines if connector is male gender
 * \return \c true if connector is male.
 */
bool Connector::isMale() const {
    return(_gender == MALE_GENDER);
}

/*!
 * \brief Determines if connector is not male gender
 * \return \c true if connector is not male.
 */
bool Connector::isNotMale() const {
    return(!isMale());
}

/*!
 * \brief Determines if connector is female gender
 * \return \c true if connector is female.
 */
bool Connector::isFemale() const {
    return(_gender == FEMALE_GENDER);
}

/*!
 * \brief Determines if connector is not female gender
 * \return \c true if connector is not female.
 */
bool Connector::isNotFemale() const {
    return(!isFemale());
}

/*!
 * \brief Determines if connector type is gender-neutral
 * \return \c true if connector is gender-neutral.
 */
bool Connector::isGenderNeutral() const {
    return(_gender == NEUTRAL_GENDER);
}

/*!
 * \brief Determines if connector type is gender-specifc
 * \return \c true if connector type has specific genders
 */
bool Connector::isGenderSpecific() const {
    return(!isGenderNeutral());
}

/*!
 * \brief Retrieves the connector type
 *
 * For user-defined connector types, use the \c customType()
 * method to retrieve type.
 *
 * \return System-defined connector type, or \c CUSTOM_CONNECTOR
 * \sa Connector::Type, customType()
 */
Connector::Type Connector::type() const {
    return(_type);
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
QString Connector::customType() const {
    return(_customType);
}

/*!
 * \brief Retrieves the gender of the connector
 * \return Gender of the connector
 * \sa RsaToolbox::ConnectorGender
 */
ConnectorGender Connector::gender() const {
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
    Connector mate;
    mate.setType(*this);
    if (isGenderNeutral()) {
        mate.setGender(NEUTRAL_GENDER);
    }
    else {
        if (isMale())
            mate.setGender(FEMALE_GENDER);
        else
            mate.setGender(MALE_GENDER);
    }
    return(mate);
}

/*!
 * \brief Sets the connector type to that of \c type
 *
 * All other properties of \c type are ignored with
 * the exception of it's type.
 *
 * \param type Connector with desired type
 */
void Connector::setType(const Connector type) {
    if (type.isCustomType())
        setCustomType(type.customType());
    else
        setType(type.type());
}

/*!
 * \brief Sets the connector type to system-defined \c type
 *
 * For user-defined connector types, use \c setCustomType()
 *
 * \param type System-defined connector type
 * \sa RsaToolbox::Connector::Type, setCustomType()
 */
void Connector::setType(Type type) {
    _type = type;
}

/*!
 * \brief Sets the connector type to user-defined \c type
 *
 * For system-defined connector types, use
 * \c setType(Type type)
 *
 * \param type System-defined connector type
 * \sa RsaToolbox::Connector::Type, setType(Connector type), setCustomType()
 */
void Connector::setCustomType(QString type) {
    _type = CUSTOM_CONNECTOR;
    _customType = type;
}

/*!
 * \brief Sets the connector gender
 * \param gender Desired gender of \c this
 */
void Connector::setGender(ConnectorGender gender) {
    _gender = gender;
}

/*!
 * \brief Sets the properties of \c this to those of \c other
 *
 * Both the connector type and gender are set.
 *
 * \param other \c Connector with properties to be used
 * \sa setType(Connector type), setGender()
 */
void Connector::operator =(const Connector &other) {
    _type = other._type;
    _customType = other._customType;
    _gender = other._gender;
}

/*!
 * \brief Converts \c type to user-friendly text
 * \param type Connector type to textualize
 * \return User-friendly text representation of \c type
 */
QString Connector::displayType(Type type) {
    switch(type) {
    case N_50_OHM_CONNECTOR: return("N 50 Ohm");
    case N_75_OHM_CONNECTOR: return("N 75 Ohm");
    case mm_7_CONNECTOR: return("7 mm");
    case mm_3_5_CONNECTOR: return("3.5 mm");
    case mm_2_92_CONNECTOR: return("2.92 mm");
    case mm_2_4_CONNECTOR: return("2.4 mm");
    case mm_1_85_CONNECTOR: return("1.85 mm");
    case in_7_16_CONNECTOR: return("7/16");
    case TYPE_F_75_OHM_CONNECTOR: return("Type F (75)");
    case BNC_50_OHM_CONNECTOR: return("BNC 50 Ohm");
    case BNC_75_OHM_CONNECTOR: return("BNC 75 Ohm");
    case CUSTOM_CONNECTOR: return("Custom Connector");
    default: return("Unknown Connector");
    }
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
bool Connector::isSingleConnectorType(QVector<Connector> &connectors) {
    int num_connectors = connectors.size();

    if (num_connectors == 0)
        return(false);

    if (num_connectors == 1)
        return(true);

    for (int i = 1; i < num_connectors; i++) {
        if (connectors.first().isNotType(connectors[i]))
            return(false);
    }

    // else
    return(true);
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
int Connector::numberOfMaleConnectors(QVector<Connector> &connectors) {
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
int Connector::numberOfFemaleConnectors(QVector<Connector> &connectors) {
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
 * \brief Converts scpi representation to Connector::Type
 * \param vnaScpi SCPI-formatted representation
 * \return Type of connector
 */
Connector::Type RsaToolbox::toConnectorType(QString vnaScpi) {
    if (vnaScpi.contains("N 50 Ohm", Qt::CaseInsensitive))
        return Connector::N_50_OHM_CONNECTOR;
    else if (vnaScpi.contains("N 75 Ohm", Qt::CaseInsensitive))
        return Connector::N_75_OHM_CONNECTOR;
    else if (vnaScpi.contains("7 mm", Qt::CaseInsensitive))
        return Connector::mm_7_CONNECTOR;
    else if (vnaScpi.contains("3.5 mm", Qt::CaseInsensitive))
        return Connector::mm_3_5_CONNECTOR;
    else if (vnaScpi.contains("2.92 mm", Qt::CaseInsensitive))
        return Connector::mm_2_92_CONNECTOR;
    else if (vnaScpi.contains("2.4 mm", Qt::CaseInsensitive))
        return Connector::mm_2_4_CONNECTOR;
    else if (vnaScpi.contains("1.85 mm", Qt::CaseInsensitive))
        return Connector::mm_1_85_CONNECTOR;
    else if (vnaScpi.contains("7-16"))
        return Connector::in_7_16_CONNECTOR;
    else if (vnaScpi.contains("Type F (75)", Qt::CaseInsensitive))
        return Connector::TYPE_F_75_OHM_CONNECTOR;
    else if (vnaScpi.contains("BNC 50 Ohm", Qt::CaseInsensitive))
        return Connector::BNC_50_OHM_CONNECTOR;
    else if (vnaScpi.contains("BNC 75 Ohm", Qt::CaseInsensitive))
        return Connector::BNC_75_OHM_CONNECTOR;
    else if (vnaScpi.isEmpty() == false)
        return Connector::CUSTOM_CONNECTOR;
    else
        return Connector::UNKNOWN_CONNECTOR;
}

/*!
 * \relates Connector
 * \brief Converts scpi representation to ConnectorGender
 * \param vnaScpi SCPI-formatted connector gender
 * \return Gender
 */
ConnectorGender RsaToolbox::toConnectorGender(QString vnaScpi) {
    vnaScpi = vnaScpi.toUpper();
    if (vnaScpi == "MALE")
        return(MALE_GENDER);
    if (vnaScpi == "FEM")
        return(FEMALE_GENDER);
    // else
        return(NEUTRAL_GENDER);
}

/*!
 * \relates Connector
 * \brief Converts Connector::Type to SCPI representation
 * \param type Connector type to convert
 * \return SCPI representation
 */
QString RsaToolbox::toVnaScpi(Connector::Type type) {
    switch(type) {
    case Connector::N_50_OHM_CONNECTOR:
        return("N 50 Ohm");
    case Connector::N_75_OHM_CONNECTOR:
        return("N 75 Ohm");
    case Connector::mm_7_CONNECTOR:
        return("7 mm"); // PC 7
    case Connector::mm_3_5_CONNECTOR:
        return("3.5 mm"); // PC 3.5
    case Connector::mm_2_92_CONNECTOR:
        return("2.92 mm");
    case Connector::mm_2_4_CONNECTOR:
        return("2.4 mm");
    case Connector::mm_1_85_CONNECTOR:
        return("1.85 mm");
    case Connector::in_7_16_CONNECTOR:
        return("7-16");
    case Connector::TYPE_F_75_OHM_CONNECTOR:
        return("Type F (75)"); // !Zva
    case Connector::BNC_50_OHM_CONNECTOR:
        return("BNC 50 Ohm"); // !Zva
    case Connector::BNC_75_OHM_CONNECTOR:
        return("BNC 75 Ohm"); // !Zva
    default:
        return("UNKNOWN_CONNECTOR");
    }
}

/*!
 * \relates Connector
 * \brief Converts ConnectorGender to SCPI representation
 * \param gender Connector gender to convert
 * \return SCPI representation
 */
QString RsaToolbox::toVnaScpi(ConnectorGender gender) {
    switch(gender) {
    case MALE_GENDER:   return("MALE");
    case FEMALE_GENDER: return("FEM");
    default:            return("MALE");
    }
}

/*!
 * \relates Connector
 * \brief Converts Connector type to SCPI representation
 * \param connector Connector with type to convert
 * \return SCPI type representation
 */
QString RsaToolbox::toConnectorTypeVnaScpi(Connector connector) {
    if (connector.isCustomType())
        return(connector.customType());
    else
        return(toVnaScpi(connector.type()));
}

/*!
 * \relates Connector
 * \brief Converts Connector gender to SCPI representation
 * \param connector Connector with gender to convert
 * \return SCPI gender representation
 */
QString RsaToolbox::toConnectorGenderVnaScpi(Connector connector) {
    return(toVnaScpi(connector.gender()));
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
        return(false);
    if (right.isCustomType() && right.customType() != left.customType())
        return(false);
    if (right.gender() != left.gender())
        return(false);

    // else
    return(true);
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
bool RsaToolbox::operator !=(const Connector &right, const Connector &left) {
    return(!(right == left));
}


