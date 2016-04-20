#include "Action.h"

Action::Action(QObject *parent) : QObject(parent)
{

}
Action::Action(const Action &other)
{

}
Action::~Action()
{

}

bool operator<(const Action &lhs, const Action &rhs) {
    int comparableMenus = std::min(lhs.menus().size(), rhs.menus().size());
    for (int i = 0; i < comparableMenus; i++) {
        if (lhs.menus()[i] < rhs.menus()[i])
            return true;
        else if (lhs.menus()[i] > rhs.menus()[i])
            return false;
    }

    // If one action has less
    // submenus than the other,
    // it is less than the other.
    if (lhs.menus().size() != rhs.menus().size())
        return lhs.menus().size() < rhs.menus().size();

    // Menus being equal,
    // return action with least parameters
    return lhs.numberOfParameters() < rhs.numberOfParameters();
}
bool operator==(const Action &lhs, const Action &rhs) {
    return !(lhs != rhs);
}
bool operator!=(const Action &lhs, const Action &rhs) {
    if (lhs.menus().size() != rhs.menus().size())
        return true;
    if (lhs.numberOfParameters() != rhs.numberOfParameters())
        return true;

    for (int i = 0; i < lhs.menus().size(); i++) {
        if (lhs.menus()[i] != rhs.menus()[i])
            return true;
    }

    // actions are equal
    return false;
}

bool operator>(const Action &lhs, const Action &rhs) {
    int comparableMenus = std::min(lhs.menus().size(), rhs.menus().size());
    for (int i = 0; i < comparableMenus; i++) {
        if (lhs.menus()[i] > rhs.menus()[i])
            return true;
        else if (lhs.menus()[i] < rhs.menus()[i])
            return false;
    }

    // If one action has less
    // submenus than the other,
    // it is less than the other.
    if (lhs.menus().size() != rhs.menus().size())
        return lhs.menus().size() > rhs.menus().size();

    // Menus being equal,
    // return action with least parameters
    return lhs.numberOfParameters() > rhs.numberOfParameters();
}
