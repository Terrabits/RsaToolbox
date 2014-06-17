

// RsaToolbox
#include "Definitions.h"
#include "Log.h"
using namespace RsaToolbox;

// Qt
#include <QDateTime>

/*!
 * \defgroup LogGroup Log
 * Module for creating detailed log files
 * that include instrument IO and
 * user-generated text.
 */

/*!
 * \class RsaToolbox::Log
 * \ingroup LogGroup
 * \brief \c %Log creates and manages a log
 * file containing a list of SCPI commands
 *
 * The \c %Log class can be attached to
 * various \c GenericBus and
 * \c GenericInstrument subclasses for
 * automatic documentation of SCPI commands.
 * %Log can also be written to manually.
 *
 * Here is an example of a \c %Log being used
 * in conjunction with a GenericInstrument:
 *
 * \code
    // Log file: "C:\Test Log.txt"
    // App name: "My App"
    // Version: 1.0.0
    Log log("C:\", "Test Log.txt", "My App", "1.0.0");

    // Instrument connection
    // Method: GPIB
    // Address: 17
    // Timeout: 1000 ms (1 second)
    GenericInstrument fsw(GPIB_CONNECTION, "17", 1000);
   \endcode
 *
 *
 * \sa GenericInstrument::useLog(), GenericBus::print()
 *
 */

/*!
 * \fn Log::closed()
 * \brief The signal \c %closed() is emitted whenever
 * the \c %Log object closes a log file.
 * \sa Log::opened(), Log::renamed(QString pathName)
 */

/*!
 * \fn Log::opened()
 * \brief The signal \c %opened() is emitted whenever
 * the \c %Log object opens a log file.
 * \sa Log::closed(), Log::renamed(QString pathName)
 */

/*!
 * \fn Log::renamed(QString pathName)
 * \brief The signal \c %renamed() is emitted whenever
 * the \c %Log object renames a log file. \c pathName
 * contains the path and file name of the new log file.
 * \sa Log::opened(), Log::closed()
 */

/*!
 * \brief The default constructor
 *
 * This constructor is provided for
 * compatibility in instances where a default
 * constructor is important, for example when
 * used as a property in a class.
 *
 * Instances created with this constructor are not meant to
 * be used. Such instances will return isOpen() == false or
 * isClosed() == true. Any other method calls (such as print)
 * may cause the application to crash.
 *
 * \param parent The parent QObject of this instance
 */
Log::Log(QObject *parent) :
    QObject(parent)
{
    _stream.setDevice(&_file);
}

/*!
 * \brief Constructor for creating a fully-functional
 * Log object.
 *
 * This constructor will create a log file in location
 * \c directory with name \c filename. For the purposes
 * of writing a header to the log, \c applicationName
 * and \c applicationVersion will be used.
 *
 * A call to \c isOpen() or \c isClosed() should be made
 * to confirm that the log file was successfully created.
 *
 * \param directory Location for the log file.
 * \param filename Log file file name.
 * \param applicationName The name of the current application
 * \param applicationVersion The version of the current application
 * \param parent The parent QObject
 */
Log::Log(QString directory, QString filename,
         QString applicationName, QString applicationVersion,
         QObject *parent) :
    QObject(parent)
{
    _stream.setDevice(&_file);
    reset(directory, filename, applicationName, applicationVersion);
}

/*!
 * \brief Destructor
 *
 * If applicable, all writes are
 * flushed to the log file and the file is closed.
 *
 */
Log::~Log() {
    _stream.flush();
    close();
}


/*!
 * \brief Returns open status of log file
 *
 * \return \c true if a log file is open; \c false otherwise
 */
bool Log::isOpen(void) {
    return(_file.isOpen());
}

/*!
 * \brief Returns closed status of the log file
 * \return \c true if a log file is not open; \c false otherwise
 */
bool Log::isClosed(void) {
    return(!isOpen());
}

/*!
 * \brief Opens the log file.
 *
 * The parameters for the log file
 * (\c directory, \c filename, \c applicationName,
 * \c applicationVersion) must be previously set.
 * A log file with these settings is opened, if
 * possible.
 */
void Log::open(void) {
    if (_file.isOpen() == false) {
        _file.open(QFile::WriteOnly);
        if (_file.isOpen())
            emit opened();
    }
}

/*!
 * \brief Closes the log file.
 *
 * If a log file is not open, this
 * method does nothing.
 */
void Log::close(void) {
    if (_file.isOpen()) {
        _stream.flush();
        _file.close();
        if (_file.isOpen() == false)
            emit closed();
    }
}

/*!
 * \brief Resets the log settings and (re)opens
 * a log file with the new settings.
 *
 * If a log is currently open, this method will close
 * it before proceeding. The effect of this method is
 * similar to the standard constructor.
 *
 * \param directory Location for the log file.
 * \param filename Log file file name.
 * \param applicationName The name of the current application
 * \param applicationVersion The version of the current application
 */
void Log::reset(QString directory, QString filename, QString applicationName, QString applicationVersion) {
    close();

    _directory = directory;
    _file.setFileName(directory + "/" + filename);
    _applicationName = applicationName;
    _applicationVersion = applicationVersion;
    open();
}

/*!
 * \brief Renames and reopens the log file.
 *
 * If applicable, the new log file contents will
 * be that of the old log file, but with the
 * directory and filename contained in \c pathName.
 *
 * \param pathName New path and filename for the log file.
 */
void Log::rename(QString pathName) {
    _file.rename(pathName);
    emit renamed(pathName);
}

/*!
 * \brief Prints a simple header to the log file
 *
 * The following is an example of the header:
    <tt>My Application Version 1.0.0
(C) 2013 Rohde & Schwarz America

Fri Dec 6 20:20:55 2013
</tt>
 *
 */
void Log::printApplicationHeader() {
        _stream << _applicationName << " Version " << _applicationVersion << endl;
        _stream << "(C) 2014 Rohde & Schwarz America" << endl << endl;
        _stream << QDateTime::currentDateTime().toString() << endl << endl;
}

/*!
 * \brief Prints \c text to the log
 *
 * If applicable, \c text is printed exactly
 * as it is to the current position of the log
 * file.
 *
 * \param text Formatted text to be added to the log
 */
void Log::print(QString text) {
    _stream << text;
    _stream.flush();
}

/*!
 * \brief Prints \c text to the log, followed by a line return character
 * \param text Formatted text to be added to the log, followed by a line return
 */
void Log::printLine(QString text) {
    _stream << text << "\n";
    _stream.flush();
}
