#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using std::string;

class Button: public Widget {
protected:
    int width;
    int height;
    string content;
public:
    Button(int _x, int _y, int _width, int _height,string _content);
    virtual void Draw();
    void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
