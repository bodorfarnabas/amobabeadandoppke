#include "button.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

Button::Button(Window * w,int x, int y, int sx, int sy,Menu * from,Menu * to,string arrow):Widget(w,x,y,sx,sy)
{
    _from=from;
    _to=to;
    _selected=false;
    _arrow=arrow;
}
void Button::draw()
{
    if(_selected)
    {
        gout << move_to(_x, _y) << color(200,200,200) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(50,50,50) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+_size_x/2-gout.twidth(_arrow)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(_arrow);
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+_size_x/2-gout.twidth(_arrow)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(_arrow);
    }
}
void Button::handle(event ev)
{
    if(ev.type==ev_mouse&&ev.button==btn_left&&is_selected(ev.pos_x,ev.pos_y))
    {
        _selected=true;
    }
    if(ev.type==ev_mouse&&ev.button==-btn_left)
        _selected=false;
    if(_selected)
    {
        _to->feltolt(_from->sselected());
        _from->torol();
    }
}
