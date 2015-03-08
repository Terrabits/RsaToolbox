#ifndef COMMAND_H
#define COMMAND_H


// RsaToolbox
#include "Menu.h"

// Qt
#include <QStringList>
#include <QByteArray>
#include <QVariant>
#include <QDebug>


namespace RsaToolbox {


class Command;
typedef QList<Command> CommandList;

class Command
{
public:
    Command();
    Command(const Command &other);
    ~Command();

    bool isQuery;
    Menus menus;
    QVariantList parameters;
    QByteArray data;

    QString toString() const;

    void operator=(const Command &other);
};
}


QDebug &operator<<(QDebug &debug, const RsaToolbox::Command &cmd);


#endif // COMMAND_H
