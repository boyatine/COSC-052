#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include "hand.h"
#include "card.h"

using namespace std;

/**
 * Deck class for storing information about a deck, which has a vector of card objects. The class implements
 * methods for manipulating and using the vector of card objects.
 *
 * @author Mark Maloof, Boya Lee (doc comments)
 * @version 1.0, 2/9/18
 */

class Deck {

  friend ostream &operator<<(ostream &out, const Deck &deck);

  public:
    Deck();
    bool empty() const;
    void shuffle();
    Hand dealHand(unsigned nCards) throw (invalid_argument);
    Card dealCard() throw (invalid_argument);

  private:
    vector<Card> cards;

}; // Deck class

#endif
