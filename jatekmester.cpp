#include "jatekmester.hpp"
#include "oswidget.hpp"

JatekMester::JatekMester() {}

void JatekMester::widget_tar(OsWidget * widget)
{
    _widgets.push_back(widget);
}

void JatekMester::event_loop()
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse)
        {
            action("eger_" + std::to_string(ev.pos_x));
        }

        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->felette(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }

        if (focus!=-1)
        {
            _widgets[focus]->kezel(ev);
        }

        for (OsWidget * w : _widgets)
        {
            w->rajzol();
        }

        gout << refresh;
    }
}
