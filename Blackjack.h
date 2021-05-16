#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Game.h"

//Blackjack
//Pays 1:1 regular, 2:1 on a Blackjack
//Rules based on the wikipedia page of Blackjack

class Blackjack: public Game {
public:
    class Card{
    public:
        Card();
        int value;
        string name;
        string suit;
    };

    class Player{
    public:
        Player();
        int handValue;
        vector<Card> hand;
        bool isSoft;
        void draw(Blackjack *game); //Draws a card from the deck and places it into a hand. Also removes that card from the deck.
        void calculateHand(); //Calculates the value total of a hand
    };
    void play(); //virtual
    void howToPlay(); //virtual
    void result(); //virtual
    static string name;
    int maxPoint;
    int bet;
    int money;
    int score;
    Player player;
    Player dealer;
    bool hideDealerHand;
    string input;
    vector<string> availableInputs;
    vector<Card> deck;
    void generateDeck(); //Creates and shuffles the deck on the heap, during runtime.
    void round(); //Starts a round of Blackjack
    int calculateScore();
    int setBet(); //Asks for a bet, verifies it and returns it.
    bool splitPlay();
    bool doublePlay();
    string getInput(vector<string> availableInputs); //Validates input for strings
    void render(); //Displays the table. Dealer hand + player hand + misc text
    void renderHand(vector<Card> hand); //Renders one hand
    void dealerTurn(); //Method for the dealer's turn. Draws until the hand value is 17 and up
    Blackjack();

};

#endif
