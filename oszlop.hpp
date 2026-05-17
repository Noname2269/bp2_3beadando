#ifndef OSZLOP_HPP
#define OSZLOP_HPP

#include "oswidget.hpp"

class Oszlop : public OsWidget
{
public:
    Oszlop(JatekMester * parent, int x, int y, int sx, int sy);
    virtual void rajzol() override;
    virtual void kezel(genv::event ev) override;
};

#endif // OSZLOP_HPP
