#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "shapebox.hpp"
#include <vector>

using namespace genv;

void Application::event_loop(std::vector<std::vector<ShBox*>*> playground, int &_timer) {
    event ev;
    int focus = -1;

    /*vector<ShBox*> *row = playground[0];
    for(ShBox* b : row[0])
    {
        ShBox* box = b;
    }
*/
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left)
            {
        for(int j=0;j<15;j++){//oszlopok vizsgálata
                //vector<ShBox> *row = playground[j];
                vector<ShBox*> *row = playground[j];
                for(ShBox* b : row[0])
                {
                    ShBox* box = b;
                    box->handle(ev,_timer);
//                    if (box->is_selected(ev.pos_x, ev.pos_y)) {
  //                  }
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
        gout << refresh;
    }

}
