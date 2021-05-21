#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include "Game.h"
#include "Fight.h"

using namespace std;

void FightFunc(Game** game){
    //the max amount of points a user can get
    ((Fight*)game[2])->setMaxPoint(100);
    
    //sets to the first word number index
    int wordNum = 0;
    //this is the score
    double score = 0.0;
    //this is the score multiplier that will
    //that will increase everytime the user guesses correctly
    //one letter after another. Set to zero if letter guessed wrong
    double multiplier = 0.0;
    
    //this will be the current word being guessed
    //from the words listed in the class
    string currentWord;
    
    //Tells user how to play the game
    ((Fight*)game[2])->howToPlay();
    
    //Is string because if user enters string instead of int
    //in an int variable, it breaks the code
    string start = "0";
    
    //This is where user has to input 1 to start the game
    //otherwise it will keep looping and displaying the same message
    while(start != "1"){
        ((Fight*)game[2])->play();
        cin >> start;
    }
    
    //this is the amount of words guessed by the user
    int wordsGuessed = 0;
    
    //while loop for the game
    //this will end when the user has guessed all words 
    //meaning wordsGuessed = 5
    while(true){
        //increases the wordNum each time a new word is guessed fully
        wordNum++;
        
        //new current word is set for the game using the wordNum index
        currentWord = ((Fight*)game[2])->getWord(wordNum);
        
        //the char array that will be displayed with "_" on each part of the word
        //yet to be guessed and displaying all the letters already guessed in the word
        //in sequenced order.
        char wordToGuess[currentWord.length() + 1];
        
        cout << "The word you have to guess is" << endl;
        //this is setting up the wordGuess array and displaying the word they have to guess
        //Letters to be guessed will be shown and stored as "_" and the first letter of the word
        //is shown to the user and also stored in the wordGuess array
        for(int i = 0; i < int(currentWord.length()); i++){
            if(i == 0){
                wordToGuess[i] = currentWord[i];
                cout << wordToGuess[i] << " ";
            }
            else if(i > 0){
                wordToGuess[i] = '_';
                cout << wordToGuess[i] << " ";
            }
        }
        cout << endl;
        
        //This is where the user will input a character or series of characters
        //and this will be compared to the letters in the current word in the next loop
        char guessLetter;
        //this is to check the number of letters the user has guessed
        //when this = currentWord length, the next word will be initiated
        int checkLength = 1;
        
        //loop for the current word
        //keeps looping until current word is fully guessed
        while(true){
            
            int correctGuessCheck = 0;
            //stores letter user inputs in guessLetter
            cout << "enter letter" << endl;
            cin >> guessLetter;
            
            //guessLetter is compared to all letters in the word to be guessed
            //and then the word is displayed once again with (if any)
            //new letters added to the word
            for(int i = 0; i < int(currentWord.length()); i++){
                //if the guessed letter matches a letter in the whole word and 
                //is being displayed as "_" to the user, the "_" is replaced by the letter
                //and checkLength is incremented by 1
                if(guessLetter == currentWord[i] && wordToGuess[i] == '_'){
                    wordToGuess[i] = currentWord[i];
                    multiplier = multiplier + 0.05;
                    score = score + (multiplier * ((Fight*)game[2])->getMaxPoint());
                    checkLength++;
                    correctGuessCheck = 1;
                }
                cout << wordToGuess[i] << " ";
            }
            cout << endl;
            
            //if a letter contained in the current word is guessed correctly by the user
            //the user is shown how much damage they have delt
            if(correctGuessCheck == 1){
                cout << "Delt " << multiplier * ((Fight*)game[2])->getMaxPoint() << " damage!" << endl;
            }
            
            //this if statement to check if the entered letter was a letter contained
            //inside of the word that was to be guessed
            //if not, multiplier reset back to 0 and 5 points taken off
            //the user's score
             if(currentWord.find(guessLetter) > currentWord.length()){
                 multiplier = 0;
                 score = score - 5;
                 cout << "Took 5 damage!" << endl;
                
            }
            
            //user's score so far shown
            cout << "score so far: " << score << endl;
            
            //break inner while loop if the whole word is guessed
            //meaning checkLength is equal to the length of the whole
            //word that was to be guessed
            //wordsGuessed is also incremented by 1
            if(checkLength == int(currentWord.length())){
                wordsGuessed++;
                break;
            }
        }
        //when wordsGuessed are 5, the user has guessed all words
        //thus breaking the loop and completing the game
        if(wordsGuessed == 5){
            break;
        }
    }
    
    //gives the score/points earned from the function to the class
    ((Fight*)game[2])->setScore(score);
    
    //shows user their final score
    //and updates global points user has earned
    ((Fight*)game[2])->result();
    
    return;
}
