#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;
Fight::Fight(){
    setName("Word guessing fight game");
    instructions.push_back("This is a game where you try to guess 5 words");
    instructions.push_back("The first letter of every new word is given to you");
    instructions.push_back("The first letter that is given can be contained inside the word again");
    instructions.push_back("Each time you guess a letter in a word correctly, your score goes up by 5");
    instructions.push_back("For every letter you get right consecutively, the points gained are increased by another 5");
    instructions.push_back("Each time you guess a letter incorrectly, the multiplier is set back to zero and 5 points are reduced from your score");
    instructions.push_back("IMPORTANT: If you want to exit the game, enter E (in capital)");
};

void Fight::play(){
    setMaxPoint(100);
    setScore(0);
    
    words[0] = "attack";
    words[1] = "defend";
    words[2] = "prestige";
    words[3] = "haste";
    words[4] = "teleport";
    cout << "Enter 1 to start" << endl;
};
string Fight::getWord(int num){
    switch(num){
        case 1:
        return words[0];
        break;
        
        case 2:
        return words[1];
        break;
        
        case 3:
        return words[2];
        break;
        
        case 4:
        return words[3];
        break;
        
        case 5:
        return words[4];
        break;
        
        default:
        break;
    }
    return 0;
};

void Fight::setScore(int aScore){
    score = aScore;
};

int Fight::getScore(){
    return score;
};

void Fight::result(){
    cout << "Your end score is: " << getScore() << endl;
    setGlobalPoint(getScore());
    
};

Fight::~Fight(){
    
};
