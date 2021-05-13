#include "button.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
using namespace genv;

Button::Button(int _x, int _y, int _width, int _height,string _content):Widget(_x,_y,_width,_height)
{
    width = _width;
    height = _height;
    content= _content;
}

void Button::Draw(){
    gout
        <<color(100,100,100)
        <<move_to(topLeft->x , topLeft->y)
        <<box(bottomright->x - topLeft->x, bottomright->y - topLeft->y);

    gout
        <<color(0,0,0)
        <<move_to(topLeft->x+2 , topLeft->y+2)
        <<box(bottomright->x - topLeft->x-4, bottomright->y - topLeft->y-4);

    gout
        <<color(100,100,100)
            <<move_to(topLeft->x+width/2-gout.twidth(content)/2,topLeft->y+height/2-gout.cascent())
            <<text(content)
            ;
}

void Button::handle(genv::event ev)
{

}

