#ifndef SCPIPARSER_H
#define SCPIPARSER_H


// RsaToolbox
#include "Parser.h"
#include "Command.h"

// Qt
#include <QStringList>
#include <QVariant>


namespace RsaToolbox {


class ScpiParser : public Parser
{
    Q_OBJECT

public:
    explicit ScpiParser(QObject *parent = 0);
    ~ScpiParser();

signals:

public slots:
    virtual void read(QByteArray &bytes);

protected:
//    virtual void processCommand(QString &command) = 0;

private:
    void init();
    QByteArray _buffer;
    QString _error;

    Command _command;

    void parse();

    // Binary transfer
    bool isInitiatingBinaryDataTransfer() const;
    bool _isBinaryDataTransfer;
    bool _isHeader;
    uint _binaryDataSize;
    void startBinaryDataTransfer();
    void parseBinaryData();
    void endBinaryDataTransfer();

    // SCPI
    bool isScpiCommand() const;
    void parseScpiCommand();

    // General
    static Command getCommand(QString str);
    static void getMenus(QString &str, Command &cmd);
    static void getParameters(QString &str, Command &cmd);
    static bool isParameter(const QString &str);
    static QVariant getParameter(QString &str);

//    void processCommands();
};
}


#endif // SCPIPARSER_H
