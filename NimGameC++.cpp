#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//Functions used/stated
int playerTurn(int numBall);
int computerStupid(int numBall);
int computerSmart(int numBall);

int main() {
    
    //Starts the random number generator and changes it for each game
    srand(time(nullptr));

    //Randomizes inital ball coount between 10 - 100
    int numBall = rand()%91 + 10;
    
    //Randomizes inital turn and mode
    int turn = rand() % 2; 
    int mode = rand() % 2; 

    // PROCESS - play the game of NIM taking turns
    cout << "***** Game of NIM Starts *****" << endl;
    
    // if there are still balls left, then keep playing
    while (numBall > 1) { 
        cout << "\t\tBall count: " << numBall << endl;
        
        //Determins if its the players turn and follows the correct function
        if (turn == 0) {
            cout << "\n\tPLAYER TURN" << endl;
         numBall = playerTurn (numBall);
            turn = 1; // switch the turn 1 - for computer turn next
        }
        
        //Determins the computers turn, mode and follows the correct function
        else {
            if (mode == 0) {
                cout << "\n\tCOMPUTER TURN - Mode: Smart" << endl;
             numBall = computerSmart (numBall);
            }
            else {
                cout << "\n\tCOMPUTER TURN - Mode: Stupid" << endl;
             numBall = computerStupid (numBall);
            }
            
            
            //Switchs turn to 0 to make it players turn
            turn = 0; 
        }
    }
    
    cout << "\t\tBall count: " << numBall << endl;
    
    
    //IF and ELSE statments used to output the game winner
    if (turn == 0 && numBall == 0) {
        cout << "\n***** GAME of NIM Winner! PLAYER *****\n\n";
    }
    else {
        cout << "\n***** Game of NIM Winner! COMPUTER *****\n\n";
    }

    //Returns updated answer to keep looping
    return 0;
}

//Function for players turn
int playerTurn(int numBall) {

    //Checks if numBall = 1 and makes player to take it   
    if  (numBall == 1) {
        
        //While statment for loop(s)
        while (true) {
            int playerInput;
            cout << "\nInsert Number Here: ";
            cin >> playerInput;
            
            //Subtract the ball(s) and return the new count if input = 1
            if (playerInput == 1) {
             numBall -= playerInput;
                return numBall; 
            } 
            
            //Else statment to output error for invalid input
            else {
                cout << "******INSERT A VALID NUMBER.******\n"; 
                continue;
            }
        }
    } 
    
    //Else statment to determine if the player can take more than 1
    else {
        while (true) {
            int playerInput;
            cout << "\nInsert Number Here: ";
            cin >> playerInput;
            
            //If players input is valid, subtract from the ball count and return
            if (0 < playerInput && playerInput <= ceil((numBall / 2))){
             numBall = numBall - playerInput;
                return numBall;
                }
            
            //Error if player input is invalid
            else {
                cout << "******INSERT A VALID NUMBER.******\n";
                continue;
            }
        }
    }
}

//Function for computer stupid 
int computerStupid (int numBall) {
    
    if (numBall > 0) {
        
        //Randomizes how many ball(s) computer takes and updates ball count /w output
        int computerInput = rand() %  (numBall / 2) + 1;
     numBall = numBall - computerInput;
        cout << "Computer picks " << computerInput << " ball(s)." << endl;
    }
    //Returns ball count
    return numBall;
}

//Function for computer smart
int computerSmart (int numBall) {
    
    //list of power of two minus one numbers (x^2-1)
    int numList[] = {3, 7, 15, 31, 63};
    
    //Loops through list from biggest to smallest
    for (int i = 9; i >= 0; i--) {
        
        //If the current number of balls is >= twoPowerList[i], calculates # to pick
        if (numBall >= numList[i]) {
            int computerInput = numBall - numList[i];
         numBall = numBall - computerInput;
            cout << "Computer picks " << computerInput << " ball(s)." << endl;
            break;
        }
    }
    
    // If numBall is not greater than any power of two minus one, play randomly
    int computerInput = rand() %  (numBall / 2) + 1;
    numBall = numBall - computerInput;
    cout << "Computer chooses: " << computerInput << endl;
    
    // Return the new numBall
    return numBall;
}
