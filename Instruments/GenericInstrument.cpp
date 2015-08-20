#include <QDebug>

// RsaTolbox
#include "General.h"
#include "GenericInstrument.h"
#include "VisaBus.h"
#include "TcpBus.h"
#include "NoBus.h"
using namespace RsaToolbox;

/*!
 * \defgroup InstrumentGroup Instrument
 * Rohde \& Schwarz instrument driver
 * classes
 */
 
 /*!
  * \defgroup GenericInstrumentGroup GenericInstrument
  * \ingroup InstrumentGroup
  */

/*!
 * \class RsaToolbox::GenericInstrument
 * \ingroup GenericInstrumentGroup
 * \brief The %GenericInstrument class serves as a base class for all instruments.
 *
 * %GenericInstrument provides basic functionality. It can manage an instrument
 * connection via a GenericBus subclass, it can connect to a Log, it can read,
 * write and query, and it implements a subset of the required SCPI commands
 * (such as *RST).
 *
 * This functionality can be extended to a specific instrument by subclassing
 * %GenericInstrument and building on it.
 */

/*!
 * \brief Default constructor
 * \param parent Optional parent QObject
 */
GenericInstrument::GenericInstrument(QObject *parent) :
    QObject(parent)
{
    _log = &_tempLog;
    resetBus();
}
/*!
 * \brief Constructor that uses the provided bus connection
 * \param bus Connection to an instrument
 * \param parent Optional parent QObject
 */
GenericInstrument::GenericInstrument(GenericBus *bus, QObject *parent) :
    QObject(parent)
{
    _log = &_tempLog;
    resetBus(bus);
    _bus->setBufferSize(500);
    _bus->setTimeout(1000);
}
/*!
 * \brief Construct which connects to the instrument at the address
 * specified
 *
 * When using this constructor, %GenericInstrument defaults to
 * VisaBus.
 * Please make sure VISA is installed on the target system.
 *
 * \param type The type of connection (see ConnectionType)
 * \param address Address of the instrument (e.g. "127.0.0.1")
 * \param parent Optional parent QObject
 */
GenericInstrument::GenericInstrument(ConnectionType type, QString address, QObject *parent) :
    QObject(parent)
{
    _log = &_tempLog;
    resetBus(type, address);
}

/*!
 * \brief Disconnects from instrument, if applicable,
 * and resets the instrument bus
 *
 * Because no bus connection is present, log is
 * also disconnected, if applicable.
 * \sa resetBus(GenericBus *bus)
 */
void GenericInstrument::resetBus() {
    bool emitSignal = isConnected();
    Log *temp = _log;
    disconnectLog();
    _bus.reset(new NoBus());
    QObject::connect(_bus.data(), SIGNAL(error()), this, SIGNAL(busError()));
    _log = temp;
    if (emitSignal)
        emit disconnected();
}
/*!
 * \brief Connects this object to the instrument connected
 * via \c bus.
 *
 * If a previous connection exists, it is destroyed. Ownership
 * of \c bus is relinquished to this method (see
 * QScopedPointer::reset() and QScopedPointer::take()).
 *
 * \param bus Bus connection to take ownership of
 * \sa resetBus()
 */
void GenericInstrument::resetBus(GenericBus *bus) {
    resetBus();
    _bus.reset(bus);
    QObject::connect(_bus.data(), SIGNAL(error()), this, SIGNAL(busError()));
    if (isConnected()) {
        connectLog();
        if (isLogConnected())
            printInfo();
        emit connected();
    }
}
/*!
 * \brief Connects to the instrument \c type :: \c address
 * with the timeout time \c timeout_ms
 *
 * This method defaults to VisaBus. Please make sure
 * VISA is installed on the target system.
 * \param type The type of connection (e.g. TCPIP or GPIB)
 * \param address Address of the instrument (e.g. "127.0.0.1")
 */
void GenericInstrument::resetBus(ConnectionType type, QString address) {
#ifdef Q_OS_WIN32
    resetBus(new VisaBus(type, address));
#else
    if (VisaBus::isVisaInstalled())
        resetBus(new VisaBus(type, address));
    else if (type == ConnectionType::TCPIP_CONNECTION)
        resetBus(new TcpBus(type, address));
    else
        resetBus(new NoBus());
#endif
}

/*!
 * \brief Checks for an instrument connection
 * \return \c true if an instrument is connected,
 * \c false otherwise
 */
bool GenericInstrument::isConnected() const {
    return !_bus.isNull() && _bus->isOpen();
}
/*!
 * \brief Checks for no connection to an instrument
 * \return \c true if no instrument connection is
 * present, \c false otherwise
 */
