#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "statictext.hpp"
#include "application.hpp"
using namespace genv;

class MyApplication:public Application{
protected:
    StText st;
    Button bt;
public:
    MyApplication(){
    }

};


int main()
{
    MyApplication *window=new MyApplication();
    gout <<text("hello world")<< refresh;
    window->event_loop();

    return 0;
}
