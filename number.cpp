#include "number.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace genv;

Numberbox::Numberbox(Window* w,int x, int y, int sx, int sy,int minim,int maxim) : Widget(w,x,y,sx,sy)
{
    _min=minim;
    _max=maxim;
    _number=_min;
    _size_text_x=_size_x-20;
}
void Numberbox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_text_x-4, _size_y-4);
    gout << move_to(_x+_size_text_x, _y+2) << color(0,0,0) << box(_size_x-_size_text_x-2, _size_y/2-3);
    gout << move_to(_x+_size_text_x, _y+_size_y/2+1) << color(0,0,0) << box(_size_x-_size_text_x-2, _size_y/2-3);
    string textt=to_string(_number);
    gout << move_to(_x+_size_text_x/2-gout.twidth(textt)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(textt);
}
void Numberbox::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        if((ev.pos_x>_x+_size_text_x && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+_size_y/2)&&_number<_max)
        {
            _number++;
        }
        if((ev.pos_x>_x+_size_text_x && ev.pos_x<_x+_size_x && ev.pos_y>_y+_size_y/2 && ev.pos_y<_y+_size_y)&&_number>_min)
        {
            _number--;
        }
    }
    if(ev.keycode==key_up&&_number<_max)
        _number++;
    if(ev.keycode==key_down&&_number>_min)
        _number--;
    if(ev.keycode==key_pgup&&_number<=_max-10)
        _number+=10;
    if(ev.keycode==key_pgdn&&_number>=_min+10)
        _number-=10;
}
