#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game {
    public: 
            virtual void play()=0;
            virtual void howToPlay()=0;
            virtual void result()=0;
            static string name;
            int maxPoint;
            
            static int globalPoint; //This will be used to add points from specific games 
                                    //so that the points add up globally
            vector<string> instructions;
};

#endif
