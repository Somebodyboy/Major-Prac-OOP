#include <bits/stdc++.h>
#include "Basketball.h"

using namespace std;

int main(){
    Basketball * basketball=new Basketball();

    // Testing out the variables
    // Checking the game name
    cout<<"\nActual value : "<<basketball->getName();
    cout<<"Expected value : Basketball\n\n";
    // Checking the maximum point you can get from the game
    cout<<"Actual value : "<<basketball->getMaxPoint();
    cout<<"\n";
    cout<<"Expected value : 30\n\n";
    // Checking the time limit of the game
    cout<<"Actual value : "<<basketball->getTimeLimit();
    cout<<"\n";
    cout<<"Expected value : 15\n\n";
    // Checking the initial score of the game
    cout<<"Actual value : "<<basketball->getScore();
    cout<<"\n";
    cout<<"Expected value : 0\n\n";
    // Checking how much score a successful shot gets
    cout<<"Actual value : "<<basketball->getScorePerShot();
    cout<<"\n";
    cout<<"Expected value : 2\n\n";
    // Checking the chances of the game
    cout<<"Actual value : \n";
    basketball->printChances();
    cout<<"\nExpected value : \nChance 1 75\nChance 2 52\nChance 3 30\n\n";

    // Testing out the gameplay
    basketball->play();
    cout<<"Score should be less than or equal to "<<basketball->getMaxPoint()<<"\n\n";

    return 0;
}