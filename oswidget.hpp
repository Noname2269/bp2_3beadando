#ifndef OSWIDGET_HPP
#define OSWIDGET_HPP

#include "graphics.hpp"

class JatekMester;

class OsWidget
{
public:
    OsWidget(JatekMester*,int, int, int, int);

    virtual void rajzol() = 0;
    virtual void kezel(genv::event ev) = 0;
    virtual bool felette(int mouse_x, int mouse_y);

protected:
    int _x, _y, _sx, _sy;
    JatekMester* _parent;
};

#endif // OSWIDGET_HPP
