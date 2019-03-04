#include "calendar.h"

Calendar::Calendar() {

}

Event& Calendar::find( string query ) throw ( logic_error ) {
	unsigned found = 0;
	for ( int i = 0; i < events.size(); ++i ) {
		if ( events[i] == query ) {
			found++;
			return events[i];
		}
	}

	if ( found == 0 ) {
		throw logic_error( "query not found in calendar" );
	}
}

void Calendar::print( ostream& out ) const {
	for ( int i = 0; i < events.size(); ++i ) {
		if ( events[i].getStatus() == 'A' )
			events[i].println( out );
			cout << endl;
	}
}

void Calendar::read( string filename ) throw ( logic_error, invalid_argument ) {
	ifstream inFile;

		inFile.open( filename );

		if ( inFile.good() ) {
				read(inFile);
		} else {
			throw logic_error( "file has not opened successfully" );
		}
}

void Calendar::read( istream& in ) throw ( invalid_argument ) {
	Event event;

	in >> event;
	while ( in ) {
		events.push_back(event);
		in >> event;
	}
}

unsigned Calendar::size() const {
	return events.size();
}

void Calendar::synchronize( Calendar& calendar ) {
	synchronize( this->events, calendar.events );
}

void Calendar::synchronize( vector<Event>& e1, vector<Event>& e2 ) {
	for ( int i = 0; i < e2.size(); i++ ) {
		if ( e1.at(i) != e2.at(i) ) {
			e1.at(i) = e2.at(i);
		} else if ( e1.at(i) > e2.at(i) ) {
			e2.at(i) = e1.at(i);
		} else if ( e1.at(i) < e2.at(i)) {
			e1.at(i) = e2.at(i);
		}
	}

	
}


void Calendar::write( string filename ) const {
	ofstream outfile;

	outfile.open( filename );

	write( outfile );

	outfile.close();
}

void Calendar::write( ostream& out ) const {
	for ( int i = 0; i < events.size(); ++i ) {
		out << events[i];
	}
}