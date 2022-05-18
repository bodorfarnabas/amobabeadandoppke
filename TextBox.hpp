#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>
using namespace genv;

class TextBox : public Widget
{
protected:
    std::string textt;
    bool _checked;
public:
    TextBox(Window* w,int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;

};

#endif // TEXTBOX_HPP_INCLUDED
