#ifndef SHAPEBOX_HPP_INCLUDED
#define SHAPEBOX_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>


class ShBox:public Widget{
protected:
    int value=0;
public:
    ShBox(int _x, int _y, int _meretx, int _merety);
    void Draw() override;
    int getValue();
    void handle(genv::event ev,int &_timer,std::vector<std::vector<ShBox*>*> playground);

};


#endif // SHAPEBOX_HPP_INCLUDED
