#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "statictext.hpp"
#include "application.hpp"
#include <vector>
using namespace genv;
using std::vector;

class MyApplication:public Application{
protected:
    vector<vector<Widget*>> playground;
public:
    MyApplication(){
        for(int i=0;i<15;i++)
        {
            for(int i=0;i<15;i++)
            {

            }
        }
    }
    void handle(MyApplication *window)
    {
        window->event_loop(vector<Widget*> playground);
    }
};


int main()
{
    MyApplication *window=new MyApplication();
    window->handle(window);



    return 0;
}
