#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Point::Point(int _x, int _y)
{
    Point::x = _x;
    Point::y = _y;
}

Widget::Widget(int vx, int vy, int vmeretx, int vmerety) :x(vx),y(vy),meretx(vmeretx),merety(vmerety)
{
    topLeft = new Point(vx, vy);
    bottomright = new Point(vx+vmeretx, vy+vmerety);
}

void Widget::Draw(){
    gout
        <<color(150,150,150)
            <<move_to(x,y)
            <<box(meretx,merety)
        <<color(0,0,0)
            <<move_to(x+2,y+2)
            <<box(meretx-4,merety-4);
}

bool Widget::isLastPosOver()
{
    return
        (lastEvX >= x)
    &&  (lastEvX <= meretx + x)
    &&  (lastEvY >= y)
    &&  (lastEvY <= y + merety);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>x && mouse_x<x+meretx && mouse_y>y && mouse_y<y+merety;
}

