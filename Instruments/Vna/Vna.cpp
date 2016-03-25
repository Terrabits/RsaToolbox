#include "Vna.h"


#include "General.h"
#include "VisaBus.h"
#include "IndexName.h"
#include "VnaScpi.h"
using namespace RsaToolbox;

// Qt
#include <QUuid>
#include <QDebug>


/*! \defgroup VnaGroup Vna
 * Classes for controlling a Rohde \& Schwarz VNA
 *
 * \ingroup InstrumentGroup
 */

/*!
 * \class RsaToolbox::Vna
 * \ingroup VnaGroup
 * \brief The \c %Vna class provides an
 * interface for controlling a
 * Rohde \& Schwarz Vector Network Analyzer.
 *
 * \c %Vna is derived from the \c GenericInstrument
 * class, and as such has the ability to
 * connect to a Vna using a \c GenericBus
 * subclass such as \c VisaBus.
 * It also can connect to a \c Log
 * for SCPI logging.
 *
 * In addition to the required basic
 * commands implemented in \c GenericInstrument,
 * \c %Vna implements most of the functionality
 * specific to Rohde \& Schwarz VNAs. It does
 * so in a style and manner that is consistent
 * with Qt's style guidelines and native
 * data types.
 *
 * \c Vna is organized into parts that
 * represent each of the logical
 * elements of R\&S VNAs, including:
 *
 * \c Vna::fileSystem()
 * \c Vna::channel()
 * \c Vna::trace()
 * \c Vna::diagram()
 *
 * As an example, the channels can be
 * queried by calling Vna::channels().
 * Each channel can then be manipulated
 * through the Vna::channel() interface.
 *
 * Convenience functions are also provided
 * that allow you to determine the properties
 * of a specific \c %Vna. These can
 * be found in:
 * \c Vna::properties()
 *
 * Some examples include:
 * VnaProperties::isZnbFamily()
 * determines whether or not you are
 * currently controlling a ZNB.
 *
 * VnaProperties::minimumFrequency_Hz()
 * determines the minimum frequency of
 * the instrument.
 *
 * VnaProperties::hasSourceAttenuators()
 * determines if the source attenuator
 * option is installed on the instrument.
 *
 * Global VNA settings can be found
 * through the \c Vna::settings()
 * interface. These settings include
 * things like user-preset, emulation
 * modes and port power limits. These
 * settings effect all channels and
 * traces.
 *
 * \sa GenericInstrument, GenericBus, Log
 */

/*!
 * \brief Default constructor
 *
 * This constructor does not connect
 * to an instrument, and should
 * not be used unless re-initialized
 * through a call to Vna::resetBus()
 *
 * \param parent Optional parent QObject
 */
Vna::Vna(QObject *parent)
    : GenericInstrument(parent),
      _properties(this),
      _settings(this),
      _fileSystem(this),
      _set(this, ""),
      _calKit(this, NameLabel()),
      _calibrate(this),
//      _calGroup(),
      _channel(this, 0),
      _trace(this, ""),
      _diagram(this, 0),
      _switchMatrix(this, 0),
      _calUnit(this, "")
{
    //
}

/*!
 * \brief Constructor connects to the instrument
 * specified in \c bus
 *
 * Before controlling the instrument, it is
 * good practice to call Vna::isConnected()
 * to make sure that the instrument connection
 * is valid.
 *
 * \param bus An instrument connection
 * \param parent Optional parent QObject
 * \sa GenericBus
 */
Vna::Vna(GenericBus *bus, QObject *parent)
    : GenericInstrument(bus, parent),
      _properties(this),
      _settings(this),
      _fileSystem(this),
      _set(this, ""),
      _calKit(this, NameLabel()),
      _calibrate(this),
//      _calGroup(),
      _channel(this, 0),
      _trace(this, ""),
      _diagram(this, 0),
      _switchMatrix(this, 0),
      _calUnit(this, "")
{
    //
}

/*!
 * \brief Constructor connects to the instrument
 * at \c address
 *
 * Before controlling the instrument, it is
 * good practice to call Vna::isConnected()
 * to make sure that the instrument connection
 * is valid.
 *
 * \param type Connection type
 * \param address Address of the instrument
 * \param parent Optional parent QObject
 * \sa ConnectionType
 */
Vna::Vna(ConnectionType type, QString address, QObject *parent)
    : GenericInstrument(type, address, parent),
      _properties(this),
      _settings(this),
      _fileSystem(this),
      _set(this, ""),
      _calKit(this, NameLabel()),
      _calibrate(this),
//      _calGroup(),
      _channel(this, 0),
      _trace(this, ""),
      _diagram(this, 0),
      _switchMatrix(this, 0),
      _calUnit(this, "")
{
    //
}

/*!
 * \brief Prints instrument info to the log file
 *
 * Below is an example result of a call
 * to \c printInfo() with a ZNB connected:
    <tt>VNA INSTRUMENT INFO
Connection:       TCPIP
Address:          192.168.0.1
Make:             Rohde & Schwarz
Model:            ZNB
Serial No:        12345678901234
Firmware Version: 1.93.2.45
Min Frequency:    9.0 KHz
Max Frequency:    8.5 GHz
Number of Ports:  4
Options:          ZNB-K2
                  ZNB-K4
                  ZNB-K14
                  ZNB-K17
                  ZNB-K19
                  ZNB8-B24
                  ZNB8-B31
                  ZNB8-B32
                  ZNB8-B33
                  ZNB8-B34
                  ZNB-B81
                  ZNB-B2
                  ZN-B12</tt>
 * \sa Vna::useLog()
 */
void Vna::printInfo(QString &info) {
    QTextStream stream(&info);
    stream << "VNA INSTRUMENT INFO" << endl;
    if (isConnected()) {
        if (_properties.isKnownModel()) {
            stream << "Connection:       " << toString(connectionType()) << endl;
            stream << "Address:          " << address() << endl;
            stream << "Make:             Rohde & Schwarz" << endl;
            stream << "Model:            " << toString(_properties.model()) << endl;
            stream << "Serial No:        " << _properties.serialNumber() << endl;
            stream << "Firmware Version: " << _properties.firmwareVersion() << endl;
            stream << "Min Frequency:    " << formatValue(_properties.minimumFrequency_Hz(), 1, Units::Hertz) << endl;
            stream << "Max Frequency:    " << formatValue(_properties.maximumFrequency_Hz(), 1, Units::Hertz) << endl;
            stream << "Number of Ports:  " << _properties.physicalPorts() << endl;
            if (!optionsString().isEmpty()) {
                stream << "Options:          ";
                stream << toString(_properties.optionsList(), "\n                  ");
                stream << endl;
            }
        }
        else {
            stream << "Make: Unknown" << endl;
            stream << "*IDN?\n  " << idString() << endl << endl << endl;
        }
    }
    else {
        stream << "Instrument not found" << endl;
        stream << "Connection:       " << toString(connectionType()) << endl;
        stream << "Address:          " << address() << endl << endl << endl;
    }
    stream << endl << endl;
    stream.flush();
}

