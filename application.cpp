#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "shapebox.hpp"
#include <vector>

using namespace genv;

void Application::event_loop(std::vector<std::vector<ShBox*>> playground, int &_timer) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
        for(int j=0;j<15;j++){
                for (size_t i=0;i<playground[j].size();i++) {
                    if (playground[j][i]->is_selected(ev.pos_x, ev.pos_y)) {
                            focus = i;
                    }
                }
                if (focus!=-1) {
                    playground[focus][j]->handle(ev,_timer);
                }
                for (std::vector<ShBox*>  w : playground) {
                    w[j]->Draw();
                }
            }
        }
        gout << refresh;
    }
}
