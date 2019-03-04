#include "bikes.h"

Bikes::Bikes() {

}

Bikes::~Bikes() {

}

int Bikes::getTotalCapacity() const {
	int totalCapacity = 0;
	Bikes *capacityPtr = NULL;

	for ( unsigned i = 0; i < bikes.size(); i++ ) {

		capacityPtr = dynamic_cast<Bikes*>(bikes.at(i));
			if ( capacityPtr ) {
				totalCapacity += capacityPtr->getTotalCapacity();
			}
	}

	return totalCapacity;
}

int Bikes::getTotalGears() const {
	int totalGears = 0;

	for ( unsigned i = 0; i < bikes.size(); i++ ) {
		totalGears += bikes.at(i)->getGears();
	}

	return totalGears;
}

void Bikes::print( ostream& out ) const {
	for ( unsigned i = 0; i < bikes.size(); i++ ) {
		bikes[i]->print( out );
		cout << endl;
	}
}

void Bikes::read( string filename ) throw ( logic_error, invalid_argument ) {
	ifstream fin;
	fin.open( filename.c_str() );

	if ( !fin ) {
		throw logic_error( "Unable to open the file" );
	}

	Bike *temp = NULL;
	temp = BikeFactory::make( fin );

	while ( fin ) {
		bikes.push_back(temp);
		temp = BikeFactory::make( fin );
	}

	fin.close();
}