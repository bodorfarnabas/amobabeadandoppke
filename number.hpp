#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
using namespace genv;

class Numberbox :public Widget
{
protected:
    int _size_text_x,_number,_min,_max;
public:
    Numberbox(Window* w,int x, int y, int sx, int sy,int minim,int maxim);
    virtual void draw() ;
    virtual void handle(event ev);
};

#endif // NUMBER_HPP_INCLUDED
