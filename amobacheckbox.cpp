#include "amobacheckbox.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>

using namespace genv;
using namespace std;

AmobaCheckBox::AmobaCheckBox(Window* w,int x,int y,int sx,int sy):Widget(w,x,y,sx,sy)
{
    _size_y=_size_x;
    _checked=false;
    _player_one=true;
}
void AmobaCheckBox::draw()
{

        gout << move_to(_x, _y) << color(50,50,50) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(200,200,200) << box(_size_x-4, _size_y-4);
    if(_checked)
    {
        string played="X";
        if(_player_one)
        {
            played="X";
            gout << move_to(_x+_size_x/2-gout.twidth(played)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,0,0)<<text(played);
        }
        if(!_player_one)
        {
            played="O";
            gout << move_to(_x+_size_x/2-gout.twidth(played)/2, _y+_size_y/2+gout.cascent()/2)<<color(0,0,255)<<text(played);
        }
    }
}
void AmobaCheckBox::handle(event ev)
{
    if(ev.type==ev_mouse&&ev.button==btn_left&&is_selected(ev.pos_x,ev.pos_y))
    {
        _checked=true;
    }
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _player_one = !_player_one;
    }
}