/*!
 * \brief Reads a \c QRowVector of data from the instrument
 * \param bufferSize_B Buffer size, in Bytes
 * \param timeout_ms Timeout, in milliseconds
 * \return Data read, in QRowVector format
 * \sa QRowVector, parseQRowVector(), queryVector()
 */
QRowVector Vna::readVector(uint bufferSize_B, uint timeout_ms) {
    QByteArray result = binaryRead(bufferSize_B, timeout_ms);
    while (result.size() < 2) {
        int prevSize = result.size();
        result += binaryRead(bufferSize_B, timeout_ms);
        if (result.size() <= prevSize)
            break;
    }
    if (result.size() < 2)
        return QRowVector();
    if (result[0] != '#')
        return QRowVector();
    int sizeSize = result.mid(1,1).toInt();
    if (sizeSize <= 0)
        return QRowVector();

    while (result.size() < 2 + sizeSize) {
        int prevSize = result.size();
        result += binaryRead(bufferSize_B, timeout_ms);
        if (result.size() <= prevSize)
            break;
    }
    if (result.size() < 2 + sizeSize)
        return QRowVector();
    int size = result.mid(2, sizeSize).toInt();
    if (size <= 0)
        return QRowVector();

    while (result.size() < 2 + sizeSize + size) {
        int prevSize = result.size();
        result += binaryRead(bufferSize_B, timeout_ms);
        if (result.size() <= prevSize)
            break;
    }
    if (result.size() < 2 + sizeSize + size) {
        return QRowVector();
    }
    else {
        return(toQRowVector(result));
    }
}

/*!
 * \brief Reads a \c ComplexRowVector from the instrument
 * \param bufferSize_B Buffer size, in Bytes
 * \param timeout_ms Timeout, in milliseconds
 * \return Data read, in \c ComplexRowVector format
 * \sa ComplexRowVector, parseComplex(), queryComplexVector()
 */
ComplexRowVector Vna::readComplexVector(uint bufferSize_B, uint timeout_ms) {
    QRowVector result = readVector(bufferSize_B, timeout_ms);
    return parseComplex(result);
}

/*!
 * \brief Writes \c scpi to the instrument and reads
 *  response data in \c QRowVector format
 * \param scpi SCPI command to send to the instrument
 * \param bufferSize_B Buffer size for reading, in Bytes
 * \param timeout_ms Timeout for read, in milliseconds
 * \return Data read, in \c QRowVector format
 * \sa QRowVector, parseQRowVector(), readVector()
 */
QRowVector Vna::queryVector(QString scpi, uint bufferSize_B, uint timeout_ms) {
    bool isReadAscii = settings().isReadAsciiFormat();
    bool isRead32Bit = settings().isRead32BitBinaryFormat();
    bool isBigEndian = settings().isBigEndian();

    settings().setRead64BitBinaryFormat();
    settings().setLittleEndian();
    write(scpi);
    QRowVector result = readVector(bufferSize_B, timeout_ms);

    if (isReadAscii)
        settings().setReadAsciiFormat();
    if (isRead32Bit)
        settings().setRead32BitBinaryFormat();
    if (isBigEndian)
        settings().setBigEndian();

    return(result);
}

/*!
 * \brief Writes \c scpi to the instrument and reads
 *  response data in \c ComplexRowVector format
 * \param scpi SCPI command to send to the instrument
 * \param bufferSize_B Buffer size for reading, in Bytes
 * \param timeout_ms Timeout for read, in milliseconds
 * \return Data read, in \c ComplexRowVector format
 * \sa ComplexRowVector, parseComplex(), readComplexVector()
 */
ComplexRowVector Vna::queryComplexVector(QString scpi, uint bufferSize_B, uint timeout_ms) {
    bool isReadAscii = settings().isReadAsciiFormat();
    bool isRead32Bit = settings().isRead32BitBinaryFormat();
    bool isBigEndian = settings().isBigEndian();

    settings().setRead64BitBinaryFormat();
    settings().setLittleEndian();
    write(scpi);
    ComplexRowVector result = readComplexVector(bufferSize_B, timeout_ms);

    if (isReadAscii)
        settings().setReadAsciiFormat();
    if (isRead32Bit)
        settings().setRead32BitBinaryFormat();
    if (isBigEndian)
            settings().setBigEndian();

    return(result);
}

/*!
 * \brief Checks the instrument for a command error
 *
 * Malformed or inappropriate commands will
 * generate an error with the instrument. It
 * can be helpful to periodically call \c isError()
 * to catch and to handle such errors. To retrieve
 * the specific error(s) that occured (if any),
 * see isError(QStringList &errors)
 *
 * \return \c true if there is a SCPI error;
 * \c false otherwise
 * \sa Vna::isError(QStringList &errors)
 */
bool Vna::isError() {
    QList<int> codes;
    QStringList messages;
    if (errors(codes, messages)) {
        QString text = "SCPI Errors:\n";
        for (int i = 0; i < messages.size(); i++) {
            QString format = "%1: %2\n";
            text += format.arg(codes[i]).arg(messages[i]);
        }
        text += "\n";
        emit print(text);
        return true;
    }
    else {
        return false;
    }
}

bool Vna::nextError(int &code, QString &message) {
    code = 0;
    message = "";

    QString result = query(":SYST:ERR?\n").trimmed();
    int sep = result.indexOf(",");
    code = result.mid(0, sep).toInt();
    message = result.mid(sep+1);
    message.remove(0,1);
    message.chop(1);
    return code != 0;
}
bool Vna::nextError(QString &message) {
    int code;
    return nextError(code, message);
}
bool Vna::errors(QList<int> &codes, QStringList &messages) {
    codes.clear();
    messages.clear();

    int code;
    QString message;
    while (nextError(code, message)) {
        codes << code;
        messages << message;
    }
    return !messages.isEmpty();
}
bool Vna::errors(QStringList &messages) {
    messages.clear();

    int code;
    QString message;
    while (nextError(code, message)) {
        messages << message;
    }
    return !messages.isEmpty();
}
/**
 * \name Set
 * VNA Sets
 * \sa VnaSet
 * @{*/

/*!
 * \brief Retrieve interface to set \c name
 * \param name Name of set
 * \return \c VnaSet object for \c name
 */
