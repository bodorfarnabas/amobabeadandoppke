#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Window;

class Widget {
protected:
    Window * _w;
    int _x, _y, _size_x, _size_y;
public:
    Widget(Window* w,int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
