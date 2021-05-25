#include "Blackjack.h"

using namespace std;

int main(){
    Blackjack blackjack;

    //Set up a pre-made deck for testing.
    string name[8] = {"Ten","Ace","Seven","King","Queen","Jack","Queen","Seven"};
    int cardvalue[8] = {10,11,7,10,10,10,10,7};
    Blackjack::Card newCard;
    for (int i = 0; i < 8; i++) {
        newCard.name = name[i];
        newCard.suit = "Suits";
        newCard.value = cardvalue[i];
        blackjack.deck.push_back(newCard);
    }

    cout << "Testing round()"  << endl;
    cout << "Testing setBet()" << endl;
    blackjack.round();
    blackjack.round();

    cout << endl;

    cout << "Testing getInput()" << endl;
    vector<string> testInputs = {"h"};
    cout << "Looking for: h" << endl;
    string x = blackjack.getInput(testInputs);
    cout << "Result: " << x << endl;


    return 0;
}
