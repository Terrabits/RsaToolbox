#include "BalancedPort.h"
using namespace RsaToolbox;


/*!
 * \class RsaToolbox::BalancedPort
 * \brief Handles balanced port definitions
 *
 * Rohde \& Schwarz Vector Network Analyzers
 * fully support balanced ports. A logical
 * port is created out of a pair of physical
 * ports, and the resulting common-mode or
 * differential-mode signal can be referenced.
 *
 * To handle balanced ports without having
 * to explicitly handle all the details,
 * the \c %BalancedPort class is used.
 *
 * For example, a mixture of balanced and
 * unbalanced ports can be represented by
 * \c %BalancedPort instances. These instances
 * can then be used as arguments in overloaded
 * methods such as
 * VnaTrace::setNetworkParameter(). This is
 * opposed to manually keeping track of which
 * ports are balanced, and calling different
 * methods depending on the port status.
 *
 * \sa VnaTrace::setNetworkParameter()
 */

/*!
 * \brief Default constructor
 *
 * The default constructor creates a
 * single-ended port with an undefined
 * logical and physical port number. Objects
 * created with the default constructor should
 * be properly initialized before use.
 * \sa setPortType, setLogicalPort, setPhysicalPort
 */
BalancedPort::BalancedPort() {
    _portType = SINGLE_ENDED;
}

/*!
 * \brief Constructor for single-ended port
 *
 * The resulting instance is single-ended
 * with logical and physical ports set
 * to \c logicalPort.
 * \sa setPortType, setLogicalPort, setPhysicalPort
 */
BalancedPort::BalancedPort(uint logicalPort) {
    _logicalPort = logicalPort;
    _portType = SINGLE_ENDED;
}

/*!
 * \brief Returns the port balance type
 *
 * \return Port balance type
 * \sa RsaToolbox::BalancedPortType
 */
BalancedPortType BalancedPort::portType() {
    return(_portType);
}

/*!
 * \brief Returns balanced port status
 * \return \c true if a balanced port; \c false otherwise
 */
bool BalancedPort::isBalanced() {
    return(!isSingleEnded());
}

/*!
 * \brief Returns differential mode port status
 * \return \c true if differential mode balanced port; \c false otherwise
 */
bool BalancedPort::isDifferential() {
    return(_portType == DIFFERENTIAL_MODE);
}

/*!
 * \brief Returns common mode port status
 * \return \c true if common mode balanced port; \c false otherwise
 */
bool BalancedPort::isCommonMode() {
    return(_portType == COMMON_MODE);
}

/*!
 * \brief Returns single ended port status
 * \return \c true if single ended port; \c false otherwise
 */
bool BalancedPort::isSingleEnded() {
    return(_portType == SINGLE_ENDED);
}

/*!
 * \brief Returns the logical port index
 * \return Logical port number
 */
uint BalancedPort::logicalPort() {
    return(_logicalPort);
}

/*!
 * \brief Sets this to a single-ended logical port
 */
void BalancedPort::setSingleEnded() {
    _portType = SINGLE_ENDED;
}

/*!
 * \brief Sets this to a differential-mode
 * logical port
 *
 * A call to \c BalancedPort::setPhysicalPorts()
 * may be necessary to fully-define the port
 * \sa BalancedPort::setPhysicalPorts()
 */
void BalancedPort::setDifferential() {
    _portType = DIFFERENTIAL_MODE;
}

/*!
 * \brief Sets this to a common-mode logical port
 *
 * A call to \c BalancedPort::setPhysicalPorts()
 * may be necessary to fully-define the port
 * \sa BalancedPort::setPhysicalPorts()
 */
void BalancedPort::setCommonMode() {
    _portType = COMMON_MODE;
}

/*!
 * \brief Sets the balanced port type
 * \param type Type of balanced port
 * \sa RsaToolbox::BalancedPortType
 */
void BalancedPort::setPortType(BalancedPortType type) {
    _portType = type;
}
/*!
 * \brief Sets the logical port index
 * \param logicalPort Logical port number
 */
void BalancedPort::setLogicalPort(uint logicalPort) {
    _logicalPort = logicalPort;
}

/*!
 * \brief Returns the logical port number
 * as an unsigned integer
 *
 * Logical ports are usually referenced by
 * their port number, regardless of whether
 * or not they are single-ended or balanced.
 * This conversion is provided as a
 * convenience for such situations.
 */
BalancedPort::operator int() {
    return(int(_logicalPort));
}

/*!
 * \brief Returns the logical port number
 * as an integer
 *
 * Logical ports are usually referenced by
 * their port number, regardless of whether
 * or not they are single-ended or balanced.
 * This conversion is provided as a
 * convenience for such situations.
 */
BalancedPort::operator uint() {
    return(_logicalPort);
}

/*!
 * \relates RsaToolbox::BalancedPort
 * \brief Converts a balanced port type into
 * VNA SCPI notation.
 *
 * This function is useful when forming SCPI
 * commands manually.
 *
 * \param type Type of balanced port
 * \return SCPI representation of port balance type
 */
QString RsaToolbox::toVnaScpi(BalancedPortType type) {
    switch(type) {
    case SINGLE_ENDED: return("s");
    case DIFFERENTIAL_MODE: return("d");
    case COMMON_MODE: return("c");
    default: return("s");
    }
}
