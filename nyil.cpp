#include "nyil.hpp"
#include "graphics.hpp"
#include "jatekmester.hpp"

using namespace genv;

extern int aktualis_jatekos;
extern bool jatek_vege;

Nyil::Nyil(JatekMester* parent, int x, int y, int sx, int sy) : OsWidget(parent, x, y, sx, sy), _lathato(false) {}

void Nyil::set_pozicio(int uj_x, bool lathato)
{
    _x = uj_x;
    _lathato = lathato;
}

void Nyil::rajzol()
{
    if (!_lathato || jatek_vege) return;

    if (aktualis_jatekos == 1) gout << color(255, 50, 50);

    else gout << color(255, 230, 50);

    int kozeppont_x = _x + _sx / 2;

    for (int i = 0; i < _sy; ++i)
    {
        int fel_szelesseg = 12 - (i * 12 / _sy);
        if (fel_szelesseg < 0) fel_szelesseg = 0;

        gout << move_to(kozeppont_x - fel_szelesseg, _y + i)
             << line_to(kozeppont_x + fel_szelesseg, _y + i);
    }
}

void Nyil::kezel(event ev) {}
