#include "menu.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace genv;

Menu::Menu(Window* w,int x, int y, int sx, int sy,vector<string> choices,int maxi) : Widget(w,x,y,sx,sy)
{
    _choices=choices;
    _which = -1;
    _checked=false;
    _selected=-1;
    _max=maxi;
    if(_size_y*_choices.size()>_max)
        _2many=true;
    else
        _2many=false;
}
void Menu::draw()
{
    if(_checked)
    {

        for(size_t i=0;i<_choices.size();i++)
        {
            if(i==_selected)
            {
//                gout << move_to(_x, _y+i*_size_y) << color(0,255,0) << box(_size_x, _size_y);
//                gout << move_to(_x+_size_x/2-gout.twidth(_choices[_selected])/2, _y+_size_y/2+gout.cascent()/2+i*_size_y)<<color(255,255,255)<<text(_choices[_selected]);
            }
            if(i==_which)
            {
                gout << move_to(_x, _y+i*_size_y) << color(200,0,0) << box(_size_x, _size_y);
                gout << move_to(_x+_size_x/2-gout.twidth(_choices[i])/2, _y+_size_y/2+gout.cascent()/2+i*_size_y)<<color(255,255,255)<<text(_choices[i]);

            }
            else
            {
                gout << move_to(_x, _y+i*_size_y) << color(200,200,200) << box(_size_x, _size_y);
                gout << move_to(_x+_size_x/2-gout.twidth(_choices[i])/2, _y+_size_y/2+gout.cascent()/2+i*_size_y)<<color(255,255,255)<<text(_choices[i]);
            }
        }
    }
    else
    {
        if(_selected==-1)
        {
            gout << move_to(_x, _y) << color(200,200,200) << box(_size_x, _size_y);
            string menu="menu";
            gout << move_to(_x+_size_x/2-gout.twidth(menu)/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(menu);
        }
        else
        {
            gout << move_to(_x,_y)<<color(0,0,0)<<box(_size_x,_size_y*_choices.size());
            gout << move_to(_x, _y) << color(200,0,0) << box(_size_x, _size_y);
            //        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
            gout << move_to(_x+_size_x/2-gout.twidth(_choices[_selected])/2, _y+_size_y/2+gout.cascent()/2)<<color(255,255,255)<<text(_choices[_selected]);
        }
    }
}
void Menu::handle(event ev)
{
    if(ev.type==ev_mouse)
    {
        if(is_selected(ev.pos_x,ev.pos_y)&&ev.button==btn_left)
           {_checked=!_checked;}
        if(!is_selected(ev.pos_x,ev.pos_y)&&ev.button==btn_left)
           {_checked=!_checked;}

        for(size_t i=0;i<_choices.size();i++)
        {
            if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y+i*_size_y && ev.pos_y<_y+_size_y+i*_size_y)
                _which = i;
            if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y+i*_size_y && ev.pos_y<_y+_size_y+i*_size_y && ev.button==btn_left)
                _selected = i;
        }

    }
}
void Menu::feltolt(string new_element)
{
    _choices.push_back(new_element);
}
