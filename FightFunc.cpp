#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;

int FightFunc(Game** game){
    
    //Tells user how to play the game
    ((Fight*)game[2])->howToPlay();
    
    //Is string because if user enters string instead of int
    //in an int variable, it breaks the code
    string start = "0";
    
    //This is where user has to input 1 to start the game
    //otherwise it will keep looping and displaying the same message
    while(start != "1"){
        ((Fight*)game[2])->play();
        cin >> start;
    }
    
    
    
    //returns points gained from game.
    return ((Fight*)game[2])->score();
};
