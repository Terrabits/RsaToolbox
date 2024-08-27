#include "ScpiParser.h"


// RsaToolbox
#include "General.h"
using namespace RsaToolbox;

// Qt
#include <QRegularExpressionValidator>


/*!
 * \brief The ScpiParser class uses standard
 * SCPI conventions to parse incoming data.
 *
 * Most SCPI commands have the following format:
 * `<Menu1><Index1>:...:<MenuN><IndexN> <Parameter1>,...,<ParameterM><EOL>`
 *
 * The characters '\n' and ';' are
 * designated as End of Line (EOL) terminations.
 * Each command must be terminated with an
 * EOL character. The null character '\0' is
 * reserved and may not be used except in
 * a raw binary data transfer (see below).
 *
 * `<Menu>` corresponds to a particular
 * SCPI command menu, and menus are nested.
 * The `<Index>` is an optional feature of
 * some menus.
 *
 * Menus are separated from parameters by one or
 * more spaces ' '.
 *
 * `<Parameter>`s are separated by commas. They
 * may not contain whitespace unless quotes
 * are used. EOL characters or the '#' character.
 * The '#' character is reserved for binary
 * transfers (see below).
 *
 * For binary (IEEE 488.2 block data format)
 * transfer, the SCPI format is:
 * \code
 * <Menu1><Index1>:...:<MenuN><IndexN> \#Xnnn<Data>
 * \endcode
 * Where nnn is the size of `<Data>`, in bytes,
 * X is the number of digits of nnn, and `<Data>`
 * is the binary data as a c style character
 * array (char []).
 *
 * There is no restriction on the values of
 * `<Data>`. A binary data transfer does not
 * require EOL character termination.
 * Trailing EOL characters will be ignored.
 *
 */

ScpiParser::ScpiParser(QObject *parent) :
    Parser(parent)
{
    init();
}
ScpiParser::~ScpiParser()
{
}

void ScpiParser::read(QByteArray &bytes) {
    _buffer.append(bytes);
    parse();
}

void ScpiParser::init() {
    _buffer.clear();
    _command = Command();

    _isBinaryDataTransfer = false;
    _isHeader = false;
    _binaryDataSize = 0;
}

void ScpiParser::parse() {
    if (_buffer.isEmpty())
        return;

    if (isInitiatingBinaryDataTransfer()) {
        startBinaryDataTransfer();
    }
    if (_isBinaryDataTransfer) {
        parseBinaryData();
        return;
    }

    // Trim prefixed whitespace
    // or EOI characters
    char firstChar = _buffer.at(0);
    if (firstChar == '\n'
            || firstChar == ';'
            || QChar(firstChar).isSpace())
    {
        _buffer.remove(0,1);
        parse();
        return;
    }

    // Convert '\0'
    _buffer.replace('\0', '\n');

    // Parse non-binary SCPI
    if (isScpiCommand()) {
        parseScpiCommand();
        parse();
        return;
    }

    // Test for invalid.
    // Remove characters from beginning of
    // buffer until command is at least
    // partially valid
    int pos = 0;
    QString bufferStr(_buffer);
     QRegularExpression regex("^(:?(?:[:*]?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*)\\??)(?:[ \\t]*)(?:(?:[ \\t]+)(?:(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*))(?:(?:,)(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)))*))?(?:[\\n;]+)", QRegularExpression::CaseInsensitiveOption);
     QRegularExpressionValidator validator(regex);
    if (validator.validate(bufferStr, pos) == QValidator::Invalid) {
        pos = 0;
        int start = 1;
        QString restOfBuffer = bufferStr.mid(start);
        while (start < bufferStr.size()-1 && validator.validate(restOfBuffer, pos) == QValidator::Invalid) {
            start++;
            pos = 0;
            restOfBuffer.remove(0,1);
        }
        QString msg = "Invalid command \"%1\"";
        msg = msg.arg(bufferStr.mid(0, start).trimmed());
        _buffer.remove(0, start);
        emit error(msg);
        parse();
    }
}

