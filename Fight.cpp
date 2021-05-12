#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;

void Fight::play(){
    maxPoint = 0;
    word1 = "attack";
    word2 = "defend";
    word3 = "prestige";
    word4 = "random";
    word5 = "randomer";
    cout << "Enter 1 to start" << endl;
};

void Fight::howToPlay(){
    cout << "This is how to play the game" << endl;
};

void Fight::result(){
    cout << "Your end score is: " << maxPoint << endl;
    
};

int Fight::score(){
    
    return maxPoint*0.5;
};
