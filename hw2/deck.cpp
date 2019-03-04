#include "deck.h"

/**
 * Default constructor. Adds card objects as elements to a vector of card objects, then shuffles
 * the elements.
 */

Deck::Deck()
{
  for (int suit = 0; suit < Card::suits; suit++) {
    for (int value = 0; value < Card::values; value++) {
      Card newCard(suit, value);
      cards.push_back( newCard );
    } // for
  } // for
  shuffle();
} // Deck::Deck

/**
 * Checks whether the vector of cards is empty or not.
 *
 * @return	a bool value indicating whether the vector of cards is empty or not.
 */

bool Deck::empty() const
{
  return cards.empty();
} // Deck::empty()

/**
 * Shuffles the vector of cards.
 */

void Deck::shuffle()
{
  random_shuffle(cards.begin(), cards.end());
} // Deck::shuffle()

/**
 * Deals a specified number of cards from the deck to a hand.
 * Throws an exception if the number of cards specified 
 * is greater than the size of the deck or if the deck is empty.
 *
 * @param	nCards	an unsigned storing the number of cards to be dealt
 * @return	a Hand object consisting of the dealt cards
 * @throw	invalid_argument	if an argument is invalid
 */

Hand Deck::dealHand(unsigned nCards) throw (invalid_argument)
{
  Hand hand;
  if (empty() || cards.size() < nCards) {
    throw invalid_argument( "Deck::dealHand: Not enough cards in deck." );
  } // if
  for (unsigned i = 0; i < nCards; i++) {
    hand.add( dealCard() );
  } // for
  return hand;
} // Deck::dealHand

/**
 * Deals a card from the deck, and removes that that card from the vector of cards.
 * Throws an exeption if the deck is empty.
 *
 * @return	a Card object that was dealt from the deck
 * @throw	invalid_argument	if an argument is invalid
 */

Card Deck::dealCard() throw (invalid_argument)
{
  if ( empty() ) {
    throw invalid_argument( "Deck::dealCard: Deck is empty." );
  } // if
  int card = rand() % cards.size();
  Card dealtCard = cards[card];
  swap( cards[card], cards.back() );
  cards.pop_back();
  return dealtCard;
} // Deck::dealCard

/**
 * Inserts a Deck object in the format "[rank, suit], [rank, suit], ... , [rank, suit]"
 * into the output stream, and returns the modified output stream.
 *
 * @param	out	the output stream for insertion
 * @param	deck	the Deck object for insertion
 * @return	the modified output stream
 */

ostream &operator<<(ostream &out, const Deck &deck)
{
  bool printedOne = false;
  for (unsigned i = 0; i < deck.cards.size(); i++) {
    if (printedOne) out << ',';
    out << deck.cards[i];
    printedOne = true;
  } // for
  return out;
} // operator<<
