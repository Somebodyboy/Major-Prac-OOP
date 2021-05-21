#include <bits/stdc++.h>
#include "Game.h"
#include "Fight.h"
#include "Basketball.h"
// #include "Blackjack.h"

using namespace std;

// All of our external game functions should go here
extern void FightFunc(Game**);

int main(){
    
    //This is where all of our games go in to one Games pointer array
    int numberOfGames=3;
    Game * games[numberOfGames];
    
    //take comment off once Basketball and Blackjack
    //have been implemented
    
    games[0] = new Basketball();
    //games[1] = new BlackJack();
    games[2] = new Fight;

    // Game options stored in an array
    int numberOfOptions = 7;
    string options[7] = {"Basketball\n","Blackjack\n","Fight\n","View game history\n","Prize corner\n","View My Prizes\n","Exit\n"};

    // Game history
    vector<string> gameHistory;

    // Prize corner
    int numberOfPrizes=5;
    string prizes[numberOfPrizes]={"High-tech gaming mouse","Office mouse","Mug","Small plushie","Stickers"};
    int basePrize=300; // This is the base prize, just divide by the index+1 for the price of each prize
    vector<string> userPrizes; // Contains the user's collected prizes

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
        while (userSelectedChoice.length()!=1 || userSelectedChoice[0]<'1' || userSelectedChoice[0]>'7' || userSelectedChoice[1]==' '){
            cout<<"Please select a valid number between 1-7 : ";
            cin>>userSelectedChoice;
        }

        // Handling user input
        int convertedChoice=int(userSelectedChoice[0])-'0'-1;
        cout<<"\nYou selected "<<options[convertedChoice]<<"\n";
        if (convertedChoice==6){
            break;
        }
        switch(convertedChoice){
            case 0:
                // Run basketball
                games[0]->play();
                gameHistory.push_back(options[0]);
                break;
            case 1:
                //Run blackjack
                gameHistory.push_back(options[1]);
                break;
            case 2:
                // Run Fight
                FightFunc(games);
                gameHistory.push_back(options[2]);
                break;
            case 3:
                //Run view game history
                cout<<"Your game history:\n";
                for (int i=0; i<int(gameHistory.size()); i++){
                    cout<<i+1<<". "<<gameHistory[i];
                }
                cout<<"\n";
                break;
            case 4:
                //Run prize corner
                cout<<"Your current amount of points : "<<games[0]->getGlobalPoint()<<"\n\n";
                for (int i=0; i<numberOfPrizes; i++){
                    cout<<i+1<<". "<<prizes[i]<<" - "<<basePrize/(i+1)<<" Points"<<"\n";
                }
                cout<<"\n";
                break;
            case 5:
                //Run view my prizes
                cout<<"The prizes you have earned:\n";
                for (int i=0; i<int(userPrizes.size()); i++){
                    cout<<i+1<<". "<<userPrizes[i]<<"\n";
                }
                cout<<"\n";
                break;
            default:
                cout<<"Invalid\n";
                break;
        }
    }

    // Goodbye message
    cout<<"Thank you for playing the Virtual Arcade\n\n";
    // cout << games[0]->getGlobalPoint() << endl;

    return 0;
}
    
