#include "graphics.hpp"
#include "oswidget.hpp"
#include "oszlop.hpp"
#include "palya.hpp"
#include "zseton.hpp"
#include "jatekmester.hpp"

using namespace std;
using namespace genv;

class MyApp : public JatekMester
{
public:
    MyApp()
    {

    }

    void action(string id)
    {

    }

protected:

};

int main()
{
    gout.open(400,400);

    MyApp app;

    app.event_loop();

    return 0;
}
