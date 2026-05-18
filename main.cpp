#include "graphics.hpp"
#include "oswidget.hpp"
#include "oszlop.hpp"
#include "palya.hpp"
#include "zseton.hpp"
#include "nyil.hpp"
#include "jatekmester.hpp"

using namespace std;
using namespace genv;

int jatek_rancs[7][6] = {0};
int aktualis_jatekos = 1;
bool jatek_vege = false;
int gyoztes = 0;

class MyApp : public JatekMester
{
public:
    MyApp()
    {
        palya = new Palya(this, 25, 70, 350, 300);

        for (int i = 0; i < 7; ++i)
        {
            oszlopok[i] = new Oszlop(this, 25 + i * 50, 70, 50, 300);
        }

        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                zsetonok[i][j] = new Zseton(this, 25 + i * 50 + 5, 70 + j * 50 + 5, 40, 40);
            }
        }

        nyil = new Nyil(this, 25, 48, 50, 15);
    }

    bool ellenoriz_gyozelem(int c, int r)
    {
        int p = jatek_rancs[c][r];
        int iranyok[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

        for (int i = 0; i < 4; ++i)
        {
            int dx = iranyok[i][0];
            int dy = iranyok[i][1];
            int db = 1;

            int nc = c + dx, nr = r + dy;
            while (nc >= 0 && nc < 7 && nr >= 0 && nr < 6 && jatek_rancs[nc][nr] == p)
            {
                db++; nc += dx; nr += dy;
            }

            nc = c - dx; nr = r - dy;
            while (nc >= 0 && nc < 7 && nr >= 0 && nr < 6 && jatek_rancs[nc][nr] == p)
            {
                db++; nc -= dx; nr -= dy;
            }

            if (db >= 4) return true;
        }
        return false;
    }

    void action(string id) override
    {
        if (id.rfind("eger_", 0) == 0)
        {
            size_t elso_aláhúzás = id.find('_');
            size_t masodik_aláhúzás = id.find('_', elso_aláhúzás + 1);

            int mx = stoi(id.substr(elso_aláhúzás + 1, masodik_aláhúzás - elso_aláhúzás - 1));
            int my = stoi(id.substr(masodik_aláhúzás + 1));

            if (mx >= 25 && mx < 375 && my >= 70 && my <= 370)
            {
                int col = (mx - 25) / 50;
                nyil->set_pozicio(25 + col * 50, true);
            }

            else
            {
                nyil->set_pozicio(0, false);
            }

            return;
        }

        if (jatek_vege) return;

        if (id.rfind("oszlop_", 0) == 0)
        {
            int col = stoi(id.substr(7));
            int row = -1;

            for (int j = 5; j >= 0; --j)
            {
                if (jatek_rancs[col][j] == 0)
                {
                    row = j;
                    break;
                }
            }

            if (row != -1)
            {
                jatek_rancs[col][row] = aktualis_jatekos;

                if (ellenoriz_gyozelem(col, row))
                {
                    jatek_vege = true;
                    gyoztes = aktualis_jatekos;
                }

                else
                {
                    aktualis_jatekos = (aktualis_jatekos == 1) ? 2 : 1;
                }
            }
        }
    }

protected:
    Palya* palya;
    Oszlop* oszlopok[7];
    Zseton* zsetonok[7][6];
    Nyil* nyil;
};

int main()
{
    gout.open(400,400);

    MyApp app;

    app.event_loop();

    return 0;
}
