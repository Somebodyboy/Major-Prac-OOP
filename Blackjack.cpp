#include "Blackjack.h"
#include <time.h> //time()
#include <stdlib.h> //srand(), rand()

//Not the best implementation in the whole world, but i guess it'll do


Blackjack::Card::Card(){
    name = "default";
    suit = "suit";
    value = 0;
}
Blackjack::Player::Player(){
    handValue = 0;
    isSoft = false;

}
Blackjack::Blackjack(){
    money = 100;
    bet = 0;
}
void Blackjack::play(){
    bool start = true;
    while(start){
        money = 100;
        cout << "Welcome to Blackjack." << endl;
        cout << "enter \"p\" to start a new game, "
        "\"i\" to read the instructions "
        "or \"q\" to quit." << endl;
        availableInputs = {"p","i","q"};
        input = getInput(availableInputs);
        if(input == "p"){
            generateDeck();
            while (true) {
             round();
             if (deck.size() < 10 || money == 0) {
                 break;
             }
             cout << "Play another round? Use \"p\" to start a new round, or \"q\" to quit." << endl;
             availableInputs = {"p","q"};
             input = getInput(availableInputs);
             if (input == "p") {continue;}
             else if(input == "q"){break;}
            }
            cout << "Game Over! Youe score is : unimplemented." << endl;
        }
        else if(input == "i"){howToPlay();}
        else if(input == "q"){start = false;}
    }
}

void Blackjack::howToPlay(){} //virtual
void Blackjack::result(){} //virtual

