#include "delivery.h"

Delivery::Delivery() : Bike() {
	setCapacity( 1 );
}

Delivery::Delivery( string id, string name, int gears, int capacity ) throw ( invalid_argument )
	: Bike( id, name, gears ) {
	setID( id );
    setCapacity( capacity );
}	

int Delivery::getCapacity() const {
	return capacity;
}

void Delivery::print( ostream& out ) const {
	Bike::print( out );
	out << ' ' << capacity;
}

void Delivery::read( istream& in ) throw ( invalid_argument ) {
	Bike::read( in );

	int capacity;

	in >> capacity;
	setCapacity( capacity );

}

void Delivery::setCapacity( int capacity ) throw ( invalid_argument ) {
	if ( capacity < 1 || capacity > 120 ) {
		cout << capacity;
		throw invalid_argument( "the value of capacity is out of bounds");
	}
	this->capacity = capacity;
}

void Delivery::setID( string id ) throw ( invalid_argument ) {
	Bike::setID( id );
	if ( this->id.at(0) != 'D' ) {
		throw invalid_argument( "the ID of the bike must being with a 'D'" );
	}
}