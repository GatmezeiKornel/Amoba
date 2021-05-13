#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;

void Application::event_loop(std::vector<Widget*> widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->Draw();
        }
        gout << refresh;
    }
}
