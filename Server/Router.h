#ifndef ROUTER_H
#define ROUTER_H


// RsaToolbox
#include "Action.h"

// Qt
#include <QObject>
#include <QList>


class Router : public QObject
{
    Q_OBJECT
public:
    explicit Router(QObject *parent = 0);
    ~Router();

    bool isAction(Action action) const;
    void addAction(Action action);
    void removeAction(Action action);

signals:
    void write(const QByteArray &bytes);
    void error(QString message);

public slots:
    void execute(const Command &cmd);

private:
    QList<Action> _actions;
};

#endif // ROUTER_H
