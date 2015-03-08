#ifndef MENU_H
#define MENU_H


// Qt
#include <QString>


namespace RsaToolbox {


class Menu;
typedef QList<Menu> Menus;

class Menu
{
public:
    Menu();
    Menu(const Menu &other);
    ~Menu();

    QString name;

    bool isIndex;
    uint index;

    void setIndex(uint value);
    void clearIndex();

    void operator=(const Menu &other);
};
}


bool operator<(const RsaToolbox::Menu &lhs, const RsaToolbox::Menu &rhs);
bool operator==(const RsaToolbox::Menu &lhs, const RsaToolbox::Menu &rhs);
bool operator!=(const RsaToolbox::Menu &lhs, const RsaToolbox::Menu &rhs);
bool operator>(const RsaToolbox::Menu &lhs, const RsaToolbox::Menu &rhs);

bool operator==(const RsaToolbox::Menu &submenu, const QString &name);
bool operator==(const QString &name, const RsaToolbox::Menu &submenu);


#endif // MENU_H
