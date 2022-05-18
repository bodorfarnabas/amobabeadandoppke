#include "graphics.hpp"
#include "window.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

void Window::event_loop()
{
    for (Widget * wg : widgets) {
    wg->draw();
    }
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        gout << move_to(0,0)<<color(0,0,0)<<box(400,400);
        for (Widget * w : widgets) {
            w->draw();
        }
        if(ev.type==ev_mouse&&ev.button==btn_left)
        {
            playerone=!playerone;
        }
        gout << refresh;
    }
}
