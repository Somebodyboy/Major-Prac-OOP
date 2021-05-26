#include "Game.h"

#include <bits/stdc++.h>

using namespace std;

int Game::globalPoint = 0;

void Game::howToPlay(){
    cout<<"Here are the instructions for how to play "<<this->getName()<<"\n";
    for (int i=0; i<int(instructions.size()); i++){
        cout<<i+1<<". "<<instructions[i]<<"\n";
    }
    cout<<"\n";
}
int Game::getMaxPoint(){
    return this->maxPoint;
}
void Game::setMaxPoint(int newMax){
    this->maxPoint=newMax;
}
string Game::getName(){
    return this->name;
}
void Game::setName(string newName){
    this->name=newName;
}

void Game::setGlobalPoint(int points){
    globalPoint = globalPoint + points;
};

int Game::getGlobalPoint(){
    return globalPoint;
};

Game::~Game(){
    
};
