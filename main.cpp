#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include "statictext.hpp"
#include "application.hpp"
#include "shapebox.hpp"
#include <vector>
using namespace genv;
using std::vector;

class MyApplication:public Application{
protected:
    vector<vector<ShBox*>> playground;
    int timer=0;
public:
    MyApplication(){
        for(int i=0;i<15;i++)
        {
            // uj vektor
            // push back
            vector<ShBox*> *row=new vector<ShBox*>;
            for(int j=0;j<15;j++)
            {
                // uj shbox
                // push back az el�z uj vektorba
                ShBox *temp=new ShBox(50,50,50,50);
                row->push_back(temp);
            }
            playground.push_back(row);
        }
    }
    void handle(MyApplication *window)
    {
        window->event_loop(playground,timer);
    }
};


int main()
{
    MyApplication *window=new MyApplication();
    window->handle(window);



    return 0;
}
