#ifndef BASKETBALL_H
#define BASKETBALL_H

#include <bits/stdc++.h>
#include "Game.h"

using namespace std;

class Basketball : public Game{
    int timeLimit;
    int chances[3];
    int score;
    int scorePerShot;
    public:
    Basketball();
    virtual void play();
    virtual void result();
    int askForShot();
    int getTimeLimit();
    void setScoreToZero();
    int getScore();
    void addScore();
    int getScorePerShot();
    void printChances();
};

#endif