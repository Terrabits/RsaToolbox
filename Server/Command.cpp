#include "Command.h"


// RsaToolbox
using namespace RsaToolbox;

// Qt
#include <QTextStream>


Command::Command() :
    isQuery(false)
{
}
Command::Command(const Command &other) :
    isQuery(other.isQuery),
    menus(other.menus),
    parameters(other.parameters),
    data(other.data)
{
}

Command::~Command()
{
}

QString Command::toString() const {
    QString str;
    QTextStream stream(&str);

    stream << "Menus:" << endl;
    foreach (Menu m, menus) {
        QString s;
        if (m.isIndex) {
            s = "  %1 (%2)";
            s = s.arg(m.name);
            s = s.arg(m.index);
        }
        else {
            s = "  %1";
            s = s.arg(m.name);
        }
        stream << s << endl;
    }
    if (isQuery)
        stream << "Query" << endl;

    stream << "Parameters:" << endl;
    foreach (QVariant v, parameters) {
        stream << "  " << v.typeName() << " " << v.toString() << endl;
    }

    if (!data.isEmpty()) {
        stream << "Binary data: " << data.size() << " bytes" << endl;
    }

    stream.flush();
    return str;
}

void Command::operator=(const Command &other) {
    isQuery = other.isQuery;
    menus = other.menus;
    parameters = other.parameters;
    data = other.data;
}

QDebug &operator<<(QDebug &debug, const Command &cmd) {
    debug << cmd.toString();
    return debug;
}
