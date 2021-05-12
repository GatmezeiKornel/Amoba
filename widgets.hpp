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
    int lastEvX = 0;
    int lastEvY = 0;

public:
    Widget(int vx, int vy, int vmeretx,int merety);
    void Draw();
    bool isLastPosOver();

};

#endif // WIDGETS_HPP_INCLUDED
