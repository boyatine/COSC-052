#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

/**
 * Hand class for storing information about a hand of cards, which has a vector of card objects.
 * The class implements methods for manipulating and using the vector of card objects.
 *
 * @author Mark Maloof, Boya Lee (doc comments)
 * @version 1.0, 2/9/18
 */

class Hand {

  friend ostream &operator<<(ostream &out, const Hand &hand);

  public:
    Hand();
    void add(const Card &card);
    int value() const;

  private:
    vector<Card> cards;

}; // Hand class

#endif
