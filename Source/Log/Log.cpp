

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
 * \param filename Log file name. Can include path.
 * \param appName The name of the current application
 * \param version The version of the current application
 * \param parent The parent QObject
 */
Log::Log(QString filename,
         QString appName, QString version,
         QObject *parent) :
    QObject(parent)
{
     open(filename, appName, version);
    _stream.setDevice(&_file);
    printHeader();
}

/*!
 * \brief Destructor
 *
 * If applicable, all writes are
 * flushed to the log file and the file is closed.
 *
 */
Log::~Log() {
    flush();
    close();
}


/*!
 * \brief Returns open status of log file
 * \return \c true if a log file is open
 */
bool Log::isOpen() const {
    return _file.isOpen();
}

/*!
 * \brief Returns the filename of the log file
 * \return Filename, including the path to log file.
 */
QString Log::filename() const {
    return _filename;
}

bool Log::open() {
    if (!_file.open(QFile::WriteOnly)) {
        return false;
    }

    emit opened();
    return true;
}
bool Log::open(QString filename, QString application, QString version) {
    close();

    _filename     = filename;
    _application  = application;
    _version      = version;
    _file.setFileName(_filename);
    return _file.open(QFile::WriteOnly);
}
void Log::close() {
    if (!isOpen()) {
        return;
    }

    flush();
    _file.close();
    emit closed();
}

void Log::flush() {
    if (!isOpen()) {
        return;
    }
    _stream.flush();
    _file  .flush();
}



/*!
 * \brief Renames and reopens the log file.
 *
 * If applicable, the new log file contents will
 * be that of the old log file, but with the
 * directory and filename contained in \c pathName.
 *
 * \param pathName New path and filename for the log file.
 * \return \c true if successful
 */
bool Log::rename(QString filename) {
    if (!isOpen()) {
        return false;
    }

    flush();
    if (!_file.rename(filename)) {
        return false;
    }

    emit renamed(filename);
    return true;
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
 * \return \c true if successful
 */
bool Log::printHeader() {
    if (!isOpen())
        return false;

    QString date(__DATE__);
    date.remove(0, date.size()-4);

    _stream << _application << " Version " << _version << endl;
    _stream << "(C) " + date + " Rohde & Schwarz North America" << endl << endl;
    _stream << QDateTime::currentDateTime().toString() << endl << endl;
    return true;
}

/*!
 * \brief Prints \c text to the log
 *
 * If applicable, \c text is printed exactly
 * as it is to the current position of the log
 * file.
 *
 * \param text Formatted text to be added to the log
 * \return \c true if successful
 */
bool Log::print(QString text) {
    if (!isOpen()) {
        return false;
    }

    _stream << text;
    flush();
    return true;
}
