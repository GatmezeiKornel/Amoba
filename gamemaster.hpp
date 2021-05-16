#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "shapebox.hpp"
#include <vector>

class GameMaster{
protected:
    int lastValue;
    int correctValue=0;
public:
    Gamemaster();
    bool rowCheck(int value,std::vector<std::vector<ShBox*>*> playground);
    bool columnCheck(int value,std::vector<std::vector<ShBox*>*> playground);
    bool diagLeftToRight(int value,std::vector<std::vector<ShBox*>*> playground);
    bool diagRightToLeft(int value,std::vector<std::vector<ShBox*>*> playground);
    bool handle(int value,std::vector<std::vector<ShBox*>*> playground);
};


#endif // GAMEMASTER_HPP_INCLUDED
