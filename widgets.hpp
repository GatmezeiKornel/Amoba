#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Point {
protected:
public:
    int x;
    int y;
    Point(int _x, int _y);
};

class Widget{
protected:
    int x,y;
    int meretx,merety;
    Point * topLeft;
    Point * bottomright;
    int lastEvX = 0;
    int lastEvY = 0;

public:
    Widget(int vx, int vy, int vmeretx,int merety);
    virtual void Draw();
    bool isLastPosOver();
    bool is_selected(int mouse_x, int mouse_y);
    //virtual void handle(genv::event ev) = 0;
};

#endif // WIDGETS_HPP_INCLUDED
