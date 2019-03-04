#include "main.h"

int main()
{
  try {
    srand(time(0));
    Deck deck;
    Hand hand = deck.dealHand( 55 );
    cout << "Hand: " << hand << endl;
    cout << "Value: " << hand.value() << endl;
  } // try
  catch ( invalid_argument &e ) {
    cout << "Caught invalid_argument: " << e.what() << endl;
  } // catch
  catch ( ... ) {
    cout << "Caught unknown exception!" << endl;
  } // catch
  return 0;
} // main

