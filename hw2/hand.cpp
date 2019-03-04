#include "hand.h"

/**
 * Default constructor. Creates an empty vector of Card objects.
 */

Hand::Hand() { }

/**
 * Adds Card objects to the vector of Card objects.
 *
 * @param card	a Card object to be added
 */

void Hand::add(const Card &card)
{
  cards.push_back(card);
} // Hand::add

/**
 * Returns the total value of the cards in a hand.
 *
 * @return	an int storing the total value of a hand
 */

int Hand::value() const
{
  int value = 0;
  for (unsigned i = 0; i < cards.size(); i++) {
    value += cards[i].getBlackjackValue();
  } // for
  return value;
} // Hand::value

/**
 * Inserts a Hand object in the format "[rank, suit], [rank, suit], ... , [rank, suit]"
 * into the output stream, and returns the modified output stream.
 *
 * @param	out	the output stream for insertion
 * @param	hand	the Hand object for insertion
 * @return	the modified output stream
 */

ostream &operator<<(ostream &out, const Hand &hand)
{
  bool printedOne = false;
  for (unsigned i = 0; i < hand.cards.size(); i++) {
    if (printedOne) out << ',';
    out << hand.cards[i];
    printedOne = true;
  } // for
  return out;
} // operator<<
