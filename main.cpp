#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"
#include "shapebox.hpp"
#include <vector>
using namespace genv;
using std::vector;

class MyApplication:public Application{
protected:
    vector<vector<ShBox*>*> playground;
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
                // push back az elõz uj vektorba
                 ShBox *temp = new ShBox(40 + j * 40,40 + i *40,40,40);
                row->push_back(temp);
            }
            playground.push_back(row);
        }
    }
    void handle(MyApplication *window)
    {
        gout.open(800,800);
        window->event_loop(playground,timer);
    }
};


int main()
{
    MyApplication *window=new MyApplication();
    window->handle(window);



    return 0;
}
