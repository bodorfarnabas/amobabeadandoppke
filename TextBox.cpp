#include "TextBox.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace genv;

TextBox::TextBox(Window* w,int x, int y, int sx, int sy) : Widget(w,x,y,sx,sy)
        {textt="HELLÓ";
        bool _checked=false;}

void TextBox ::draw()
{
    if(_checked)
    {
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+4, _y+4) << color(0,0,0) << box(_size_x-8, _size_y-8);
    gout << move_to(_x+_size_x/2-gout.twidth(textt)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(textt);
    gout << move_to(_x+_size_x/2+gout.twidth(textt)/2, _y+_size_y/2-gout.cascent()/2)<<color(255,255,255)<<line(0,gout.cascent());

    }
    else
    {
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x/2-gout.twidth(textt)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(textt);
    }
}
void TextBox::handle(event ev)
{
if (ev.type == ev_key && ev.keycode == key_enter) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
    if(ev.type==ev_key && _checked)
    {
        if(_size_x>gout.twidth(textt)+16)
        {std::string t=ev.keyutf8;
        textt+=t;
        }
        if(ev.keycode==key_backspace && textt.size()>0)
        {

            textt.pop_back();
        }
    }
}
bool TextBox::is_checked()
{
    return _checked;
}
