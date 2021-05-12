#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "button.hpp"
#include "graphics.hpp"

using std::string;

class StText: public Button{
public:
    StText(int _x, int _y, int _width, int _height,string _content);
    //void handle(genv::event ev) override;
};


#endif // STATICTEXT_HPP_INCLUDED
