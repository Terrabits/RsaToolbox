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
    _type = BalancedPort::Type::SingleEnded;
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
    _port = logicalPort;
    _type = BalancedPort::Type::SingleEnded;
}

BalancedPort::BalancedPort(uint logicalPort, Type type) {
    _port = logicalPort;
    _type = type;
}

/*!
 * \brief Returns the port balance type
 *
 * \return Port balance type
 * \sa RsaToolbox::BalancedPortType
 */
BalancedPort::Type BalancedPort::type() const {
    return(_type);
}

/*!
 * \brief Returns balanced port status
 * \return \c true if a balanced port; \c false otherwise
 */
bool BalancedPort::isBalanced() const {
    return(!isSingleEnded());
}

/*!
 * \brief Returns differential mode port status
 * \return \c true if differential mode balanced port; \c false otherwise
 */
bool BalancedPort::isDifferential() const {
    return(_type == BalancedPort::Type::Differential);
}

/*!
 * \brief Returns common mode port status
 * \return \c true if common mode balanced port; \c false otherwise
 */
bool BalancedPort::isCommonMode() const {
    return(_type == BalancedPort::Type::Common);
}

/*!
 * \brief Returns single ended port status
 * \return \c true if single ended port; \c false otherwise
 */
bool BalancedPort::isSingleEnded() const {
    return(_type == BalancedPort::Type::SingleEnded);
}

/*!
 * \brief Returns the logical port index
 * \return Logical port number
 */
uint BalancedPort::port() const {
    return _port;
}

/*!
 * \brief Sets this to a single-ended logical port
 */
void BalancedPort::setSingleEnded() {
    _type = BalancedPort::Type::SingleEnded;
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
    _type = BalancedPort::Type::Differential;
}

/*!
 * \brief Sets this to a common-mode logical port
 *
 * A call to \c BalancedPort::setPhysicalPorts()
 * may be necessary to fully-define the port
 * \sa BalancedPort::setPhysicalPorts()
 */
void BalancedPort::setCommonMode() {
    _type = BalancedPort::Type::Common;
}

/*!
 * \brief Sets the balanced port type
 * \param type Type of balanced port
 * \sa RsaToolbox::BalancedPortType
 */
void BalancedPort::setType(BalancedPort::Type type) {
    _type = type;
}
/*!
 * \brief Sets the logical port index
 * \param logicalPort Logical port number
 */
void BalancedPort::setPort(uint logicalPort) {
    _port = logicalPort;
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
BalancedPort::operator int() const {
    return int(_port);
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
BalancedPort::operator uint() const {
    return _port;
}

