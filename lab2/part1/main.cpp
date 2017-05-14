// Maria Beatriz Zanardo
// Lab 2, Part 1
// Main program

#include <iostream>
#include "carddeck.h"

using namespace std;

int main() {
  char option;
  int player, dealer, cardnum;
  int pscore = 0;       
  int dscore = 0;
  bool win;
  CardDeck D;
  while (option != 'q') {
    win = false;
    player = 0;
    dealer = 0;    

    cout << endl;
    cout << "Player's first card: " << endl;
    player = D.Deal();
    cout << endl;
    cout << "Dealer's first card: " << endl;
    dealer = D.Deal();
    cout << endl;
    cout << "Player's second card: " << endl;
    player = player + D.Deal();
    cout << "Player's sum: " << player << endl;
    cout << endl;
    if (player == 21) {
      cout << "The player won!" << endl;
      pscore++;
      win = true;
      continue;
    }

    if (player > 21) {
      cout << "The dealer won!" << endl;
      dscore++;
      win = true;
      continue;
    }

    cout << "Dealer's second card: " << endl;
    dealer = dealer + D.Deal();
    cout << "Dealer's sum: " << dealer << endl;
    cout << endl;    
    if (dealer == 21) {
      cout << "The dealer won!" << endl;
      dscore++;
      win = true;
      continue;
    }
    if (dealer > 21) {
      cout << "The player won!" << endl;
      pscore++;
      win = true;
      continue;
    }


    while ( (win = false) || (option != 'q') ) {
      if (dealer < 17) {
        cout << "The dealer hits." << endl;
        dealer = dealer + D.Deal();      
        cout << "Dealer's sum: " << dealer << endl;
        cout << endl;
        if (dealer == 21) {
          cout << "The dealer won!" << endl;
          dscore++;
          win = true;
          break;
        }
        if (dealer > 21) {
          cout << "The player won!" << endl;
          pscore++;
          win = true;
          break;
        }
      } 

      cout << "Player, do you want to hit or stand (h/s)?" << endl;
      cin >> option;
      if (option == 'h') {
        cout << "Player hits." << endl;
        player = player + D.Deal();
        cout << "Player's sum: " << player << endl;
        cout << endl;
      }

      if (player == 21) {
        cout << "The player won!" << endl;
        pscore++;
        win = true;
        break;
      }

      if (player > 21) {
        cout << "The dealer won!" << endl;
        dscore++;
        win = true;
        break;
      }
     
      if ( (option == 's') && (dealer >= 17) ) {
        if (player > dealer) {
          cout << "The player won!" << endl;
          pscore++;
          win = true;
          break;
        }
        if (player < dealer) {
          cout << "The dealer won!" << endl;
          dscore++;
          win = true;
          break;
        }
        if (player == dealer) {
          cout << "It's a tie!" << endl;
          win = true;
          break;
        }
      }
    }

    while ( (option != 'q')  && (option != 'c') ) {
      cout << "Score: " << endl;
      cout << "Player: " << pscore << endl;
      cout << "Dealer: " << dscore << endl;
      cout << "To play another round, press c. To quit, press q." <<endl;
      cin >> option;
    }
 
  }

return 0;
}