bool GenericInstrument::isDisconnected() const {
    return(!isConnected());
}

bool GenericInstrument::isLogOpen() const {
    return _log->isOpen();
}
/*!
 * \brief Checks if log is in use
 *
 * \note A %GenericBus object that is not connected
 * to an instrument is also not connected to
 * a log. If a valid log has been registered via
 * %useLog(), it will be (re)connected after a valid
 * instrument connection is made.
 *
 * \return \c true if this object is connected
 * to a log, \c false otherwise
 */
bool GenericInstrument::isLogConnected() const {
    return(isLogOpen() && isConnected());
}
/*!
 * \brief Returns disconect status of log
 * \return \c true if no log is connected,
 * \c false otherwise
 */
bool GenericInstrument::isLogDisconnected() const {
    return(!isLogConnected());
}
/*!
 * \brief Returns a pointer to the current log
 * \return \c Log pointer if a log is connected,
 * \c NULL otherwise
 */
Log* GenericInstrument::log() {
    if (_log != &_tempLog)
        return(_log);
    else
        return(NULL);
}
/*!
 * \brief Connects %GenericInstrument to a log
 *
 * If %GenericInstrument is not connected to an
 * instrument at the time, the %log pointer will
 * connect after an instrument connection is made
 * (see resetBus(GenericBus *bus).
 *
 * \param log Pointer to log to use
 */
void GenericInstrument::useLog(Log *log) {
    disconnectLog();
    if (log->isOpen()) {
        _log = log;
        connectLog();
    }
}
/*!
 * \brief Disconnects from the current log,
 * if applicable
 *
 * If no log is currently registered, this
 * method has no effect.
 * \sa useLog()
 */
void GenericInstrument::disconnectLog() {
    if (isLogConnected()) {
        QObject::disconnect(_bus.data(), SIGNAL(print(QString)),
                            _log, SLOT(print(QString)));
    }
    _log = &_tempLog;
}
void GenericInstrument::connectLog() {
    if (isLogOpen() && isConnected()) {
        QObject::connect(_bus.data(), SIGNAL(print(QString)),
                         _log, SLOT(print(QString)));
    }
}

void GenericInstrument::print(QString text) {
    *_log << text;
}
void GenericInstrument::printLine(QString text) {
    *_log << text << endl;
}
void GenericInstrument::printInfo() {
    if (!_log->isOpen())
        return;

    Log *tempLog = _log;
    disconnectLog();

    QString info;
    printInfo(info);
    tempLog->print(info);

    useLog(tempLog);
}
void GenericInstrument::printInfo(QString &info) {
    QTextStream stream(&info);
    stream << "INSTRUMENT INFO" << endl;
    stream << "Connection: " << toString(_bus->connectionType()) << endl;
    stream << "Address:    " << _bus->address() << endl;
    if (isConnected()) {
        if (isRohdeSchwarz())
            stream << "Make:       Rohde & Schwarz" << endl;
        else
            stream << "Make:       Unknown" << endl;
        stream << "Id string:  " << idString() << endl;
    }
    else {
        stream << "Error:      Instrument not found!" << endl;
    }
    stream << endl << endl;
    stream.flush();
}

/*!
 * \brief Passes ownership of the current instrument
 * connection to callee.
 *
 * %GenericInstrument object is left in a disconnected
 * state.
 *
 * \note If no instrument connection is present,
 * \c bus may be \c NULL. Check the value
 * of \c bus for NULL and check to make sure
 * \c bus is connected before use.
 *
 * \return Ownership of \c bus pointer
 * \sa bus()
 */
GenericBus* GenericInstrument::takeBus() {
    disconnectLog();
    return(_bus.take());
    disconnected();
}

/*!
 * \brief Returns the current connection type
 *
 * \note If no connection is present, \c NO_CONNECTION
 * is returned.
 *
 * \return Instrument connection type
 * \sa address(), timeout_ms(), RsaToolbox::ConnectionType
 */
ConnectionType GenericInstrument::connectionType() const {
    if (isConnected())
        return(_bus->connectionType());
    //else
    return(NO_CONNECTION);
}

/*!
 * \brief Returns the address of the instrument
 * that is connected
 *
 * \note If no instrument connection is present,
 * an emtpy string ("") is returned.
 *
 * \return Instrument address
 * \sa connectionType(), timeout_ms()
 */
QString GenericInstrument::address() const {
    if (isConnected())
        return(_bus->address());
    // else
    return("");
}

/*!
 * \brief GenericInstrument::read
 * \param buffer
 * \param bufferSize_B
 * \param timeout_ms
 * \return
 */