QStringList Vna::sets() {
    QString scpi = ":MEM:CAT?\n";
    return query(":MEM:CAT?\n").trimmed().remove('\'').split(',', QString::SkipEmptyParts);
}
QString Vna::activeSet() {
    QStringList setList = sets();
    if (setList.size() == 0)
        return QString();
    if (setList.size() == 1)
        return setList.first();

    uint channel = channels().first();
    QString name = QUuid::createUuid().toString().remove('{').remove('}').remove('-');
    name.prepend("tr");
    createTrace(name, channel);

    foreach (QString s, setList) {
        set(s).select();
        if (traces().contains(name)) {
            deleteTrace(name);
            return s;
        }
    }

    // Else
    return QString();
}
QString Vna::newSet() {
    QStringList setList = sets();
    QString name = "Set%1";
    uint i = 1;
    while (setList.contains(name.arg(i), Qt::CaseInsensitive))
        i++;
    name = name.arg(i);

    newSet(name);
    return name;
}
void Vna::newSet(const QString &name) {
    QString scpi = ":MEM:DEF \'%1\'\n";
    scpi = scpi.arg(name);
    write(scpi);
}
void Vna::openSet(QString filePathName) {
    QString extension;
    if (properties().isZvaFamily())
        extension = ".zvx";
    else
        extension = ".znx";
    if (!filePathName.endsWith(extension, Qt::CaseInsensitive))
        filePathName += extension;

    QString scpi = ":MMEM:LOAD:STAT 1,\'%1\'\n";
    scpi = scpi.arg(filePathName);

    QString directory = fileSystem().directory();
    fileSystem().changeDirectory(VnaFileSystem::Directory::RECALL_SETS_DIRECTORY);
    write(scpi);
    fileSystem().changeDirectory(directory);
    pause();
}
void Vna::closeActiveSet() {
    const QString _activeSet(activeSet());
    if (!_activeSet.isEmpty())
        closeSet(_activeSet);
}
void Vna::closeSet(const QString &name) {
    QString scpi = ":MEM:DEL \'%1\'\n";
    scpi = scpi.arg(name);
    write(scpi);
}
void Vna::closeSets() {
    write(":MEM:DEL:ALL\n");
}
bool Vna::saveActiveSet(QString &filePathName) {
    QString _activeSet = activeSet();
    if (_activeSet.isEmpty())
        return false;

    set(_activeSet).save(filePathName);
    return true;
}
void Vna::deleteSet(QString filePathName) {
    QString extension;
    if (properties().isZvaFamily())
        extension = ".zvx";
    else
        extension = ".znx";
    if (!filePathName.endsWith(extension, Qt::CaseInsensitive))
        filePathName += extension;

    QString directory = fileSystem().directory();
    fileSystem().changeDirectory(VnaFileSystem::Directory::RECALL_SETS_DIRECTORY);
    fileSystem().deleteFile(filePathName);
    fileSystem().changeDirectory(directory);
}
VnaSet &Vna::set(const QString &name) {
    _set = VnaSet(this, name);
    return _set;
}

/** @} */


/**
 * \name Properties
 * Immutable properties of the instrument
 * \sa VnaProperties
 * @{*/

/*!
 * \brief Returns the Vna properties interface
 *
 * The Vna properties interface is used
 * to determine the physical properties
 * of the Vna. This can be useful when
 * creating applications that rely on
 * the presence of certain properties. It
 * can also be useful in providing a
 * user with a range of valid settings
 * and preventing an error from occuring.
 *
 * See VnaProperties
 *
 * \return VnaProperties interface
 * \sa VnaProperties
 */
