#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Game.h"
#include <string>

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
    void result(); //virtual. Calculates the score based on rounds played and money left.
    static string name;
    int bet;
    int money;
    int score;
    int rounds;
    Player player;
    Player dealer;
    bool hideDealerHand;
    string input;
    vector<string> availableInputs;
    vector<Card> deck;
    void generateDeck(); //Creates and shuffles the deck on the heap, during runtime.
    void round(); //Starts a round of Blackjack
    int setBet(int limit); //Asks for a bet up to a limit, verifies it and returns it.
    bool splitActive; //splitPlay active, true when the last round was a split.
    void splitPlay();
    void doublePlay();
    string getInput(vector<string> availableInputs); //Validates input for strings
    void render(); //Displays the table. Dealer hand + player hand + misc text
    void renderHand(vector<Card> hand); //Renders one hand
    void dealerTurn(); //Method for the dealer's turn. Draws until the hand value is 17 and up
    Blackjack();

};

#endif
