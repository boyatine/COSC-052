#include "card.h"

/**
 * Default constructor. Sets suit to the default of spade and rank to the default of ace.
 */

Card::Card()
{
  setSuit( 'S' );
  setRank( "A" );
} // Card::Card

/**
 * Explicit class constructor initializing a Card object using the arguments suit and rank. 
 * Throws an exception if passed invalid values.
 *
 * @param	suit	a char storing the suit of this card
 * @param	rank	a string storing the rank of this card
 * @throw	invalid_argument	if an argument is invalid
 */

Card::Card(char suit, string rank) throw ( invalid_argument )
{
  setSuit( suit );
  setRank( rank );
} // Card::Card

/**
 * Explicit class constructor initializing a Card object using int arguments suit and rank.
 * Throws an exception if passed invalid values.
 *
 * @param	suit	an int storing the suit of this card
 * @param	rank	an int storing the rank of this card
 * @throw	invalid_argument	if an argument is invalid
 */

Card::Card(int suit, int rank) throw ( invalid_argument )
{
  setSuit( intToSuit(suit) );
  setRank( intToRank(rank) );
} // Card::Card

/**
 * Returns this card's suit.
 *
 * @return	a char storing this card's suit
 */

char Card::getSuit() const
{
  return suit;
} // Card::getSuit

/**
 * Returns this card's rank.
 *
 * @return	a string storing this card's rank
 */

string Card::getRank() const
{
  return rank;
} // Card::getRank

/**
 * Returns this card's blackjack value.
 *
 * @param	soft	a bool value indicating a soft hand or hard hand
 * @return	an int storing this card's blackjack value
 */

int Card::getBlackjackValue(bool soft) const
{
  if (rank == "A")
    return soft ? 11 : 1;
  if (rank == "10" || rank == "K" || rank == "Q" || rank == "J")
    return 10;
  else
    return int(rank.at(0)) - 48;
} // Card::getBlackjackValue

/**
 * Converts an int suit to a char suit.
 *
 * @param	suit	an int storing the suit of this card
 * @return	a char storing the suit of this card
 */

char Card::intToSuit(int suit) const
{
  char cardSuit = '\0';
  switch (suit) {
    case 0:
      cardSuit = 'C';
      break;
    case 1:
      cardSuit = 'D';
      break;
    case 2:
      cardSuit = 'H';
      break;
    case 3:
      cardSuit = 'S';
      break;
  } // switch
  return cardSuit;
} // Card::intToSuit

/**
 * Converts an int rank to a string rank.
 *
 * @param	rank	an int storing the rank of this card
 * @return	a string storing the rank of this card
 */

string Card::intToRank(int rank) const
{
  if (rank == 0)
    return "A";
  if (rank >= 1 && rank <= 8) {
    string iHateCPlusPlus;  // No constructor for chars in string!!??
    iHateCPlusPlus += char(rank + 49);
    return iHateCPlusPlus;
  } // if
  if (rank == 9)
    return "10";
  if (rank == 10)
    return "J";
  if (rank == 11)
    return "Q";
  if (rank == 12)
    return "K";
  return "";
} // Card::intToRank

/**
 * Sets this card's suit. The suit must be in {C, D, H, S}.
 * Throws an exception if passed invalid values.
 *
 * @param	suit	an char storing the suit of this card
 * @throw	invalid_argument	if an argument is invalid
 */

void Card::setSuit(char suit) throw ( invalid_argument )
{
  if (suit != 'C' && suit != 'D' && suit != 'H' && suit != 'S') {
    stringstream ss;
    ss << "Card::setSuit: Invalid suit: " << suit;
    throw invalid_argument( ss.str() );
  } // if
  this->suit = suit;
} // Card::setSuit

/**
 * Sets this card's rank. The rank must be in {2, 3, 4, 5, 6, 7, 8, 9, J, Q, K, A}.
 * Throws an exception if passed invalid values.
 *
 * @param	rank	a string storing the rank of this card
 * @throw	invalid_argument	if an argument is invalid
 */

void Card::setRank(string rank) throw ( invalid_argument )
{
  bool error = false;
  if (rank.size() == 1) {
    string ranks = "23456789JQKA";
    if (rank.find( ranks ) != string::npos) {
      error = true;
    } // if
  } // if
  else if (rank != "10") {
    error = true;
  } // else
  if ( error ) {
    stringstream ss;
    ss << "Card::setRank: Invalid rank: " << rank;
    throw invalid_argument( ss.str() );
  } // if
  this->rank = rank;
} // Card::setRank

/**
 * Inserts a Card object in the format "[rank, suit]" into the output stream, and returns the
 * modified output stream.
 *
 * @param	out	the output stream for insertion
 * @param	card	the Card object for insertion
 * @return	the modified output stream
 */

ostream &operator<<(ostream &out, const Card &card)
{
  out << "[" << card.rank << "," << card.suit << "]";
  return out;
} // operator<<
