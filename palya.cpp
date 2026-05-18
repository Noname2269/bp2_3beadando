#include "palya.hpp"
#include <string>

using namespace genv;

extern int aktualis_jatekos;
extern bool jatek_vege;
extern int gyoztes;

Palya::Palya(JatekMester * parent, int x, int y, int sx, int sy) : OsWidget(parent,  x, y, sx, sy) {}

void Palya::rajzol()
{
    gout << move_to(0, 0) << color(0, 0, 0) << box(400, 400);

    gout << move_to(_x, _y) << color(30, 80, 220) << box(_sx, _sy);

    gout << move_to(25, 35);

    if (jatek_vege)
    {
        if (gyoztes == 1)
        {
            gout << color(255, 50, 50) << text("RED PLAYER WON!");
        }

        else
        {
            gout << color(255, 230, 50) << text("YELLOW PLAYER WON!");
        }
    }

    else
    {
        if (aktualis_jatekos == 1)
        {
            gout << color(255, 50, 50) << text("RED PLAYER'S TURN");
        }

        else
        {
            gout << color(255, 230, 50) << text("YELLOW PLAYER'S TURN");
        }
    }
}

void Palya::kezel(event ev)
{}
