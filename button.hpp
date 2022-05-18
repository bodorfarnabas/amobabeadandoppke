#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "menu.hpp"
#include <string>
#include <vector>

class Button : public Widget
{
protected:
    bool _selected;
    Menu * _from;
    Menu * _to;
    std::string _arrow;
public:
    Button(Window* w,int x, int y, int sx, int sy,Menu * from,Menu * to,std::string arrow);
    virtual void draw() ;
    virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
