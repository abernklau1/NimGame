#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Functions used/stated
int playerTurn( int numBall );
int computerStupid( int numBall );
int computerSmart( int numBall );

int main()
{

  // Starts the random number generator and changes it for each game
  srand( time( nullptr ) );

  // Randomizes inital ball count between 10 - 100
  int numBall = rand() % 91 + 10;

  // Randomizes inital turn and mode
  int turn = rand() % 2;
  int mode = rand() % 2;

  // Game starts
  cout << "***** Game of NIM Starts *****" << endl;
  cout << "Computer mode : " << ( mode == 0 ? "Smart" : "Stupid" ) << endl;

  // if there are still balls left, then keep playing
  while ( numBall >= 1 )
  {
    cout << "\tBall count: " << numBall << endl;

    // Determines if it's the player's turn and follows the correct function
    if ( turn == 0 )
    {
      cout << "\nPLAYER TURN" << endl;
      numBall = playerTurn( numBall );
      turn    = 1; // switch the turn to 1 for computer turn next
    }

    // Determines the computer's turn, mode, and follows the correct function
    else
    {
      if ( mode == 0 )
      {
        cout << "\nCOMPUTER TURN" << endl;
        numBall = computerSmart( numBall );
      }
      else
      {
        cout << "\nCOMPUTER TURN" << endl;
        numBall = computerStupid( numBall );
      }
      turn = 0;
    }

    // Switch turn to 0 to make it player's turn
  }

  cout << "\tBall count: " << numBall << endl;

  // IF and ELSE statements used to output the game winner
  if ( turn == 0 && numBall == 0 )
  {
    cout << "\n***** GAME of NIM Winner! PLAYER *****\n\n";
  }
  else
  {
    cout << "\n***** Game of NIM Winner! COMPUTER *****\n\n";
  }

  // Returns updated answer to keep looping
  return 0;
}

// Function for player's turn
int playerTurn( int numBall )
{
  int playerInput;
  cout << "\nInsert Number Here: ";
  while ( !( cin >> playerInput ) || ( playerInput <= 0 || ( playerInput > ceil( numBall / 2 ) && playerInput != 1 ) ) )
  {
    
    if ( cin.fail() || ( playerInput <= 0 || ( playerInput > ceil( numBall / 2 ) && playerInput != 1 ) ) )
    {
      cout << "******INSERT A VALID NUMBER.******\n";
      cout << "\nInsert Number Here: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
  }
  numBall -= playerInput;
  return numBall;
}

// Function for computer's turn (stupid mode)
int computerStupid( int numBall )
{
  int computerInput;
  if ( numBall > 1 )
  {
    // Randomizes how many ball(s) computer takes and updates ball count with output
    computerInput = rand() % ( numBall / 2 ) + 1;
  }
  else
  {
    computerInput = 1;
  }
}

// Function for computer smart
int computerSmart( int numBall )
{

  // list power of 2 minus 1 numbers (#^2-1)
  int numList[5] = { 3, 7, 15, 31, 63 };
  int computerInput;

  // Loops through list from biggest to smallest
  for ( int i = 4; i >= 0; i-- )
  {
    if ( numBall >= numList[i] )
    {
      computerInput = numBall - numList[i];
      break;
    }
  }

  if ( !computerInput && numBall > 2 )
  {
    computerInput = rand() % ( numBall / 2 ) + 1;
    cout << computerInput << endl;
  }
  else if ( !computerInput || numBall <= 2 )
  {
    computerInput = 1;
  }

  numBall -= computerInput;
  cout << "Computer chose: " << computerInput << endl;
  // Return the new numBall
  return numBall;
}