bool GenericInstrument::read(char *buffer, uint bufferSize_B, uint timeout_ms) {
    uint previousTimeout = _bus->timeout_ms();
    _bus->setTimeout(timeout_ms);
    bool success = _bus->read(buffer, bufferSize_B);
    _bus->setTimeout(previousTimeout);
    return(success);
}

/*!
 * \brief Reads data from the instrument into \c buffer
 *
 * The action and result is printed to a log file, if connected.
 *
 * It is important to property set the \c bufferSize of \c buffer.
 * If more than \c bufferSize bytes are waiting to be read
 * by the instrument, an error may result and/or subsequent
 * calls to \c %read() may be necessary.
 *
 * It is also important to make sure that the instrument
 * is expecting to be read; calling %read() without having
 * any data to be read will result in an instrument error.
 *
 * \note Make sure that a valid instrument connection is
 * present before calling this method, otherwise
 * unintended behavior may result.
 *
 * \param bufferSize_B Buffer for read
 * \param timeout_ms Time until timeout, in milliseconds
 * \return \c true if successful, \c false otherwise
 * \sa write(), query(), isConnected(), useLog()
 */
QString GenericInstrument::read(uint bufferSize_B, uint timeout_ms) {
    uint previousBufferSize = _bus->bufferSize_B();
    uint previousTimeout = _bus->timeout_ms();

    _bus->setBufferSize(bufferSize_B);
    _bus->setTimeout(timeout_ms);
    QString result = _bus->read();

    _bus->setBufferSize(previousBufferSize);
    _bus->setTimeout(previousTimeout);
    return(result);
}

/*!
 * \brief Writes \c scpiCommand to the instrument
 *
 * The action and result is printed to a log file, if connected.
 *
 * See query() for SCPI commands that elicit a response
 * from the instrument; query() can handle both the read
 * and write in one method call.
 *
 * \note Make sure that a valid instrument connection is
 * present before calling this method, otherwise
 * unintended behavior may result.
 * \param scpiCommand Command to be written to the instrument
 * \sa read(), query(), isConnected(), useLog()
 */
void GenericInstrument::write(QString scpiCommand) {
    _bus->write(scpiCommand);
}
/*!
 * \brief Writes \c scpiCommand to the instrument, then
 * immediately reads the result to \c buffer
 *
 * This method is provided for convenience: it calls
 * write() and then read(), then returns the result. See
 * write() and read() for more information.
 *
 * The action and result is printed to a log file, if connected.
 *
 *\note Make sure that a valid instrument connection is
 * present before calling this method, otherwise
 * unintended behavior may result.
 *
 * \param scpiCommand Command to be written to the instrument
 * \param bufferSize_B Buffer for data to be read into
 * \param timeout_ms Time until timeout, in milliseconds
 * \return
 * \sa write(), read(), isConnected(), useLog()
 */
QString GenericInstrument::query(QString scpiCommand, uint bufferSize_B, uint timeout_ms) {
    uint previousBufferSize = _bus->bufferSize_B();
    uint previousTimeout = _bus->timeout_ms();

    _bus->setBufferSize(bufferSize_B);
    _bus->setTimeout(timeout_ms);
    QString result = _bus->query(scpiCommand);

    _bus->setBufferSize(previousBufferSize);
    _bus->setTimeout(previousTimeout);
    return(result);
}

/*!
 * \brief GenericInstrument::binaryRead
 * \param buffer
 * \param bufferSize_B
 * \param bytesRead
 * \param timeout_ms
 * \return
 */
bool GenericInstrument::binaryRead(char *buffer, uint bufferSize_B, uint &bytesRead, uint timeout_ms) {
    uint previousTimeout = _bus->timeout_ms();
    _bus->setTimeout(timeout_ms);
    bool success = _bus->binaryRead(buffer, bufferSize_B, bytesRead);
    _bus->setTimeout(previousTimeout);
    return(success);
}

QByteArray GenericInstrument::binaryRead(uint bufferSize_B, uint timeout_ms)
{
    uint previousBufferSize = _bus->bufferSize_B();
    uint previousTimeout = _bus->timeout_ms();

    _bus->setBufferSize(bufferSize_B);
    _bus->setTimeout(timeout_ms);
    QByteArray result = _bus->binaryRead();

    _bus->setBufferSize(previousBufferSize);
    _bus->setTimeout(previousTimeout);
    return(result);
}
void GenericInstrument::binaryWrite(QByteArray scpiCommand) {
    _bus->binaryWrite(scpiCommand);
}
/*!
 * \brief Queries binary response from the
 * instrument
 *
 * The data contained in scpiCommand is written
 * to the instrument as-is; no null-terminations
 * or assumentions are made. The returned binary
 * data is treated in a similar manner.
 *
 * This is appropriate
 * when standard string formatting would interfere
 * with the query operation, such as when
 * transferring the raw binary contents of a file.
 *
 * \note bufferSize_B() must be equal to or
 * greater than the amount of data to be read,
 * otherwise a partial read will occur.
 *
 * \param scpiCommand
 * \param bufferSize_B
 * \param timeout_ms
 * \return Query result
 */
