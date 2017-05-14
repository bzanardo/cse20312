// Maria Beatriz Zanardo
// Lab 2
// Interface for Card Deck class

#ifndef CARDDECK_H
#define CARDDECK_H

class CardDeck {
  public:
    CardDeck(int = 52);
    ~CardDeck();
    int getSize();
    int Deal();
  private:
    int size;
    int * deck; 
    void shuffle();
};

#endif
