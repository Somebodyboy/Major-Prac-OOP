#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>

using namespace std;

class Game{
    private:
            string name;
            int maxPoint;
            static int globalPoint;
    public:
            vector<string> instructions;
            virtual void play()=0;
            virtual void result()=0;
            void howToPlay();
            int getMaxPoint();
            void setMaxPoint(int newMax);
            string getName();
            void setName(string newName);
            double getGlobalPoint();
            void setGlobalPoint(double points);
            virtual ~Game()=0;

    
};

#endif
