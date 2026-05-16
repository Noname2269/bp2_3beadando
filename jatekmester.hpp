#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include "oswidget.hpp"

using namespace genv;

class JatekMester
{
public:
    JatekMester();

    void event_loop();

    void widget_tar(OsWidget * widget);

    virtual void action(std::string id) = 0;

protected:
    std::vector<OsWidget*> _widgets;
};

#endif // JATEKMESTER_HPP
