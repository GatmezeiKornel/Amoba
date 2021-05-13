#include "statictext.hpp"

StText::StText(int _x, int _y, int _width, int _height,string _content):Button(_x,_y,_width,_height,_content)
{
}

void StText::Draw(){
    gout
        <<color(100,100,100)
            <<move_to(topLeft->x+width/2-gout.twidth(content)/2,topLeft->y+height/2-gout.cascent())
            <<text(content)
            ;
}
