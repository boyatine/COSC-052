#include "factory.h"

Bike* BikeFactory::make( istream& in ) throw ( invalid_argument ) {
	Bike* b = NULL;

	//if ( in ) {
	char first_letter /* = in.get()*/;
	in >> first_letter;
	if (in)
		in.putback( first_letter );
		cout << first_letter; // why are the if / else if statements skipped when the first_letter corresponds to 'U'...
		if (first_letter == 'U' ) {
			b = new Urban();
		} else if (first_letter == 'D' ) { 
			b = new Delivery();
		} else {
			throw invalid_argument( "Bikes must be either delivery or urban." );
		}

		b->read( in );
	}

	return b;
}