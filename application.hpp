#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>
#include "widgets.hpp"

using namespace genv;

class Application{
public:
    void event_loop(std::vector<Widget*> widgets);
};

#endif // APPLICATION_HPP_INCLUDED