QByteArray GenericInstrument::binaryQuery(QByteArray scpiCommand,
                                          uint bufferSize_B, uint timeout_ms)
{
    uint previousBufferSize = _bus->bufferSize_B();
    uint previousTimeout = _bus->timeout_ms();

    _bus->setBufferSize(bufferSize_B);
    _bus->setTimeout(timeout_ms);
    QByteArray result = _bus->binaryQuery(scpiCommand);

    _bus->setBufferSize(previousBufferSize);
    _bus->setTimeout(previousTimeout);
    return(result);
}

/*!
 * \brief Locks the instrument for exclusive access
 *
 * This method calls the \c GenericBus::lock() method
 * of the underlying connection bus. Note that
 * Not all instrument busses support locking the instrument.
 *
 * \return \c true if operation is successful, \c false otherwise
 * \sa GenericBus::lock(), unlock()
 */
bool GenericInstrument::lock() {
    if (isConnected())
        return(_bus->lock());
    // else
    return(false);
}

/*!
 * \brief Unlocks the instrument for access by other applications
 *
 * This method calls the \c GenericBus::unlock() method
 * of the underlying connection bus. Note that
 * Not all instrument busses support locking the instrument.
 *
 * \return \c true if operation is successful, \c false otherwise
 * \sa GenericBus::unlock(), lock()
 */
bool GenericInstrument::unlock() {
    if (isConnected())
        return(_bus->unlock());
    // else
    return(false);
}

/*!
 * \brief Puts the instrument into local mode
 * via the current bus protocol
 *
 * This method calls the \c GenericBus::local()
 * method of the current bus object. Note that
 * not all busses support putting the instrument
 * into local mode. If a bus-level method is not provided,
 * check the instrument documentation for an equivalent
 * device-specific SCPI commands.
 *
 * \return \c true if successful, \c false otherwise
 * \sa GenericBus::remote(), local()
 */
bool GenericInstrument::local() {
    if (isConnected())
        return(_bus->local());
    // else
    return(false);
}

/*!
 * \brief Puts the instrument into remote mode
 * via the current bus protocol
 *
 * This method calls the \c GenericBus::remote()
 * method of the current bus object. Note that
 * not all busses support putting the instrument
 * into remote mode. If a bus-level method is not provided,
 * check the instrument documentation for an equivalent
 * device-specific SCPI commands.
 *
 * \return \c true if successful, \c false otherwise
 * \sa GenericBus::remote(), local()
 */
bool GenericInstrument::remote() {
    if (isConnected())
        return(_bus->remote());
    // else
    return(false);
}

/*!
 * \brief Determines if the instrument is a Rohde \&
 * Schwarz instrument
 *
 * This method uses the \c idString(). If the
 * \c idString() contains the string "Rohde",
 * this method returns true.
 *
 * \return \c true if instrument is Rohde \& Schwarz,
 * \c false otherwise
 */
bool GenericInstrument::isRohdeSchwarz() {
    return(idString().contains("Rohde", Qt::CaseInsensitive));
}

// General SCPI commands (*)

/*!
 * \brief Returns the identification string
 *
 * This method uses the "*IDN?" SCPI
 * command to query the id string
 * of the instrument.
 *
 * \return Identification string
 */
QString GenericInstrument::idString() {
    return(_bus->query("*IDN?\n").trimmed());
}

/*!
 * \brief Returns the options string
 *
 * This method uses the "*OPT?"
 * SCPI command.
 *
 * \return Options string
 * \sa idString()
 */
QString GenericInstrument::optionsString() {
    return(_bus->query("*OPT?\n").trimmed());
}

/*!
 * \brief Presets the instrument
 *
 * This method sends the "*RST"
 * SCPI command.
 */
void GenericInstrument::preset() {
    _bus->write("*RST\n");
}

