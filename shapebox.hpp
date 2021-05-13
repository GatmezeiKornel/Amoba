#ifndef SHAPEBOX_HPP_INCLUDED
#define SHAPEBOX_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"


class ShBox:public Widget{
protected:
    int value=0;
public:
    ShBox(int _x, int _y, int _meretx, int _merety);
    void Draw() override;
    void handle(genv::event ev,int &_timer);

};


#endif // SHAPEBOX_HPP_INCLUDED
