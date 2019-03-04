#include "urban.h"

Urban::Urban() : Bike() {
	setID ( "U00" );
}

Urban::Urban( string id, string name, int gears ) throw ( invalid_argument )
	: Bike( id, name, gears ) {
	setID( id );
}

void Urban::print( ostream& out ) const {
	Bike::print( out );
}

void Urban::read( istream& in ) throw ( invalid_argument ) {
	Bike::read( in );
}

void Urban::setID( string id ) throw ( invalid_argument ) {
	Bike::setID( id );
	if ( this->id.at(0) != 'U' ) {
		throw invalid_argument( "the ID of this bike must being with a 'U'" );
	}
}