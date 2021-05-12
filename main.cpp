#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;

//All of our external game functions should go here
extern int FightFunc(Game** game);
    

int main(){
    //This is where all of our games go in to one Games pointer array
    Game* games[3];
    
    //take comment off once Basketball and Blackjack
    //have been implemented
    
    //games[0] = new Basketball();
    //games[1] = new BlackJack();
    games[2] = new Fight;
    
    //Arcade welcome message and name input message
    cout << "Welcome to the arcade!" << endl;
    
    cout << "Enter your name: " << endl;
    
    //name is static across all children so the cast and array number
    //can be changed and it should stil give everyone the same name
    cin >> ((Fight *)games[2])->name;
    
    cout << ((Fight *)games[2])->name << endl;
    
    //this option will be used to determine which game the user wants to play
    
    //string for option because if it's int type and user enters a string
    //it breaks the code
    string option = "0";
    int check = 0;
    
    //This is where the user gets the options and the numbers associated with them
    cout << "1. BasketBall" << endl;
    cout << "2. BlackJack" << endl;
    cout << "3. Fighting game" << endl;
    cout << "Please pick the number you want to play" << endl;
    
    //This loop is to make sure the user enters a number between
    //1-3
    while((check != 1)){
        cin >> option;
        if(option == "1" || option == "2" || option == "3"){
            check = 1;
        }
    }
    
    //If they picked option 3, the FightFunc will be used
    if(option == "3"){
        FightFunc(games);
    }
    
    return 0;
}
    
