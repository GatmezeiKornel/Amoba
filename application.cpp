#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "shapebox.hpp"
#include "gamemaster.hpp"
#include <vector>

using namespace genv;

void Application::event_loop(std::vector<std::vector<ShBox*>*> playground, int &_timer) {
    event ev;
    int focus = -1;
    GameMaster ellenorzo;
    while(gin >> ev ) {
        if(!ellenorzo.handle(1,playground) && !ellenorzo.handle(-1,playground) && !ellenorzo.PgIsFull(playground))
        {
            if (ev.type == ev_mouse && ev.button==btn_left)
            {
                for(int j=0;j<15;j++){//oszlopok vizsgálata
                    vector<ShBox*> *row = playground[j];
                    for(ShBox* b : row[0])
                    {
                        ShBox* box = b;
                        box->handle(ev,_timer,playground);
                        box->Draw();
                    }
                }
            }
        }
        if(ellenorzo.handle(1,playground)){
            gout
                <<color(0,0,0)<<move_to(0,0)<<box(800,800)
                <<color(255,255,255)<<move_to(400-gout.twidth("A kék nyert")/2,400-gout.cascent())<<text("A kék nyert");
        }
        if(ellenorzo.handle(-1,playground)){
            gout
                <<color(0,0,0)<<move_to(0,0)<<box(800,800)
                <<color(255,255,255)<<move_to(400-gout.twidth("A piros nyert")/2,400-gout.cascent())<<text("A piros nyert");
        }
        if(ellenorzo.PgIsFull(playground))
        {
            gout
                    <<color(0,0,0)<<move_to(0,0)<<box(800,800)
                    <<color(255,255,255)<<move_to(400-gout.twidth("A pálya megtelt, döntetlen"),400-gout.cascent())<<text("A pálya megtelt, döntetlen");
        }

        gout << refresh;
    }

}
