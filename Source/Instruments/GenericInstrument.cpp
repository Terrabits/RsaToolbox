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
    init();
}

GenericInstrument::GenericInstrument(ConnectionType type, QString address, QObject *parent) :
    QObject(parent)
{
    init();
    open(type, address);
}

bool GenericInstrument::open(ConnectionType type, const QString &address) {
    const uint bufferSize = 500;
    const uint timeout_ms = 1000;
    setBus(new VisaBus(type,       address,
                       bufferSize, timeout_ms,
                       this));
    return isOpen();
}
void GenericInstrument::close() {
    const bool connected = isOpen();
    _bus->disconnect ();
    _bus->deleteLater();
    _bus = new NoBus(this);
    if (connected) {
        emit disconnected();
    }
}
void GenericInstrument::setBus(GenericBus *bus) {
    close();
    _bus = bus;
    QObject::connect(_bus, SIGNAL(error()), this, SIGNAL(busError()));
    QObject::connect(_bus, SIGNAL(print(QString)), _log, SLOT(print(QString)));
    if (isOpen()) {
        emit connected();
    }
}

/*!
 * \brief Checks for an instrument connection
 * \return \c true if an instrument is connected,
 * \c false otherwise
 */
bool GenericInstrument::isOpen() const {
    return _bus->isOpen();
}
bool GenericInstrument::isResponding() {
    return isOpen() && !idString().isEmpty();
}
bool GenericInstrument::isLogging() const {
    return _log->isOpen();
}
bool GenericInstrument::startLog(QString filename, QString application, QString version) {
    stopLog();

    _log = new Log(filename, application, version, this);
    connect(_bus, SIGNAL(print(QString)), _log, SLOT(print(QString)));
    printInfo();
    return isLogging();
}
void GenericInstrument::stopLog() {
    _log->close();
    _log->deleteLater();
    _log = new Log(this);
}

void GenericInstrument::print(QString text) {
    _log->print(text);
}
void GenericInstrument::init() {
    _log = new Log  (this);
    _bus = new NoBus(this);
}
void GenericInstrument::printInfo() {
    if (!isLogging()) {
        return;
    }
    const bool blocked = _bus->blockSignals(true);
    print(info());
    _bus->blockSignals(blocked);
}
QString GenericInstrument::info() {
    QString info;
    QTextStream stream(&info);
    stream << "INSTRUMENT INFO" << endl;
    stream << "Connection: " << toString(_bus->connectionType()) << endl;
    stream << "Address:    " << _bus->address() << endl;
    if (isOpen()) {
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
    return info;
}

ConnectionType GenericInstrument::connectionType() const {
    return _bus->connectionType();
}

QString GenericInstrument::address() const {
    return _bus->address();
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
    if (isOpen())
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
    if (isOpen())
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
    if (isOpen())
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
    if (isOpen())
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