VnaProperties &Vna::properties() {
    return(_properties);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaProperties object.
 *
 * A dynamically-allocated VnaProperties
 * interface can be used apart from the
 * Vna object itself, so long as the
 * original Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see properties() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaProperties interface
 * \sa new, delete, QScopedPointer, VnaProperties
 */
VnaProperties *Vna::takeProperties() {
    return(new VnaProperties(this));
}
/** @} */

/**
 * \name Settings
 * Global instrument settings
 * \sa VnaSettings
 * @{*/

/*!
 * \brief Returns the Vna settings interface
 *
 * The Vna settings interface includes
 * all global VNA settings. Example
 * Vna-wide settings include:
 * - displayOn/off
 * - colorScheme
 * - userPreset
 *
 * See VnaSettings
 *
 * \return VnaSettings interface
 * \sa VnaSettings
 */
VnaSettings &Vna::settings() {
    return(_settings);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaSettings object.
 *
 * A dynamically-allocated VnaSettings
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see settings() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated VnaSettings
 * interface
 * \sa new, delete, QScopedPointer, VnaSettings
 */
VnaSettings *Vna::takeSettings() {
    return(new VnaSettings(this));
}
/** @} */

/**
 * \name File System
 * Manipulates the underlying file system
 * (files, directories, etc) of the instrument.
 * \sa VnaFileSystem
 * @{*/

/*!
 * \brief Returns the Vna file system interface
 *
 * The Vna file system interface provides
 * methods for controlling the underlying
 * file system on the VNA. Files can be
 * copied, moved, deleted, uploaded and
 * downloaded, among other things.
 *
 * See VnaFileSystem
 *
 * \return VnaFileSystem interface
 * \sa VnaFileSystem
 */
VnaFileSystem &Vna::fileSystem() {
    return(_fileSystem);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaFileSystem object.
 *
 * A dynamically-allocated VnaFileSystem
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see fileSystem() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaFileSystem interface
 * \sa new, delete, QScopedPointer, VnaSettings
 */
VnaFileSystem *Vna::takeFileSystem() {
    return(new VnaFileSystem(this));
}

/** @} */

/**
 * \name Calibration Kits
 * Queries and manipulates calibration kits
 * \sa VnaCalKit
 * @{*/

/*!
 * \brief Retrieve all valid connector types
 * \return QVector containing all connector types
 */
void Vna::defineCustomConnector(const Connector &connector) {
    QString scpi = ":CORR:CONN \'%1\',%2,%3,%4,%5\n";
    scpi = scpi.arg(VnaScpi::toTypeString(connector));
    scpi = scpi.arg(VnaScpi::toString(connector.mode()));
    if (connector.isGenderSpecific())
        scpi = scpi.arg("GEND");
    else
        scpi = scpi.arg("NGEN");
    scpi = scpi.arg(connector.permittivity());
    if (connector.isTemMode())
        scpi = scpi.arg(connector.impedance_Ohms());
    else
        scpi = scpi.arg(connector.cutoffFrequency_Hz());
    write(scpi);
}
void Vna::deleteConnector(const QString &name) {
    // [SENSe<Ch>:]CORRection:CONNection:DELete '<conn_name>'
    QString scpi = ":CORR:CONN:DEL \'%1\'\n";
    scpi = scpi.arg(name);
    write(scpi);
}
void Vna::deleteConnector(const Connector &connector) {
    deleteConnector(VnaScpi::toTypeString(connector));
}

QVector<Connector> Vna::connectorTypes() {
    QString scpi = ":CORR:CONN:CAT?\n";
    QStringList typeList =
            query(scpi).trimmed().remove('\'').split(',');
    QVector<Connector> types;
    foreach (QString type, typeList) {
        Connector c;
        c.setType(VnaScpi::toConnectorType(type));
        if (c.isCustomType())
            c.setCustomType(type);
        types.append(c);
    }

    for (int i = 0; i < types.size(); i++) {
        scpi = ":CORR:CONN? \'%1\'\n";
        scpi = scpi.arg(VnaScpi::toTypeString(types[i]));
        QStringList results = query(scpi).trimmed().split(",");
        if (results.size() < 5)
            continue;

        // results[0] = connector type (why?)
        // results[1] = mode (TEM | WGUide)
        // results[2] = gender (GENDer | NGENder)
        // results[3] = permittivity
        // results[4] = impedance | cutoff freq (Hz)
        if (results[2].startsWith("NGEN", Qt::CaseInsensitive))
            types[i].setGender(Connector::Gender::Neutral);
        else
            types[i].setGender(Connector::Gender::Male);
        types[i].setPermittivity(results[3].toDouble());
        if (VnaScpi::toConnectorMode(results[1]) == Connector::Mode::Waveguide)
            types[i].setWaveguideMode(results[4].toDouble());
        else
            types[i].setTemMode(results[4].toDouble());
    }

    return types;
}

/*!
 * \brief Test for the presense of connector \c type
 * \param type Type of connector to test for
 * \return \c true if \c type exists;
 * \c false otherwise
 */
bool Vna::isConnectorType(const Connector &type) {
    QVector<Connector> types = connectorTypes();
    foreach (Connector _type, types) {
        if (type.isType(_type))
            return(true);
    }
    // else
    return(false);
}

/*!
 * \brief Test for the presense of user-defined
 * connector \c userDefinedType
 * \param userDefinedType User-defined connector type
 * \return \c true if \c userDefinedType exists;
 * \c false otherwise
 */
bool Vna::isConnectorType(const QString &userDefinedType) {
    Connector type;
    type.setCustomType(userDefinedType);
    return(isConnectorType(type));
}

/*!
 * \brief Query if connector of type \c type is gender neutral
 * \param type Connector type (other properties are ignored)
 * \return \c true if gender neutral connector; \c false otherwise
 */
bool Vna::isConnectorGenderNeutral(Connector type) {
    QString scpi = "CORR:CONN? \'%1\'\n";
    scpi = scpi.arg(VnaScpi::toTypeString(type));
    QStringList results = query(scpi).trimmed().split(",");
    // results[0] = connector type (why?)
    // results[1] = mode (TEM | WGUide)
    // results[2] = gender (GENDer | NGENder)
    // results[3] = permittivity
    // results[4] = impedance | cutoff freq (Hz)
    if (results.size() < 3)
        return false;
    else
        return results[2].toUpper() == "NGEN";
}

/*!
 * \brief Test for presence of a Calibration Kit
 * \param nameLabel The name and label of the desired cal kit
 * \return \c true if cal kit exists;
 * \c false otherwise
 */
bool Vna::isCalKit(NameLabel nameLabel) {
    QVector<NameLabel> kits = calKits();
    return(kits.contains(nameLabel));
}

/*!
 * \brief Test for presence of a Calibration Kit
 * \param name
 * \param label
 * \return \c true if the cal kit exists;
 * \c false otherwise
 */
bool Vna::isCalKit(QString name, QString label) {
    return(isCalKit(NameLabel(name, label)));
}

/*!
 * \brief Test for the absence of a Calibration Kit
 * \param nameLabel Name and label of the cal kit
 * \return \c true if cal kit does not exist;
 * \c false otherwise
 */
bool Vna::isNotCalKit(NameLabel nameLabel) {
    return(!isCalKit(nameLabel));
}

/*!
 * \brief Test for the absence of a Calibration Kit
 * \param name
 * \param label
 * \return \c true if the cal kit exists;
 * \c false otherwise
 */
bool Vna::isNotCalKit(QString name, QString label) {
    return(!isCalKit(name, label));
}

/*!
 * \brief Returns a list of all available
 * calibration kits
 * \return All calibration kits
 */
QVector<NameLabel> Vna::calKits() {
    QVector<Connector> connectors = connectorTypes();
    QVector<NameLabel> kits;
    foreach(Connector type, connectors) {
        kits += calKits(type);
    }
    return(kits);
}

/*!
 * \brief Returns a list of all calibration kits
 * of a particular connector \c type
 *
 * \note The gender of \c type is ignored
 *
 * \param type Connector type
 * \return Cal kits of connector \c type
 */
QVector<NameLabel> Vna::calKits(Connector type) {
    if (type.isCustomType())
        return(calKits(type.customType()));
    else
        return(calKits(type.type()));
}

/*!
 * \brief Returns a list of all calibration kits
 * of a particular connector \c type
 * \param type Connector type
 * \return Cal kits of connector \c type
 */
QVector<NameLabel> Vna::calKits(Connector::Type type) {
    return(calKits(VnaScpi::toString(type)));
}

/*!
 * \brief Returns a list of all calibration kits
 * of a particular user-defined connector type
 * \param userDefinedConnectorType User-defined
 * connector type
 * \return Cal kits of connector \c type
 */
QVector<NameLabel> Vna::calKits(QString customType) {
    QString scpi = ":CORR:CKIT:LCAT? \'%1\'\n";
    scpi = scpi.arg(customType);
    QString result = query(scpi, 2000).trimmed();
    return NameLabel::parse(result, ",", "\'");
}

/*!
 * \brief Deletes a calibration kit
 * \param calkit Name and label of the calibration
 * kit to delete
 */
void Vna::deleteCalKit(NameLabel calkit) {
    QString scpi = ":CORR:CKIT:LDEL \'%1\', \'%2\'\n";
    scpi = scpi.arg(calkit.name()).arg(calkit.label());
    write(scpi);
}

/*!
 * \brief Imports a calibration kit from a file
 *
 * Most calibration kits come with a
 * characterization file that must be
 * used to correctly apply the calibration
 * results. Use this method to import the
 * calibration kit file.
 *
 * \note Rohde \& Schwarz Calibration Kits
 * have the file extension .calkit
 *
 * \param pathName Directory and filename of
 * the cal kit file
 */
void Vna::importCalKit(QString pathName) {
    QFileInfo file_info(pathName);
    QString filename;
    if (file_info.path().isEmpty()) {
        filename = fileSystem().directory(VnaFileSystem::CAL_KIT_DIRECTORY);
        filename += file_info.fileName();
    }
    if (!filename.endsWith(".calkit", Qt::CaseInsensitive))
        filename += ".calkit";
    filename = QDir::toNativeSeparators(file_info.filePath());

    QString scpi = ":MMEM:LOAD:CKIT \'%1\'\n";
    scpi = scpi.arg(filename);
    write(scpi);
}

/*!
 * \brief Exports a calibration kit to a file
 *
 * This method is useful when creating a custom
 * cal kit for use on multiple VNAs.
 *
 * \note The exported file is proprietary.
 * The file's extension is .calkit
 *
 * \param calkit The name and label of the cal
 * kit to export
 * \param pathName Directory and filename of
 * the exported cal kit file
 */
void Vna::exportCalKit(NameLabel calkit, QString pathName) {
    QFileInfo file_info(pathName);
    QString filename;
    if (file_info.path().isEmpty())
        filename = fileSystem().directory(VnaFileSystem::CAL_KIT_DIRECTORY);
    else
        filename = QDir::toNativeSeparators(file_info.filePath());
    filename += file_info.baseName() + ".calkit";

    QString scpi = ":MMEM:STOR:CKIT:WLAB \'%1\',\'%2\',\'%3\'\n";
    scpi = scpi.arg(calkit.name()).arg(calkit.label());
    scpi = scpi.arg(pathName);
    write(scpi);
}

/*!
 * \brief Returns an interface to the calibration kit
 * specified by \c nameLabel
 *
 * This interface is used to manipulate a
 * calibration kit. Standards contained in
 * the kit can be queried, added and deleted
 * through this interface.
 *
 * See VnaCalKit
 *
 * \param nameLabel Name and label of the
 * calibration kit
 * \return VnaCalKit interface
 * \sa VnaCalKit
 */
VnaCalKit &Vna::calKit(NameLabel nameLabel) {
    _calKit = VnaCalKit(this, nameLabel);
    return(_calKit);
}

/** @} */

/**
 * \name Calibrate
 * Performs calibration on all channels
 * \note The ZVA-family of instruments
 * does not support this feature.
 * \sa VnaCalibrate, VnaChannel::calibrate()
 * @{*/

// Calibration
void Vna::multiChannelCalibrationOn(bool isOn) {
    if (properties().isZvaFamily()) {
        if (isOn)
            emit print("Note:\nMulti-channel calibration enabled by default on ZVA.\n\n");
        else
            emit print("Note:\nCannot disable multi-channel calibration on ZVA.\n\n");

        return;
    }

    QString scpi;
    if (isOn)
        scpi = ":CORR:COLL:CHAN:MCTY 1\n";
    else
        scpi = ":CORR:COLL:CHAN:MCTY 0\n";
    write(scpi);
}
void Vna::multiChannelCalibrationOff(bool isOff) {
    multiChannelCalibrationOn(!isOff);
}

QVector<uint> Vna::calibratedChannels() {
    QVector<uint> _channels = channels();
    QVector<uint> _calibratedChannels;
    foreach (uint i, _channels) {
        if (channel(i).isCalibrated())
            _calibratedChannels.append(i);
    }
    return _calibratedChannels;
}

/*!
 * \brief Returns the Vna calibration interface
 *
 * The Vna calibration interface is
 * used to perform an
 * OSM, UOSM or TOSM calibration,
 * among others, across all channels.
 * If you would like to perform a channel-
 * specific calibration,
 * see VnaChannel::calibrate()
 *
 * \note The ZVA-family of network
 * analyzers does not currently support
 * calibrating all channels at once.
 *
 * \return VnaCalibrate interface
 * \sa VnaCalibrate
 */
VnaCalibrate &Vna::calibrate() {
    return(_calibrate);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaCalibrate object.
 *
 * A dynamically-allocated VnaCalibrate
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see calibrate() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaCalibrate interface
 * \sa new, delete, QScopedPointer, VnaCalibrate
 */
VnaCalibrate *Vna::takeCalibrate() {
    return(new VnaCalibrate(this));
}

/** @} */

/**
 * \name Calibration Groups
 * Addresses calibration groups
 * \sa VnaCalibrate, VnaChannel::calibrate()
 * @{*/

/*!
 * \brief Vna::deleteCalGroup
 * \param name
 */
void Vna::deleteCalGroup(QString name) {
    if (!name.endsWith(".cal", Qt::CaseInsensitive))
        name += ".cal";

    QString scpi = ":MMEM:DEL:CORR \'%1\'\n";
    scpi = scpi.arg(name);
    write(scpi);
}

/*!
 * \brief Retrieves saved calibrations (groups) from the calibration pool
 * \return List of cal groups (saved calibrations)
 */
QStringList Vna::calGroups() {
    QString currentDirectory = fileSystem().directory();
    fileSystem().changeDirectory(VnaFileSystem::CAL_GROUP_DIRECTORY);
    QStringList files = fileSystem().files();
    fileSystem().changeDirectory(currentDirectory);

    QStringList calGroups;
    QStringListIterator i(files);
    foreach(QString file, files) {
        if (file.endsWith(".cal", Qt::CaseInsensitive)) {
            file.remove(".cal", Qt::CaseInsensitive);
            calGroups.append(file);
        }
    }
    return(calGroups);
}

/** @} */

/**
 * \name Channels
 * Query, create, delete and
 * control channels
 * \sa VnaChannel
 * @{*/

/*!
 * \brief Checks for the presence of
 * channel \c index.
 * \param index Channel number to test for
 * \return \c true of channel \c index exists;
 * \c false otherwise
 */
bool Vna::isChannel(uint index) {
    return channels().contains(index);
}
/*!
 * \brief Queries existence of channel \c name
 * \param name Name of channel to query
 * \return \c true if channel \c name exists;
 * false otherwise
 */
bool Vna::isChannel(QString name) {
    QString result = query(":CONF:CHAN:CAT?\n", 5000).trimmed();
    QVector<IndexName> indexNames;
    indexNames = IndexName::parse(result, ",", "\'");
    return IndexName::names(indexNames).contains(name);
}

/*!
 * \brief Checks for the absense of
 * channel \c index.
 * \param index Channel number
 * \return \c true if channel \c index
 * does not exist; \c false otherwise
 */
bool Vna::isNotChannel(uint index) {
    return(!isChannel(index));
}
/*!
 * \brief Queries for existence of \c name
 * \param name Name of channel
 * \return \c true if channel \c name does not exist;
 * \c false otherwise.
 */
bool Vna::isNotChannel(QString name) {
    return(!isChannel(name));
}

/*!
 * \brief Returns the number of channels
 * that are present
 *
 * \note Channels are usually, but not
 * necessarily, sequential. Use \c
 * Vna::channels() to get an actual
 * list of channels present.
 *
 * \return Number of channels present
 */
uint Vna::numberOfChannels() {
    return(uint(channels().size()));
}

/*!
 * \brief Retrieves index of channel \c name
 *
 * \note \c 0 is returned if \c name does
 * not exist.
 *
 * \param name Name of channel
 * \return Index of channel \c name;
 * \c 0 if \c name does not exist.
 */
uint Vna::channelId(QString name) {
    if (name.isEmpty())
        return(0);

    QString scpi = ":CONF:CHAN:NAME:ID? \'%1\'\n";
    scpi = scpi.arg(name);

    QString result = query(scpi).trimmed();
    clearStatus();
    return(result.toUInt());
}

/*!
 * \brief Creates a channel with the next
 * available index value
 *
 * \note This method creates a channel
 * with an index equal to MAX_INDEX + 1.
 * For a list of channels that is not
 * sequential, this is not equal to
 * numberOfChannels() + 1.
 *
 * \return Index of the created channel
 */
uint Vna::createChannel() {
    QVector<uint> channelList = channels();
    if (channelList.isEmpty()) {
        createChannel(1);
        return(1);
    }
    else {
        uint newChannel = max(channelList) + 1;
        createChannel(newChannel);
        return(newChannel);
    }
}

/*!
 * \brief Creates the channel \c index
 *
 * \note If the channel \c index
 * already exists, this method has
 * no effect.
 *
 * \param index Number of the channel to create
 */
void Vna::createChannel(uint index) {
    QString scpi(":CONF:CHAN%1 1\n");
    scpi = scpi.arg(index);
    write(scpi);
}

/*!
 * \brief Returns a list of all active channels
 * \return All active (on) channels
 */
QVector<uint> Vna::channels() {
    QString result = query(":CONF:CHAN:CAT?\n", 5000).trimmed();
    QVector<IndexName> indexNames;
    indexNames = IndexName::parse(result, ",", "\'");
    return(IndexName::indices(indexNames));
}

/*!
 * \brief Deletes channel \c index
 * \param index Channel to delete
 */
void Vna::deleteChannel(uint index) {
    QString scpi = ":CONF:CHAN%1 0\n";
    scpi = scpi.arg(index);
    write(scpi);
}

/*!
 * \brief Deletes channel \c name, if it exists
 *
 * \note If channel \c name does not exist,
 * this function does nothing.
 *
 * \param name Name of channel to delete
 */
void Vna::deleteChannel(QString name) {
    uint id = channelId(name);
    if (id != 0)
        deleteChannel(id);
}

/*!
 * \brief Deletes the channels in \c indices
 * \param indices Channels to delete
 */
void Vna::deleteChannels(QVector<uint> indices) {
    foreach (uint index, indices)
        deleteChannel(index);
}

/*!
 * \brief Deletes all active channels
 */
void Vna::deleteChannels() {
    deleteChannels(channels());
}

/*!
 * \brief Returns an interface to channel
 * \c index
 *
 * The Vna channel interface contains
 * all the properties, settings and
 * actions of a channel.
 *
 * See VnaChannel
 *
 * \param index Channel index to retrieve
 * \return VnaChannel interface
 * \sa VnaChannel
 */
VnaChannel &Vna::channel(uint index) {
    _channel = VnaChannel(this, index);
    return(_channel);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaChannel object.
 *
 * A dynamically-allocated VnaChannel
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see channel() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaChannel interface
 * \sa new, delete, QScopedPointer, VnaChannel
 */
VnaChannel *Vna::takeChannel(uint index) {
    return(new VnaChannel(this, index));
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated array of all \c VnaChannel objects.
 *
 * A dynamically-allocated VnaChannel
 * array can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * array, or don't know what that means,
 * see channel() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaChannel interfaces
 * \sa new, delete[], QScopedArrayPointer, VnaChannel
 */
VnaChannel *Vna::takeChannels() {
    QVector<uint> channelList = channels();
    int numberOfChannels = channelList.size();
    QScopedArrayPointer<VnaChannel>
            channelPointers(new VnaChannel[numberOfChannels]);
    for (int i = 0; i < numberOfChannels; i++) {
        channelPointers[i] = VnaChannel(this, channelList[i]);
    }
    return(channelPointers.take());
}

/** @} */

/**
 * \name Traces
 * Query, create, delete and
 * control measurement traces
 * \sa VnaTrace
 * @{*/

/*!
 * \brief Checks for the presence of trace \c name
 * \param name Name of the trace to check for
 * \return \c true if trace exists; \c false otherwise
 */
bool Vna::isTrace(QString name) {
    return(traces().contains(name));
}

/*!
 * \brief Queries the number of traces
 * \return Number of traces
 */
uint Vna::numberOfTraces() {
    return(traces().size());
}

/*!
 * \brief Returns a list of all traces
 * \return List of names of all traces
 */
QStringList Vna::traces() {
    QString scpi = ":CONF:TRAC:CAT?\n";
    QString result = query(scpi, 1000).trimmed();
    QVector<IndexName> indexNames;
    indexNames = IndexName::parse(result, ",", "\'");
    return(IndexName::names(indexNames));
}

/*!
 * \brief Creates trace \c name in \c channel
 *
 * All traces must be assigned to a particular
 * channel. The settings of the trace are
 * absorbed in part from the channel settings.
 *
 * \param name Name of the trace to create
 * \param channel Channel to create the trace in
 */
void Vna::createTrace(QString name, uint channel) {
    QString scpi = ":CALC%1:PAR:SDEF \'%2\', \'%3\'\n";
    scpi = scpi.arg(channel);
    scpi = scpi.arg(name);
    if (this->channel(channel).isSingleEndedPort(1))
        scpi = scpi.arg("S11");
    else
        scpi = scpi.arg("Sdd11");
    write(scpi);
}

/*!
 * \brief Create a trace in \c channel without
 * a specific name.
 *
 * To also name the trace, use the overloaded
 * method:
 * \c createTrace(QString name, uint channel)
 *
 * \param channel Channel of trace
 * \sa Vna::createTrace(QString name, uint channel)
 */
QString Vna::createTrace(uint channel) {
    QStringList traces = this->traces();
    QString name = "Trc%1";
    int i = traces.size() + 1;
    while (traces.contains(name.arg(i), Qt::CaseInsensitive))
        i++;
    name = name.arg(i);
    createTrace(name, channel);
    return name;
}

/*!
 * \brief Deletes trace \c name
 * \param name Name of the trace to delete
 */
void Vna::deleteTrace(QString name) {
    QString scpi = ":CALC%1:PAR:DEL \'%2\'\n";
    scpi = scpi.arg(trace(name).channel());
    scpi = scpi.arg(name);
    write(scpi);
}

/*!
 * \brief Deletes the traces in \c traces
 * \param traces Names of traces to delete
 */
void Vna::deleteTraces(QStringList traces) {
    foreach(QString trace, traces)
        deleteTrace(trace);
}

/*!
 * \brief Deletes all traces
 */
void Vna::deleteTraces() {
    deleteTraces(traces());
}

/*!
 * \brief Retrieves an interface for
 * trace \c name
 * \param name Name of the trace
 * \return VnaTrace interface
 */
VnaTrace &Vna::trace(QString name) {
    _trace = VnaTrace(this, name);
    return(_trace);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaTrace interface
 *
 * A dynamically-allocated VnaTrace
 * interface can be used apart from the
 * Vna object itself, so long as the
 * original Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see \c trace() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaTrace interface
 * \sa new, delete, QScopedPointer, VnaTrace
 */
VnaTrace *Vna::takeTrace(QString name) {
    return(new VnaTrace(this, name));
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated array of \c VnaTrace objects.
 *
 * A dynamically-allocated VnaTrace
 * interface array can be used apart
 * from the Vna object itself, so long
 * as the original Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see \c :trace() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 * VnaProperties interface
 * \sa new, delete[], QScopedArrayPointer, VnaTrace
 */
VnaTrace *Vna::takeTraces() {
    QStringList traceList = traces();
    int numberOfTraces = traceList.size();
    QScopedArrayPointer<VnaTrace>
            tracePointers(new VnaTrace[numberOfTraces]);
    for (int i = 0; i < numberOfTraces; i++) {
        tracePointers[i] = VnaTrace(this, traceList[i]);
    }
    return(tracePointers.take());
}

/** @} */

/**
 * \name Diagrams
 * Query, create, delete and
 * control diagrams
 * \sa VnaDiagram
 * @{*/

/*!
 * \brief Checks for the presence of
 * diagram \c index
 * \param index Index of the diagram to check for
 * \return \c true if diagram \c index exists;
 * \c false otherwise
 */
bool Vna::isDiagram(uint index) {
    return(diagrams().contains(index));
}

/*!
 * \brief Checks for the absence of
 * diagram \c index
 * \param index Index of the diagram to check for
 * \return \c true if diagram \c index does not exist;
 * \c false otherwise
 */
bool Vna::isNotDiagram(uint index) {
    return(!isDiagram(index));
}

/*!
 * \brief Queries the number of diagrams
 * \return Number of diagrams
 */
uint Vna::numberOfDiagrams() {
    return(diagrams().size());
}

/*!
 * \brief Returns a list of all diagrams
 * \return QVector<uint> containing all
 * available diagrams
 */
QVector<uint> Vna::diagrams() {
    QString result =
            query(":DISP:CAT?\n").trimmed();
    QVector<uint> diagrams;
    QVector<IndexName> indexNames
            = IndexName::parse(result, ",", "\'");
    return IndexName::indices(indexNames);
}

/*!
 * \brief Creates a diagram with the next
 * highest index number
 *
 * \note This method creates a diagram
 * with an index equal to MAX_INDEX + 1.
 * For a list of diagrams that is not
 * sequential, this is not equal to
 * numberOfChannels() + 1.
 *
 * \return Index of new diagram
 */
uint Vna::createDiagram() {
    QVector<uint> diagramList = diagrams();
    uint diagram;
    if (diagramList.isEmpty())
        diagram = 1;
    else
        diagram = max(diagramList) + 1;
    createDiagram(diagram);
    return(diagram);
}

/*!
 * \brief Creates the diagram \c index
 *
 * \note Although it is possible to create
 * diagrams with non-sequential indexes,
 * this is not recommended. Certain
 * methods, such as deleteDiagram(), cause
 * the Vna to reorder all remaining diagrams
 * so that they are sequential. This behavior
 * will cause the indexes used in your
 * application to change without notice.
 *
 * \param index Index of the diagram to create
 */
void Vna::createDiagram(uint index) {
    QString scpi =
            QString(":DISP:WIND%1:STAT 1\n").arg(index);
    write(scpi);
}

/*!
 * \brief Deletes diagram \c index
 * \param index Index of the diagram to delete
 */
void Vna::deleteDiagram(uint index) {
    QString scpi =
            QString(":DISP:WIND%1:STAT 0\n").arg(index);
    write(scpi);
}

/*!
 * \brief Deletes the diagrams in \c diagrams
 * \param diagrams List of diagrams to delete
 */
void Vna::deleteDiagrams(QVector<uint> diagrams) {
    foreach (uint diagram, diagrams)
        deleteDiagram(diagram);
}

/*!
 * \brief Deletes all diagrams
 */
void Vna::deleteDiagrams() {
    QVector<uint> diagramList = diagrams();
    int numberOfDiagrams = diagramList.size();
    if (numberOfDiagrams <= 1)
        return;

    diagramList.removeLast();
    deleteDiagrams(diagramList);
}

/*!
 * \brief Autoscales all diagrams
 */
void Vna::autoscaleDiagrams() {

}

VnaDiagram &Vna::diagram(uint index) {
    _diagram = VnaDiagram(this, index);
    return(_diagram);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaDiagram object.
 *
 * A dynamically-allocated VnaDiagram
 * interface can be used apart from the
 * Vna object itself, so long as the
 * original Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see \c diagram() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated
 *VnaDiagram interface
 * \sa new, delete, QScopedPointer, VnaDiagram
 */
VnaDiagram *Vna::takeDiagram(uint index) {
    return(new VnaDiagram(this, index));
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaDiagram interface array.
 *
 * A dynamically-allocated VnaDiagram
 * interface array can be used apart from the
 * Vna object itself, so long as the
 * original Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see \c diagram() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \return Pointer to dynamically-allocated VnaDiagram interface array
 * \sa new, delete, QScopedArrayPointer, VnaDiagram
 */
VnaDiagram *Vna::takeDiagrams() {
    QVector<uint> diagramList = diagrams();
    int numberOfDiagrams = diagramList.size();
    QScopedArrayPointer<VnaDiagram>
            diagramPointers(new VnaDiagram[numberOfDiagrams]);
    for (int i = 0; i < numberOfDiagrams; i++) {
        diagramPointers[i] = VnaDiagram(this, diagramList[i]);
    }
    return(diagramPointers.take());
}

/** @} */

/**
 * \name Measurement Controls
 * Start and synchronise measurements
 * for all channels and
 * traces.
 * \sa VnaChannel::startSweep(), wait(), pause()
 * @{*/

/*!
 * \brief Sweep time for all channels
 *
 * Returns the total sweep time when sweeping all channels
 * at once, including multiple manual sweeps.
 *
 * \return Time, in ms
 */
uint Vna::sweepTime_ms() {
    QVector<uint> cList = channels();
    uint totalTime = 0;
    foreach (uint c, cList) {
        uint time = channel(c).sweepTime_ms();
        uint sweeps = channel(c).sweepCount();
        totalTime += (time * sweeps);
    }
    return totalTime;
}

/*!
 * \brief Calibration sweep time for all channels
 *
 * Returns the sweep time for calibrating all channels.
 * This includes extra sweeps for averaging.
 *
 * \return Time, in ms.
 */
uint Vna::calibrationSweepTime_ms() {
    QVector<uint> cList = channels();
    uint totalTime = 0;
    foreach (uint c, cList)
        totalTime += channel(c).calibrationSweepTime_ms();
    return totalTime;
}

/*!
 * \brief Starts a sweep in all available channels
 */
void Vna::startSweeps() {
    write(":INIT:SCOP ALL\n");
    write(":INIT\n");
}

/** @} */

/**
 * \name Test Ports
 * Queries and configures test port
 * assignments.
 * @{*/

/*!
 * \brief Returns the number of available test ports
 *
 * The number of test ports and the
 * number of physical ports on the VNA
 * are identical unless a Switch
 * Matrix is installed. Switch Matrices
 * extend the number of available ports.
 *
 * \return \c Number of available test ports
 * \sa VnaProperties::physicalPorts()
 */
uint Vna::testPorts() {
    // ZVA does not have this command
    if (_properties.isZvaFamily())
        return(properties().physicalPorts());

    QString scpi = ":INST:TPORT:COUN?\n";
    return(query(scpi).trimmed().toUInt());
}

/*!
 * \brief Queries test port mapping to physical VNA port
 *
 * \param testPort Queried test port
 * \return \c true if the test port maps directly to a physical VNA port; \c false otherwise
 */
bool Vna::isVnaPort(uint testPort) {
    return testPortToVnaMap().contains(testPort);
}

/*!
 * \brief Returns physical VNA port assigned \c testPort index.
 * \param testPort Queried test port
 * \return Returns physical VNA port if mapped, or \c 0 otherwise.
 */
uint Vna::vnaPort(uint testPort) {
    return testPortToVnaMap().value(testPort, 0);
}

/*!
 * \brief Returns a list of test ports mapped to physical VNA ports
 * \return Physical VNA ports
 */
QVector<uint> Vna::vnaTestPorts() {
    return testPortToVnaMap().keys().toVector();
}

/*!
 * \brief Returns the mapping for test ports
 * that map directly to physical VNA ports.
 *
 * Test ports that do not map directly to the VNA
 * (because they are assigned to a switch matrix)
 * are not contained in PortMap.
 *
 * \return \c PortMap from test port to VNA port
 */
PortMap Vna::testPortToVnaMap() {
    // For Zva, test port == physical Vna port?
    if (properties().isZvaFamily()) {
        uint _testPorts = testPorts();
        PortMap map;
        for (uint i = 0; i < _testPorts; i++)
            map.insert(i, i);
        return map;
    }

    const QString scpi = ":SYST:COMM:RDEV:SMAT:CONF:TVNA?\n";
    QString result = query(scpi).trimmed();
    if (result.isEmpty())
        return PortMap();
    else
        return parseMap<uint,uint>(result, ",");
}

/** @} */

/**
 * \name Switch Matrix
 * Queries, configures and controls switch
 * matrices.
 * @{*/

/*!
 * \brief Vna::areSwitchMatrices
 * \return
 */
bool Vna::areSwitchMatrices() {
    return switchMatrices() > 0;
}

/*!
 * \brief Queries the number of switch matrices
 * \return Number of switch matrices
 */
uint Vna::switchMatrices() {
    if (properties().isZvaFamily())
        return 0;

    return query(":SYST:COMM:RDEV:SMAT:COUN?\n").trimmed().toUInt();
}

/*!
 * \brief Vna::isMatrixPort
 * \param testPort
 * \return
 */
bool Vna::isSwitchMatrixPort(uint testPort) {
    return switchMatrixWithPort(testPort) != 0;
}

/*!
 * \brief Returns switch matrix
 * assigned to port \c testPort
 *
 * If \c testPort is not valid, or is
 * not mapped to a switch matrix,
 * this function returns \c 0;
 *
 * \param testPort Test port
 * \return Switch matrix mapped to
 * \c testPort; \c 0 otherwise.
 */
uint Vna::switchMatrixWithPort(uint testPort) {
    uint matrices = switchMatrices();
    for (uint i = 1; i <= matrices; i++) {
        if (switchMatrix(i).hasTestPort(testPort))
            return i;
    }

    // Test port not found
    return 0;
}

/*!
 * \brief Disconnects all switch matrices from
 * the VNA.
 */
void Vna::disconnectSwitchMatrices() {
    if (properties().isZvaFamily())
        return;

    write(":INST:SMAT 0\n");
}

/*!
 * \brief Removes all switch matrices
 * from the pool of connected devices.
 */
void Vna::removeSwitchMatrices() {
    if (properties().isZvaFamily())
        return;

    write(":SYST:COMM:RDEV:SMAT:DEL\n");
}

/*!
 * \brief Returns an interface to switch
 * matrix \c index
 *
 * The switch matrix interface contains
 * all the properties, settings and
 * actions of a switch matrix.
 *
 * See VnaSwitchMatrix
 *
 * \param index Switch matrix index
 * \return VnaSwitchMatrix interface to \c index
 * \sa VnaSwitchMatrix
 */
VnaSwitchMatrix &Vna::switchMatrix(uint index) {
    _switchMatrix = VnaSwitchMatrix(this, index);
    return(_switchMatrix);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaSwitchMatrix object.
 *
 * A dynamically-allocated VnaSwitchMatrix
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see switchMatrix() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \param index Index of switch matrix
 * \return Pointer to dynamically-allocated
 * VnaSwitchMatrix interface
 * \sa new, delete, QScopedPointer, VnaSwitchMatrix
 */
VnaSwitchMatrix *Vna::takeSwitchMatrix(uint index) {
    return(new VnaSwitchMatrix(this, index));
}

/** @} */

/**
 * \name Calibration Units
 * Queries, configures and controls
 * automatic calibration units
 * (autocal units)
 * \sa VnaCalUnit
 * @{*/

/*!
 * \brief Queries the presense of
 * calibration unit \c id
 * \param id Identifier for cal unit
 */
bool Vna::isCalUnit(QString id) {
    return calUnits().contains(id);
}

/*!
 * \brief Returns a list of calibration
 * units
 * \return List of cal units
 */
QStringList Vna::calUnits() {
    QString scpi = ":SYST:COMM:RDEV:AKAL:ADDR:ALL?\n";
    return query(scpi).trimmed().remove("\'").split(",", QString::SkipEmptyParts);
}

/*!
 * \brief Returns an interface to the
 * calibration unit \c id
 *
 * The calibration unit interface contains
 * all the properties, settings and
 * actions of a autocal unit.
 *
 * See VnaCalUnit
 *
 * \param id Identifier for cal unit
 * \return Interface to cal unit \c id
 */
VnaCalUnit &Vna::calUnit(QString id) {
    _calUnit = VnaCalUnit(this, id);
    return(_calUnit);
}

/*!
 * \brief Returns a pointer to a dynamically-
 * allocated \c VnaCalUnit object.
 *
 * A dynamically-allocated VnaCalUnit
 * interface can be used apart from the
 * \c Vna object itself, so long as the
 * original \c Vna object still exists.
 *
 * In most cases this function is not necessary.
 * If you do not need a dynamically-allocated
 * pointer, or don't know what that means,
 * see calUnit() instead.
 *
 * \note The callee takes responsibility
 * for the dynamically-allocated memory, and
 * should take care to delete this pointer
 * when finished with it. Failure to do so will
 * cause a memory leak in your application.
 *
 * \param id Identifier for cal unit
 * \return Pointer to dynamically-allocated
 * VnaCalUnit interface
 * \sa new, delete, QScopedPointer, VnaCalUnit
 */
VnaCalUnit *Vna::takeCalUnit(QString id) {
    return(new VnaCalUnit(this, id));
}

// Extension Units
bool Vna::isExtensionUnit() {
    // Extension units on ZVA Only
    if (!properties().isZvaFamily())
        return false;

    // ZVAX 24/40
    isError();
    clearStatus();
    settings().errorDisplayOff();
    QString scpi = ":SYST:COMM:RDEV:EUN:IDN?\n";
    bool isZvax = !query(scpi).trimmed().isEmpty();
    isError();
    clearStatus();
    settings().errorDisplayOn();

    // ZVAX-TRM
    scpi = ":SYST:COMM:RDEV:TEUN:COUN?\n";
    bool isZvaxTrm = query(scpi).trimmed().toUInt() >= 1;

    return isZvax || isZvaxTrm;
}

// Global Limits
bool Vna::isGlobalLimitsPass() {
    return !isGlobalLimitsFail();
}
bool Vna::isGlobalLimitsFail() {
    return query(":CALC:CLIM:FAIL?\n").trimmed() == "1";
}

// Screenshots
void Vna::saveScreenshot(QString filename, ImageFormat format) {
    settings().setImageFormat(format);
    QString extension = "." + toString(format);
    if (!filename.endsWith(extension, Qt::CaseInsensitive))
        filename += extension;
    settings().setFileDestination(filename);

    write(":HCOP:PAGE:WIND HARD\n");
    write(":HCOP\n");
}
void Vna::saveScreenshotLocally(QString filename, ImageFormat format) {
    QString extension = "." + toString(format);
    QString tempFilename = uniqueAlphanumericString() + extension;
    if (!filename.endsWith(extension, Qt::CaseInsensitive))
        filename += extension;

    saveScreenshot(tempFilename, format);
    fileSystem().downloadFile(tempFilename, filename);
    fileSystem().deleteFile(tempFilename);
}
