// Maria Beatriz Zanardo
// Lab 2
// Implementation for Card Deck Class

#include "carddeck.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

CardDeck::CardDeck(int n) {
  size = n;
  deck = new int[size];
  for (int i = 0; i != (size-1); i++) {
    deck[i] = i;
  }
  shuffle();
}

CardDeck::~CardDeck() { 
  delete [] deck;
}

int CardDeck::getSize() {
  return (size);
}

void CardDeck::shuffle() {
  srand(time(NULL));
  for (int i = 0; i != (size-1); i++) {
    int j = rand() % (size - 1);
    int temp;
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  } 

}

int CardDeck::Deal() {
  int c, card, value;
  c = 52 - size;
  card = deck[c];
  size--;
  card = card % 13;
  if (card == 0) {  	// 0 represents an Ace.
    value = 11;
    cout << "An ace was dealt." << endl;
  }
  if (card == 10) {   	// If card is a Jack, Queen or King
    value = 10;
    cout << "A jack was dealt." << endl;
  }
  if (card == 11) { 
    value = 10;
    cout << "A queen was dealt." << endl;
  } 
  if (card == 12) { 
    value = 10;
    cout << "A king was dealt." << endl;
  }
  if ( (card != 0) && (card != 10) && (card != 11) && (card != 12) ) {
    value = card + 1;  
    cout << "A " << value << " was dealt." << endl;
  }

  return (value);
}

