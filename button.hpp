#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using std::string;

class Button: public Widget {
protected:
    Point * topLeft;
    Point * bottomright;
    int width;
    int height;
    string content;
public:
    Button(int _x, int _y, int _width, int _height,string _content);
    void Draw();
    virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
