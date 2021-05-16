#include "shapebox.hpp"
#include "graphics.hpp"
#include "gamemaster.hpp"
#include <iostream>

using namespace genv;
using namespace std;

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

    if((value==1) || (value == -1))
    {
        gout << ((value ==1) ? color(0,0,255) : color(255,0,0))
             << move_to(x+4, y+4) << line(meretx-8, merety-8)
             << move_to(x+5, y+4) << line(meretx-8, merety-8)
             << move_to(x+meretx-4, y+4) << line(-meretx+8, merety-8)
             << move_to(x+meretx-5, y+4) << line(-meretx+8, merety-8);

    }
/*


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
        for(int dx=0;dx<=meretx;dx++){
            for(int dy=0;dy<=meretx;dy++){
                if(dx*dx+dy*dy<=meretx*meretx){
                    gout<<color(255,255,255)<<move_to(x+dx+meretx/2,y+dy+merety/2)<<dot;
                }
            }
        }

    }
    */
}

int ShBox::getValue(){
    return value;
}

void ShBox::handle(genv::event ev,int &_timer,std::vector<std::vector<ShBox*>*> playground)
{
    //GameMaster ellenorzo;
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && value==0)
    {
        if(_timer%2==0){
            value=1;
            /*if(ellenorzo.handle(value,playground)){
                gout
                    <<color(0,0,0)<<move_to(0,0)<<box(800,800)
                    <<color(255,255,255)<<move_to(400-gout.twidth("A kék nyert"),400-gout.cascent())<<text("A kék nyert");
            }*/
        }
        else{
            value=-1;
            /*if(ellenorzo.handle(value,playground)){
                gout
                    <<color(0,0,0)<<move_to(0,0)<<box(800,800)
                    <<color(255,255,255)<<move_to(400-gout.twidth("A piros nyert"),400-gout.cascent())<<text("A piros nyert");
            }*/
        }
        _timer++;
    }
}





