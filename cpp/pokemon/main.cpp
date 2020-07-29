#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main()
{ 
  // Main Menu
  string input;
  cout << endl << "POKEMON ASCII" << endl << endl;
  cout << "Press any key to begin your adventure." << endl << endl;
  input = cin.get();

  // Start Game
  Game* game = new Game();
  game->Start();
}
