#include "application.hpp"
#include "graphics.hpp"

using namespace genv;

void event_loop(genv::event ev){
    gout.open(400,400);
    while(gin >> ev) {

        refresh();
    }
}
