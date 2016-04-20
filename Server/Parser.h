#ifndef PARSER_H
#define PARSER_H


// RsaToolbox
#include "Command.h"

// Qt
#include <QObject>
#include <QSharedPointer>


namespace RsaToolbox {


class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    ~Parser();

signals:
    void write(const QByteArray &bytes);
    void receivedCommand(const Command &command);
    void error(const QString &message);

public slots:
    virtual void read(QByteArray &bytes) = 0;
};
}


#endif // PARSER_H
