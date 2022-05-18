#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"
#include "graphics.hpp"

class Window {
protected:
    std::vector<Widget*> widgets;
    bool playerone=true;
public:
    void registerwidget(Widget* w){widgets.push_back(w);};
    void event_loop();
};

#endif // WINDOW_HPP_INCLUDED
