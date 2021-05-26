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
            double score;
    public:
            Fight();
            virtual void play();
            virtual void result();
            void setScore(double);
            double getScore();
            string getWord(int num);
            virtual ~Fight();
    
};

#endif
