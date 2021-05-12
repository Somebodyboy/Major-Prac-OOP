#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
using namespace std;

class Fight : public Game
{
    public:
            //Fight();
            virtual void play();
            virtual void howToPlay();
            virtual void result();
            int score();
            string word1;
            string word2;
            string word3;
            string word4;
            string word5;
            int start;
    
};

#endif
