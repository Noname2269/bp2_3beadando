#include "oswidget.hpp"
#include "graphics.hpp"
#include "jatekmester.hpp"

OsWidget::OsWidget(JatekMester* parent, int x, int y, int sx, int sy) : _parent(parent), _x(x), _y(y), _sx(sx), _sy(sy)
{
    _parent ->register_widget(this);
}

bool OsWidget::felette(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
}