//Creates and shuffles the deck on the heap (vector), during runtime.
void Blackjack::generateDeck(){
    srand(time(NULL));
    deck.resize(52);
    vector<int> deckPosition;
    for (int i = 0; i < 52; i++) {
        deckPosition.push_back(i);
    }
    string name[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
    int cardvalue[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
    string suits[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    int i;
    int cardsRemaining = 52;
    Card newCard;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 13; k++) {
        i = rand() % cardsRemaining--;
        newCard.name = name[k];
        newCard.suit = suits[j];
        newCard.value = cardvalue[k];
        deck[deckPosition[i]] = newCard;
        deckPosition.erase(deckPosition.begin()+i);
        }
    }
    //Cheat with this. Prints out every card in order.
    /*for (int i = 0; i < 52; i++) {
        cout << deck[i].name << " of "<< deck[i].suit << endl;
    }*/
}

//Starts a round of Blackjack
void Blackjack::round(){
    bet = setBet();
    hideDealerHand = true;
    dealer.draw(this);
    player.draw(this);
    dealer.draw(this);
    player.draw(this);
    while(true){
        player.calculateHand();
        if (player.handValue >= 21) {
            break;
        }
        else if(player.handValue < 21){
            render();
            availableInputs = {"h", "s"};
            /* Split case. Write Later.
            if(player.hand.size() == 2){
                if (player.hand[0].name == player.hand[0].name) {
                    availableInputs.push_back("s");
                }
            }
            */
            input = getInput(availableInputs);
            cout << "\n\n";
            if (input == "s") { break;}
            else if (input == "h") {
                player.draw(this);
            }
            //else if (input == "s") {} //Split case.
        }
    }
    hideDealerHand = false;
    dealerTurn();
    render();
    if (dealer.handValue == player.handValue && player.handValue <= 21) { //Push
        cout << "Push. Your bet is returned.";
        money += bet;
    }
    else if (player.handValue > 21) { //Bust
        cout << "You bust. Your lose your bet.";
    }
    else if (player.handValue == 21) { //Blackjack
        cout << "Blackjack! Your bet is doubled and given.";
        money += bet*4;
    }
    else if (player.handValue > dealer.handValue) { //Win
        cout << "You win. Your bet is given.";
        money += bet*2;
    }
    else if (player.handValue < dealer.handValue) { //Lose
        cout << "You lose. Your bet is lost.";
    }
    cout << endl;
    player.hand.clear();
    dealer.hand.clear();
}

//Draws a card from the deck and places it into a hand. Also removes that card from the deck.
//Requires a reference to the Blackjack object instance since it is a nested class.
void Blackjack::Player::draw(Blackjack * game){
  hand.push_back(game->deck[0]);
  game->deck.erase(game->deck.begin());
}

//Calculates the value total of a hand
void Blackjack::Player::calculateHand(){
    int value = 0;
    for (int i = 0; i < hand.size(); i++) {
        value += hand[i].value;
        //Aces have a value of 11 or 1. Value is 1 if and only if the value is over 21 when the Ace is counted as 11.
        if (hand[i].value == 11) {
            isSoft = true;
            if (value > 21) {
                isSoft = false;
                value -= 10;
            }
        }

    }
    if(value == 21) { //If 21, no need for soft.
        isSoft = false;
    }
    handValue = value;
}

//Calculates the score based on rounds won and money left. Unimplemented.
int Blackjack::calculateScore(){return 0;}

//Asks for a bet, verifies it and returns it.
int Blackjack::setBet(){
    while (true) {
        cout << "Please enter your bet, 1-" << money << endl;
        cin >> bet;
        if (bet > 0 && bet <= money) {
            money -= bet;
            return bet;
        }
        cout << "Invalid bet, please try again!" << endl;
    }
}

//Unimplemented.
bool Blackjack::splitPlay(){return true;}
bool Blackjack::doublePlay(){return true;}

//Validates input for strings
string Blackjack::getInput(vector<string> availableInputs){
    while(true){
        cin >> input;
        for (int i = 0; i < availableInputs.size(); i++) {
            if (input == availableInputs[i]) {
                availableInputs.clear();
                return input;
            }
        }
        cout << "Invalid input, please try again!" << endl;
    }
}

//render().
//Displays the table. Dealer hand + player hand + misc text
//Example render (X's and -'s are whitespace.):
//Dealer's Hand:
//XQueenXX--XXTenXXX--XXFourXX--
//XXXOfXXX--XXXOfXXX--XXXOfXXX--
//Diamonds--XXCLUBSX--XSpadesX--
//
//Dealer's value: 123
//Player's value: 123
//
//Your Hand:
//XQueenXX--XXSixXXX--XXFourXX--
//XXXOfXXX--XXXOfXXX--XXXOfXXX--
//Diamonds--XXClubsX--XSpadesX--
//
//Money: 123   Bet: 123
void Blackjack::render(){
    cout << "Dealer's Hand:" << endl;
    if (hideDealerHand == true){ //Case for the starting hand where the dealer reveals only one card.
        dealer.handValue = dealer.hand[0].value;
        switch(dealer.hand[0].name.size()){
            case 3: cout << "  "; break;
            case 4: cout << "  "; break;
            case 5: cout << " "; break;
        }
        cout << dealer.hand[0].name << endl;
        cout << "   Of     Hidden" << endl;
        switch(dealer.hand[0].suit.size()){
            case 5: cout << "  " << dealer.hand[0].suit << " "; break;
            case 6: cout << " " << dealer.hand[0].suit << " "; break;
            case 8: cout << dealer.hand[0].suit; break;
        }
        cout << "    Card" << endl;
    }
    else{ //Default case, dealer reveals all his cards.
        renderHand(dealer.hand);
    }
    cout << endl;
    cout << "Dealer's Value: ";
    if (dealer.isSoft == true) {
        cout << "soft ";
    }
    cout << dealer.handValue << endl;
    cout << "Player's Value: ";
    if (player.isSoft == true) {
        cout << "soft ";
    }
    cout << player.handValue << "\n" << endl;
    cout << "Your Hand:" << endl;
    renderHand(player.hand);
    cout << endl;
    cout << "Money: " << money << "   Bet: " << bet << endl;
}

//Renders a single hand. Accompanies the render() method.
void Blackjack::renderHand(vector<Card> hand){
    for (int i = 0; i < hand.size(); i++) {
        switch(hand[i].name.size()){
            case 3: cout << "  " << hand[i].name << "     "; break;
            case 4: cout << "  " << hand[i].name << "    "; break;
            case 5: cout << " " << hand[i].name << "    "; break;
        }
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++) {
        cout << "   Of     ";
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++) {
        switch(hand[i].suit.size()){
            case 5: cout << "  " << hand[i].suit << " "; break;
            case 6: cout << " " << hand[i].suit << " "; break;
            case 8: cout << hand[i].suit; break;
        }
        cout << "  ";
    }
    cout << endl;
}

//Method for the dealer's turn. Draws until the hand value is 17 and up
void Blackjack::dealerTurn(){
    while (true) {
        dealer.calculateHand();
        if (dealer.handValue < 17) {
            dealer.draw(this);
        }
        else{
            break;
        }
    }
}
