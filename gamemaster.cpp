#include "gamemaster.hpp"
#include <vector>
#include <iostream>

using namespace std;

GameMaster::Gamemaster(){
}

bool GameMaster::rowCheck(int value,std::vector<std::vector<ShBox*>*> playground){
    lastValue=value;
    for(int j=0;j<15;j++){//oszlopok vizsgálata
                std::vector<ShBox*> *row = playground[j];
                for(ShBox* b : row[0])
                {
                    ShBox* box = b;
                    if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
                    //box->handle(ev,_timer);
                }
    }
    return false;
}

bool GameMaster::columnCheck(int value,std::vector<std::vector<ShBox*>*> playground){
    lastValue=value;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            std::vector<ShBox*> *row = playground[j];
            ShBox* box =row[0][i];
            if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
        }
    }
    return false;
}

bool GameMaster::diagLeftToRight(int value,std::vector<std::vector<ShBox*>*> playground){
    lastValue=value;
    int sorvaltozo=0;
    for(int i=10;i>0;i--)
    {
        for(int j=0;j<5+sorvaltozo;j++){
            std::vector<ShBox*> *row = playground[i+j];
            ShBox* box =row[0][j];
            if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
        }
        sorvaltozo++;
    }
    int oszlopvaltozo=0;
    for(int i=10;i>0;i--)
    {
        for(int j=0;j<5+oszlopvaltozo;j++){
            std::vector<ShBox*> *row = playground[j];
            ShBox* box =row[0][i+j];
            if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
        }
        oszlopvaltozo++;
    }
    return false;
}

bool GameMaster::diagRightToLeft(int value,std::vector<std::vector<ShBox*>*> playground){
        lastValue=value;
    int sorvaltozo=0;
    for(int i=5;i<15;i++)
    {
        for(int j=0;j<5+sorvaltozo;j++){
            std::vector<ShBox*> *row = playground[i-j];
            ShBox* box =row[0][j];
            if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
        }
        sorvaltozo++;
    }
    int oszlopvaltozo=0;
    for(int i=10;i>0;i--)
    {
        for(int j=0;j<5+oszlopvaltozo;j++){
            std::vector<ShBox*> *row = playground[14-j];
            ShBox* box =row[0][i+j];
            if(lastValue==box->getValue()){
                        correctValue++;
                        lastValue=value;
                        if(correctValue==5) return true;
                    }
                    else correctValue=0;
        }
        oszlopvaltozo++;
    }
    return false;
}

bool GameMaster::handle(int value,std::vector<std::vector<ShBox*>*> playground){
return (rowCheck(value,playground)||columnCheck(value,playground)||diagLeftToRight(value,playground)||diagRightToLeft(value,playground));


}