bool ScpiParser::isInitiatingBinaryDataTransfer() const {
     QRegularExpression regex("^(?:(?::?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*))(?:[ \\t]+)(?:(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)),)*(?:[ \\t]*#)", QRegularExpression::CaseInsensitiveOption);
    if (QString(_buffer).contains(regex))
        return true;
    else
        return false;
}
void ScpiParser::startBinaryDataTransfer() {
    _isBinaryDataTransfer = true;
    _isHeader = false;
    _binaryDataSize = 0;

    // Take everything, up to
    // and including the '#'
    static QRegularExpression regex("^(?:(?::?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*))(?:[ \\t]+)(?:(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)),)*(?:[ \\t]*#)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = regex.match(QString(_buffer));
    QString str = match.captured(0);
    _buffer.remove(0, str.size());

    // Remove '#', trailing ','
    str.chop(1);
    str = str.trimmed();
    if (str.endsWith(',')) {
        str.chop(1);
    }

    _command = getCommand(str);
}
void ScpiParser::parseBinaryData() {
    if (_isHeader && uint(_command.data.size()) == _binaryDataSize) {
        endBinaryDataTransfer();
        parse();
        return;
    }

    if (_buffer.isEmpty())
        return;

    if (!_isHeader) {
        if (!QChar(_buffer.at(0)).isDigit()) {
            _isBinaryDataTransfer = false;
            _isHeader = false;
            _binaryDataSize = 0;
            _buffer.clear();
            _command = Command();
            emit error("Invalid IEEE 488.2 block data header!");
            return;
        }

        uint size = _buffer.mid(0,1).toUInt();
        if (uint(_buffer.size()) < size + 1) {
            return;
        }

        bool isUInt;
        _binaryDataSize = _buffer.mid(1, size).toUInt(&isUInt);
        if (!isUInt) {
            _isBinaryDataTransfer = false;
            _isHeader = false;
            _binaryDataSize = 0;
            _buffer.clear();
            _command = Command();
            emit error("Invalid IEEE 488.2 block data header!");
            return;
        }

        // Header sections parsed.
        // Remove from buffer
        _isHeader = true;
        _buffer.remove(0, size+1);
        parseBinaryData();
        return;
    }
    else if (uint(_command.data.size()) < _binaryDataSize) {
        uint takeBytes = _binaryDataSize - _command.data.size();
        if (takeBytes > uint(_buffer.size()))
            takeBytes = _buffer.size();
        _command.data.append(_buffer.mid(0, takeBytes));
        _buffer.remove(0, takeBytes);
        parseBinaryData();
        return;
    }
}

void ScpiParser::endBinaryDataTransfer() {
    _isBinaryDataTransfer = false;
    _isHeader = false;
    _binaryDataSize = 0;

    emit receivedCommand(_command);
}

bool ScpiParser::isScpiCommand() const {
    static QRegularExpression regex("^(:?(?:[:*]?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*)\\??)(?:[ \\t]*)(?:(?:[ \\t]+)(?:(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*))(?:(?:,)(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)))*))?(?:[\\n;]+)", QRegularExpression::CaseInsensitiveOption);
    if (QString(_buffer).contains(regex)) {
        return true;
    }
    else {
        return false;
    }
}
void ScpiParser::parseScpiCommand() {
    static QRegularExpression regex("^(:?(?:[:*]?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*)\\??)(?:[ \\t]*)(?:(?:[ \\t]+)(?:(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*))(?:(?:,)(?:(?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)))*))?(?:[\\n;]+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = regex.match(QString(_buffer));
    QString str = match.captured(0);
    _buffer.remove(0, str.size());

    while (str.endsWith('\n') || str.endsWith(';')) {
        str.chop(1);
    }

    _command = getCommand(str);
    emit receivedCommand(_command);
}

Command ScpiParser::getCommand(QString str) {
    Command cmd;
    getMenus(str, cmd);
    getParameters(str, cmd);
    return cmd;
}
void ScpiParser::getMenus(QString &str, Command &cmd) {
    static QRegularExpression menuRegex("^(?:[:*]?)(?:[a-z]+\\d*(?::[a-z]+\\d*)*)\\??", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = menuRegex.match(str);
    QString capture = match.captured(0);
    str.remove(0, capture.size());

    if (capture.contains('?')) {
        cmd.isQuery = true;
    }

    Menus menus;
    QStringList list = capture.split(':', Qt::SkipEmptyParts);
    foreach (QString m, list) {
        Menu menu;
        static QRegularExpression menuPartsRegex("([a-z]+)(\\d*)(\\??)", QRegularExpression::CaseInsensitiveOption);
        match = menuPartsRegex.match(m);
        menu.name = match.captured(1);
        if (!match.captured(2).isEmpty()) {
            menu.setIndex(match.captured(2).toUInt());
        }
        menus << menu;
    }
    cmd.menus = menus;
}
void ScpiParser::getParameters(QString &str, Command &cmd) {
    QVariantList parameters;
    while (isParameter(str))
        parameters << getParameter(str);
    cmd.parameters = parameters;
}

bool ScpiParser::isParameter(const QString &str) {
    static QRegularExpression nextParameter("^(((?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)))(?:,?)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = nextParameter.match(str);
    return match.hasMatch();
}
QVariant ScpiParser::getParameter(QString &str) {
    static QRegularExpression nextParameter("^(((?:[ \\t]*)(?:(?:\"[^\"\\0]*\")|(?:\'[^\'\\0]*\')|(?:(?:-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:[fpumkMGT](?:Hz|s|dB|deg|rad)?)))?)|(?:[^#\\s,\"\'\\0]+))(?:[ \\t]*)))(?:,?)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = nextParameter.match(str);
    QString param = match.captured(1).trimmed();
    str.remove(0, match.captured(0).size());

    static QRegularExpression doubleQuotes("^\"[^\"\\0]*\"$", QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression singleQuotes("^\'[^\'\\0]*\'$", QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression unsignedInt("^\\d+$", QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression integer("^-?\\d+$", QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression floatR("^-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?$", QRegularExpression::CaseInsensitiveOption);
    static QRegularExpression floatWithUnits("^(-?\\d+(?:\\.\\d*)?(?:E-?\\d+)?)(?:(?:[ \\t]*)(?:(?:(([fpumkMGT]))(?:Hz|s|dB|deg|rad)?)))?$", QRegularExpression::CaseInsensitiveOption);

    // Word is the default?
//     QRegularExpression word("^$", QRegularExpression::CaseInsensitiveOption); // default?

    if (param.contains(doubleQuotes))
        return param.remove('\"');
    if (param.contains(singleQuotes))
        return param.remove('\'');
    if (param.contains(unsignedInt))
        return param.toUInt();
    if (param.contains(integer))
        return param.toInt();
    if (param.contains(floatR))
        return param.toDouble();
    if (param.contains(floatWithUnits)) {
        match = floatWithUnits.match(param);
        double f    = match.captured(1).toDouble();
        char prefix = match.captured(2).at(0).toLatin1();
        return f * toDouble(toSiPrefix(prefix));
    }

    // Else: word
    return param;
}
