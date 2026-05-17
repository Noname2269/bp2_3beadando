#ifndef ZSETON_HPP
#define ZSETON_HPP

#include "oswidget.hpp"

class Zseton : public OsWidget
{
public:
    Zseton(JatekMester * parent, int x, int y, int sx, int sy);

    virtual void rajzol() override;
    virtual void kezel(genv::event ev) override;
};

#endif // ZSETON_HPP
