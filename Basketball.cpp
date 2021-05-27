#include "Basketball.h"
#include <bits/stdc++.h>

using namespace std;


// Initialises all the variables requried for the game to run
Basketball::Basketball(){
    this->timeLimit=15;
    this->chances[0]=75;
    this->chances[1]=52;
    this->chances[2]=30;
    this->scorePerShot=2;
    this->setScoreToZero();
    this->setMaxPoint(this->timeLimit*this->scorePerShot);
    this->setName("Basketball\n");
    this->instructions.push_back("You have 15 seconds to score as many points as possible");
    this->instructions.push_back("You can choose between three types of shots : fast, normal, and slow");
    this->instructions.push_back("A fast shot will take up 1 seconds with a 25% chance to score");
    this->instructions.push_back("A normal shot will take up 2 seconds with a 48% chance to score");
    this->instructions.push_back("A slow shot will take up 3 seconds with a 70% chance to score");
    this->instructions.push_back("Exceeding the time limit does not have a penalty, but you run out of chances when the time falls below 1");
}

// Starts the game and runs all the functions in the game
void Basketball::play(){
    this->timeLimit=15;
    this->setScoreToZero();
    this->howToPlay();
    while (timeLimit>0){
        cout<<"Time left : "<<this->timeLimit<<"\n";
        int chosenShot=this->askForShot();
        srand(time(0));
        int scoreChance=rand()%100+1;
        if (scoreChance>this->chances[chosenShot-1]){
            this->addScore();
            cout<<"\nYou scored!\n";
        }
        else{
            cout<<"\nOops, you missed!\n";
        }
        this->timeLimit-=chosenShot;
    }
    setGlobalPoint(this->getScore());
    this->result();
}

// Prints out the results of the game
void Basketball::result(){
    cout<<"\n-----------------------------------\n";
    cout<<"\nThank you for playing basketball\n";
    cout<<"\n"<<this->getScore()/2<<" shots on point\n";
    cout<<"\nYour final score is "<<this->getScore()<<"\n\n";
}

// Ask the user for a shot type
int Basketball::askForShot(){
    int newShot=0;
    cout<<"\nYou have three choices : \n";
    cout<<"1. Fast\n";
    cout<<"2. Normal\n";
    cout<<"3. Slow\n";
    while (newShot!=1 && newShot!=2 && newShot!=3){
        string shotInput;
        cout<<"\nPlease enter a value from 1-3 to make a choice : ";
        cin>>shotInput;
        if (shotInput.length()!=1 || shotInput[0]<'1' || shotInput[0]>'3'){
            continue;
        }
        newShot=shotInput[0]-'0';
    }
    return newShot;
}

// Resets the score to 0
void Basketball::setScoreToZero(){
    this->score=0;
}

// Returns the time limit of the game
int Basketball::getTimeLimit(){
    return this->timeLimit;
}

// Returns the current score the player got in the current game session
int Basketball::getScore(){
    return this->score;
}

// Adds to the player score when they make a successful shot
void Basketball::addScore(){
    this->score+=this->scorePerShot;
}

// Return the current point achieved with a successful shot
int Basketball::getScorePerShot(){
    return this->scorePerShot;
}

// Prints out the chances for each type of shots, mainly for testing
void Basketball::printChances(){
    for (int i=0; i<3; i++){
        cout<<"Chance "<<i+1<<" "<<this->chances[i];
        cout<<"\n";
    }
}

// Destructor
Basketball::~Basketball(){
    
}