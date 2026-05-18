#include "palya.hpp"
#include "jatekmester.hpp"
#include <string>

using namespace genv;

extern int aktualis_jatekos;
extern bool jatek_vege;
extern int gyoztes;
extern bool dontetlen;

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

        gout << move_to(300, 20) << color(50, 150, 50) << box(90, 25);
        gout << move_to(315, 37) << color(255, 255, 255) << text("NEW GAME");
    }

    else if (dontetlen)
    {
        gout << color(150, 150, 150) << text("DRAW!");

        gout << move_to(300, 20) << color(50, 150, 50) << box(90, 25);
        gout << move_to(315, 37) << color(255, 255, 255) << text("NEW GAME");
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
{
    if ((jatek_vege || dontetlen) && ev.type == ev_mouse && ev.button == btn_left)
    {
        if (ev.pos_x >= 300 && ev.pos_x <= 390 && ev.pos_y >= 20 && ev.pos_y <= 45)
        {
            _parent->action("ujraindit");
        }
    }
}

bool Palya::felette(int mouse_x, int mouse_y)
{
    if (jatek_vege || dontetlen)
    {
        return true;
    }

    return OsWidget::felette(mouse_x, mouse_y);
}
