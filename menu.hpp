#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
#include <vector>
using namespace genv;
using namespace std;

class Menu : public Widget
{
protected:
    vector<string> _choices;
    int _which,_selected,_max;
    bool _checked,_2many;
public:
    Menu(Window* w,int x, int y, int sx, int sy,vector<string> choices,int _max);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    void feltolt(string new_element);
    int selected()
    {
        return _selected;
    }
    string sselected()
    {
        return _choices[_selected];
    }
    void torol()
    {
        _choices.erase(_choices.begin()+_selected);
    }
};

#endif // MENU_HPP_INCLUDED
