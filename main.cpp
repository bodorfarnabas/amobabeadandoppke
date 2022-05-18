#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "TextBox.hpp"
#include <vector>
#include "window.hpp"
#include <fstream>
#include "number.hpp"
#include "menu.hpp"
#include "button.hpp"
#include "amobacheckbox.hpp"
using namespace std;
using namespace genv;

struct Ablak : public Window
{
private:


public:

    Ablak()
    {
        gout.open(480,480);
        gout << refresh;

        for(int i=1;i<15;i++)
        {
            for(int j=1;j<15;j++)
            {
                new AmobaCheckBox(this,30*i,30*j,30,30);
            }
        }
    }
} ;




int main()
{
    Ablak a;
    a.event_loop();

    return 0;
}
