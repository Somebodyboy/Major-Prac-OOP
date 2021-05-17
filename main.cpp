#include <bits/stdc++.h>
// #include "Game.h"
// #include "Fight.h"
#include "Basketball.h"
// #include "Blackjack.h"

using namespace std;

// All of our external game functions should go here
// extern int FightFunc(Game** game);

int main(){
    
    //This is where all of our games go in to one Games pointer array
    Game * games[3];
    
    //take comment off once Basketball and Blackjack
    //have been implemented
    
    games[0] = new Basketball();
    //games[1] = new BlackJack();
    //games[2] = new Fight;

    // Game options stored in an array
    int numberOfOptions=6;
    string options[numberOfOptions]={"Basketball\n","Blackjack\n","Fight\n","View game history\n","Prize corner\n","Exit\n"};

    // Prize corner
    // string prizes[5]={"High-tech gaming mouse","Office mouse","Mug","Small plushie","Stickers"};
    // int basePrize=300; // This is the base prize, just divide by the index+1 for the price of each prize
    // vector<string> userPrizes; // Contains the user's collected prizes

    // Welcome message
    cout<<"\n\nWelcome to the Virtual Arcade!\n";

    // Initialise arcade
    while (true){

        // Options
        cout<<"Please enter the number for the option you would like\n";
        for (int i=0; i<numberOfOptions; i++){
            cout<<i+1<<". "<<options[i];
        }
        cout<<"\n";

        // User input and validation
        string userSelectedChoice="0";
        while (userSelectedChoice.length()!=1 || userSelectedChoice[0]<'1' || userSelectedChoice[0]>'6' || userSelectedChoice[1]==' '){
            cout<<"Please select a valid number between 1-6 : ";
            cin>>userSelectedChoice;
        }

        // Handling user input
        int convertedChoice=int(userSelectedChoice[0])-'0'-1;
        cout<<"\nYou selected "<<options[convertedChoice]<<"\n";
        if (convertedChoice==5){
            break;
        }
        switch(convertedChoice){
            case 0:
                games[0]->play();
                break;
            case 1:
                //Run blackjack
                break;
            case 2:
                //Run fight
                break;
            case 3:
                //Run view game history
                break;
            case 4:
                //Run prize corner
                break;
            default:
                cout<<"Invalid\n";
                break;
        }
    }

    // Goodbye message
    cout<<"Thank you for playing the Virtual Arcade\n\n";

    return 0;
}
    
    
