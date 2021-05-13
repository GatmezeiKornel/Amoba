#include "shapebox.hpp"
#include "graphics.hpp"

using namespace genv;

ShBox::ShBox(int _x, int _y, int _meretx, int _merety):Widget(_x,_y,_meretx,_merety){
}

void ShBox::Draw()
{
    gout
        <<color(100,100,100)
        <<move_to(topLeft->x , topLeft->y)
        <<box(bottomright->x - topLeft->x, bottomright->y - topLeft->y);

    gout
        <<color(0,0,0)
        <<move_to(topLeft->x+2 , topLeft->y+2)
        <<box(bottomright->x - topLeft->x-4, bottomright->y - topLeft->y-4);
    if(value==1)
    {
        gout << color(255,255,255)
             << move_to(x+4, y+4) << line(meretx-8, merety-8)
             << move_to(x+5, y+4) << line(meretx-8, merety-8)
             << move_to(x+meretx-4, y+4) << line(-meretx+8, merety-8)
             << move_to(x+meretx-5, y+4) << line(-meretx+8, merety-8);
    }
    else if(value==-1)
    {
        for(int dx=-meretx;dx<=meretx;dx++){
            for(int dy=-meretx;dy<=meretx;dy++){
                if(dx*dx+dy*dy<=meretx*meretx){
                    gout<<color(255,255,255)<<move_to(x+dx,y+dy)<<dot;
                }
            }
        }

    }
}

void ShBox::handle(genv::event ev,int &_timer)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && value==0)
    {
        if(_timer%2==0)
            value=1;
        else
            value=-1;
        _timer++;
    }
}





