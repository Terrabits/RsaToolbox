#ifndef ACTION_H
#define ACTION_H


// RsaToolbox
#include "SubMenu.h"
#include "Command.h"

#include <QObject>

class Action : public QObject
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = 0);
    Action(const Action &other);
    ~Action();

    virtual Menus menus() const = 0;
    virtual uint numberOfParameters() const = 0;

    virtual void operator=(const Action &other) = 0;

signals:
    void error(QString message);

public slots:
    virtual void execute(Command command) = 0;
};

bool operator<(const Action &lhs, const Action &rhs);
bool operator==(const Action &lhs, const Action &rhs);
bool operator!=(const Action &lhs, const Action &rhs);
bool operator>(const Action &lhs, const Action &rhs);

#endif // ACTION_H
