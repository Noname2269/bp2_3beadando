#include "zseton.hpp"
#include "jatekmester.hpp"
#include <string>

using namespace genv;

extern int jatek_rancs[7][6];

Zseton::Zseton(JatekMester * parent, int x, int y, int sx, int sy) : OsWidget(parent,  x, y, sx, sy) {}

void Zseton::rajzol()
{
    int c = (_x - 25) / 50;
    int r = (_y - 70) / 50;

    int allapot = jatek_rancs[c][r];

    if (allapot == 0)
    {
        gout << move_to(_x, _y) << color(20, 25, 40) << box(_sx, _sy);
    }

    else if (allapot == 1)
    {
        gout << move_to(_x, _y) << color(255, 50, 50) << box(_sx, _sy);
    }

    else if (allapot == 2)
    {
        gout << move_to(_x, _y) << color(255, 230, 50) << box(_sx, _sy);
    }
}

void Zseton::kezel(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        if (felette(ev.pos_x, ev.pos_y))
        {
            int col_index = (_x - 25) / 50;
            _parent->action("oszlop_" + std::to_string(col_index));
        }
    }
}
