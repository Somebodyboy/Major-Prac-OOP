#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;

int FightFunc(Game** game){
    
    string start = "0";
    ((Fight*)game[2])->howToPlay();
    
    while(start != "1"){
        ((Fight*)game[2])->play();
        cin >> start;
    }
    
    
    
    
    return ((Fight*)game[2])->score();
};
