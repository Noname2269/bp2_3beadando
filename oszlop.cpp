#include "oszlop.hpp"
#include <string>
#include "jatekmester.hpp"

using namespace genv;

Oszlop::Oszlop(JatekMester * parent, int x, int y, int sx, int sy) : OsWidget(parent,  x, y, sx, sy) {}

void Oszlop::rajzol() {}

void Oszlop::kezel(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        int col_index = (_x - 25) / 50;
        _parent->action("oszlop_" + std::to_string(col_index));
    }
}
