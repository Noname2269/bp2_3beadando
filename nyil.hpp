#ifndef NYIL_HPP
#define NYIL_HPP

#include "oswidget.hpp"

class Nyil : public OsWidget
{
private:
    bool _lathato;
public:
    Nyil(JatekMester* parent, int x, int y, int sx, int sy);

    void set_pozicio(int uj_x, bool lathato);

    virtual void rajzol() override;
    virtual void kezel(genv::event ev) override;
};

#endif // NYIL_HPP