/*!
 * \brief Sends the "*WAI" SCPI command
 *
 * *WAI is used to synchonize SCPI commands.
 * *WAI commands the instrument to process all
 * preceeding commands and allow all sweeps to
 * finish before processing any subsequent SCPI
 * commands. This method immediately returns,
 * although any subsequent read/write operations
 * may be held up while *WAI is being processed.
 *
 * For a gentle introduction to synchronous
 * instrument programming, see Application Note
 * <a href="http://www.rohde-schwarz.de/file/1GP79_1E_SCPI_Programming_Guide_SigGens.pdf">
 * 1GP79-1E: Top Ten SCPI Programming Tips for
 * Signal Generators</a>. Although the App Note is
 * specifically for Signal Generators, many of
 * the concepts apply equally well to all
 * instruments.
 *
 *\note Make sure that a valid instrument connection is
 * present before calling this method, otherwise
 * unintended behavior may result.
 */
void GenericInstrument::wait() {
    _bus->write("*WAI\n");
}

/*!
 * \brief Pauses until previous commands are completed.
 *
 * Use this method to synchronize your application
 * with the SCPI command queue of the instrument.
 *
 * This method sends the "*OPC?" SCPI command
 * to the instrument. Upon receiving this query,
 * the instrument will complete all previous
 * SCPI commands before returning the string "1".
 * \c Pause waits for this return value before
 * returning to the caller.
 *
 * This command is used for synchronous
 * measurement sweeps.
 *
 * For a gentle introduction to synchronous
 * instrument programming, see Application Note
 * <a href="http://www.rohde-schwarz.de/file/1GP79_1E_SCPI_Programming_Guide_SigGens.pdf">
 * 1GP79-1E: Top Ten SCPI Programming Tips for
 * Signal Generators</a>. Although the App Note is
 * specifically for Signal Generators, many of
 * the concepts apply equally well to all
 * instruments.
 *
 * \note This command has a timeout of
 * \c GenericBus::timeout_ms() milliseconds.
 *
 * \return \c true if operation(s) completed.
 * \c false otherwise.
 * \sa pause(uint timeout_ms), GenericBus::timeout_ms()
 */
bool GenericInstrument::pause() {
    return _bus->query("*OPC?\n").toUInt() == 1;
}

/*!
 * \brief Pauses until previous commands are completed
 * or for \c timeout_ms, whichever comes first.
 * \param timeout_ms
 * \return \c true if operation(s) completed.
 * \c false otherwise
 * \sa pause()
 */
bool GenericInstrument::pause(uint timeout_ms) {
    uint oldTime = _bus->timeout_ms();
    _bus->setTimeout(timeout_ms);
    bool isOperationComplete = pause();
    _bus->setTimeout(oldTime);
    return isOperationComplete;
}

/*!
 * \brief Initialize poll-and-loop synchronization
 *
 * This command sets the Operation Complete
 * bit (bit 0) of the Event Status Register (ESR)
 * to zero. Call this command immediately after
 * the operation you want to synchronize to.
 *
 * When the instrument completes the current operation,
 * it will set the Operation Complete bit to
 * 1. Use the \c isOperationComplete() method
 * to check for this.
 *
 * For a gentle introduction to synchronous
 * instrument programming, see Application Note
 * <a href="http://www.rohde-schwarz.de/file/1GP79_1E_SCPI_Programming_Guide_SigGens.pdf">
 * 1GP79-1E: Top Ten SCPI Programming Tips for
 * Signal Generators</a>. Although the App Note is
 * specifically for Signal Generators, many of
 * the concepts apply equally well to all
 * instruments.
 * \sa isOperationComplete()
 */
void GenericInstrument::initializePolling() {
    _bus->write("*OPC\n");
}

/*!
 * \brief Polls instrument for operation status
 *
 * When used with \c initializePolling(),
 * this method returns \c true when the current
 * operation is complete.
 *
 * For a gentle introduction to synchronous
 * instrument programming, see Application Note
 * <a href="http://www.rohde-schwarz.de/file/1GP79_1E_SCPI_Programming_Guide_SigGens.pdf">
 * 1GP79-1E: Top Ten SCPI Programming Tips for
 * Signal Generators</a>. Although the App Note is
 * specifically for Signal Generators, many of
 * the concepts apply equally well to all
 * instruments.
 * \return \c true if operation is complete,
 * \c false otherwise
 * \sa initializePolling()
 */
bool GenericInstrument::isOperationComplete() {
    const uint opcBit = 0x1;
    uint esr = _bus->query("*ESR?\n").toUInt();
    return (esr & opcBit) == 1;
}

/*!
 * \brief Clears all errors
 *
 * Sends the "*CLS" SCPI command to
 * the instrument, which clears
 * all errors from the
 * error queue.  These errors are
 * discarded without being read
 * or handled.
 */
void GenericInstrument::clearStatus() {
    _bus->write("*CLS\n");
}
