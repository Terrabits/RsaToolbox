#include "Menu.h"


// RsaToolbox
using namespace RsaToolbox;


Menu::Menu()
{
    clearIndex();
}
Menu::Menu(const Menu &other) :
    name(other.name),
    isIndex(other.isIndex),
    index(other.index)
{
}

Menu::~Menu()
{
}

void Menu::setIndex(uint value) {
    index = value;
    isIndex = true;
}
void Menu::clearIndex() {
    isIndex = false;
    index = 0;
}

void Menu::operator=(const Menu &other) {
    name = other.name;
    isIndex = other.isIndex;
    index = other.index;
}

bool operator<(const Menu &lhs, const Menu &rhs) {
    return lhs.name.compare(rhs.name, Qt::CaseInsensitive) < 0;
}
bool operator==(const Menu &lhs, const Menu &rhs) {
    return lhs.name.compare(rhs.name, Qt::CaseInsensitive) == 0;
}
bool operator!=(const Menu &lhs, const Menu &rhs) {
    return !(lhs == rhs);
}
bool operator>(const Menu &lhs, const Menu &rhs) {
    return lhs.name.compare(rhs.name, Qt::CaseInsensitive) > 0;
}

bool operator==(const Menu &submenu, const QString &name) {
    return submenu.name.toUpper() == name.toUpper();
}
bool operator==(const QString &name, const Menu &submenu) {
    return operator==(submenu, name);
}
