#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
using namespace std;

class Fight : public Game
{
    private:
            string words[5];
            int score;
    public:
            Fight();
            virtual void play();
            virtual void result();
            void setScore(int);
            int getScore();
            string getWord(int num);
            ~Fight();
    
};

#endif
