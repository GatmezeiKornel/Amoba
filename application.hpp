#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>
#include "widgets.hpp"
#include "shapebox.hpp"

using namespace genv;
using std::vector;

class Application{
public:
    void event_loop(vector<vector<ShBox*>*> playground,int &_timer);
};

#endif // APPLICATION_HPP_INCLUDED
