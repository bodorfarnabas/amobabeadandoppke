#ifndef AMOBACHECKBOX_HPP_INCLUDED
#define AMOBACHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class AmobaCheckBox : public Widget
{
protected:
    bool _checked,_player_one;
public:
    AmobaCheckBox(Window* w,int x, int y, int sx, int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // AMOBACHECKBOX_HPP_INCLUDED
