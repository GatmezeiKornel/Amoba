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

    /*vector<ShBox*> *row = playground[0];
    for(ShBox* b : row[0])
    {
        ShBox* box = b;
    }
*/
    while(gin >> ev ) {
        if(!ellenorzo.handle(1,playground) && !ellenorzo.handle(-1,playground) && !ellenorzo.PgIsFull(playground))
        {
            if (ev.type == ev_mouse && ev.button==btn_left)
            {
                for(int j=0;j<15;j++){//oszlopok vizsgálata
                    //vector<ShBox> *row = playground[j];
                    vector<ShBox*> *row = playground[j];
                    for(ShBox* b : row[0])
                    {
                        ShBox* box = b;
                        box->handle(ev,_timer,playground);
        //              if (box->is_selected(ev.pos_x, ev.pos_y)) {
          //            }
                        box->Draw();
                    }
        /*

                    for (size_t i=0;i<playground[j]->size();i++) {//sorok vizsgálata



                        ShBox* box = row[i];
                        if (&row[i].is_selected(ev.pos_x, ev.pos_y)) {//elem azonosítása
                                focus = i;//azonosító
                        }
                    }
                    if (focus!=-1) {
                        playground[j][focus].handle(ev,_timer);
                        focus = -1;
                    }
                    for (std::vector<ShBox*> * w : playground[j]) {
                        w->Draw();
                    }
                    */
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
                <<color(255,255,255)<<move_to(400-gout.twidth("A kék nyert")/2,400-gout.cascent())<<text("A kék nyert");
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
