#ifndef PALYA_HPP
#define PALYA_HPP

#include "oswidget.hpp"

class Palya : public OsWidget
{
public:
    Palya(JatekMester * parent, int x, int y, int sx, int sy);
    virtual void rajzol() override;
    virtual void kezel(genv::event ev) override;
};

#endif // PALYA_HPP
