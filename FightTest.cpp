#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Fight.h"
using namespace std;

void test1(Game* fight1){
    cout << "Expected name: Word guessing fight game" << endl;
    cout << "Actual name: " << ((Fight*)fight1)->getName() << endl;
    ((Fight*)fight1)->setName("Random name");
    
    cout << "Expected name after changing: Random name" << endl;
    cout << "Actual name after changing: "  << ((Fight*)fight1)->getName() << endl;
    cout << "Actual name: " << ((Fight*)fight1)->getName() << endl;
    
    cout << "Instructions to the game should be shown now" << endl;
    ((Fight*)fight1)->howToPlay();
    
    
    //checking to see if the words for the game have been
    //initialized yet
    cout << "Expected output should be random letters or numbers or even blank spaces" << endl;
    cout << "Since the words have not been initialized yet" << endl;
    for(int i = 1; i < 6;i++){
        cout << ((Fight*)fight1)->getWord(i) << endl;
    }

    //calls play function which should display
    //a message for starting the game and initializes other variables in object
    cout << "Expected output: Enter 1 to start" << endl;
    cout << "actual output: ";
    ((Fight*)fight1)->play();

    //check to see what the words for the game look like now
    //after that the play function has been called
    cout << "Expected output: attack defend prestige haste teleport" << endl;
    for(int i = 1; i < 6;i++){
        cout << ((Fight*)fight1)->getWord(i) << " ";
    }
    cout << endl;
    
    //set score in object to 1000
    ((Fight*)fight1)->setScore(1000);

    //getting the score from the object
    int aScore = ((Fight*)fight1)->getScore();
    cout << "expected output: 1000" << endl;
    cout << "Actual output: "<< aScore << endl;
    
    //checking what output message and end score it shows
    cout << "expected output: Your end score is 1000" << endl;
    cout << "Actual output: ";
    ((Fight*)fight1)->result();
    //checking what the global points for the user are so far
    cout << "Expected output: 1000" << endl;
    cout << "Actual output: " << ((Fight*)fight1)->getGlobalPoint() << endl;
    return;
}

void test2(Game* fight2){
    
    cout << endl;
    cout << "This test to to check whether globalpoint static variable is actually working" << endl;
    cout << "This will use an object of the same class to add onto globalPoint variable" << endl;
    cout << endl;
    cout << "Expected output: Enter 1 to start" << endl;
    cout << "actual output: ";
    ((Fight*)fight2)->play();
    
    cout << "Setting score to 4000" << endl;
    //set score in object to 4000
    ((Fight*)fight2)->setScore(4000);

    //getting the score from the object
    int aScore = ((Fight*)fight2)->getScore();
    cout << "expected output: 4000" << endl;
    cout << "Actual output: "<< aScore << endl;
    
    cout << "Before result function is called" << endl;
    //checking what the global points for the user are so far
    cout << "Expected output: 1000" << endl;
    cout << "Actual output: " << ((Fight*)fight2)->getGlobalPoint() << endl;
    
    cout << "After result function is called" << endl;
    
    //checking what output message and end score it shows
    cout << "expected output: Your end score is 4000" << endl;
    cout << "Actual output: ";
    ((Fight*)fight2)->result();
    
    cout << "Expected output for globalPoint variable: 5000" << endl;
    cout << "Actual output for globalPoint variable: " << ((Fight*)fight2)->getGlobalPoint() << endl;
    
    return;
}


int main(){
    //makes Fighting game objects
    Game *fight1 = new Fight();
    Game *fight2 = new Fight();
    
    cout << "This test is used to see if the classes and objects of the classes are";
    cout << " functioning as expcted" << endl;
    cout << endl;
    
    test1(fight1);
    test2(fight2);
    
    delete ((Fight*)fight1);
    delete ((Fight*)fight2);
}
