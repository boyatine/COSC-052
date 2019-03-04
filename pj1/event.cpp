#include "event.h"

Event::Event() {
	setStatus( 'A' );
}

string Event::getLocation() const {
	return location;
}

string Event::getName() const {
	return name;
}

char Event::getStatus() const {
	return status;
}

bool Event::operator!=( const Event& e ) const {
	return ( id != e.id );
}

bool Event::operator<( const Event& e ) const {
	return ( modified < e.modified );
}

bool Event::operator==( const Event& e ) const {
	return ( id == e.id );
}

bool Event::operator==(	const string& query	) const {
	bool foo;
	if ( name.find(query) != string::npos || location.find(query) != string::npos ) {
  		foo = true;
	} else {
		foo = false;
	}

	return foo;
}

bool Event::operator>( const Event& e ) const {
	return ( modified > e.modified );
}

void Event::println( ostream& out ) const {
	out << "NAME: " << name << ' ' << "LOCATION: " << location << ' ' << "START: " << start << ' ' 
		<< "END: " << end;
}

string Event::readDoubleQuotedString( istream& in ) const {
	string dummy;
	string str;
	
	getline( getline( in, dummy, '"' ), str, '"' );

	return str;
}

void Event::setStatus( char status ) throw ( invalid_argument ) {
	if ( status != 'A' && status != 'D' ) {
		throw invalid_argument( "invalid value for status" );
	}

	this->status = status;
}

ostream& operator<<( ostream& out, const Event& e ) {
	out << e.status << ' ' << e.id << ' ' << '"' << e.name << '"' << ' ' << '"' << e.location
		<< '"' << ' ' << e.start << ' ' << e.end << ' ' << e.modified << ' ' << endl;
	return out;
}

istream& operator>>( istream& in, Event& e ) throw ( invalid_argument ) {
	char status;
    string id, name, location;
    DateTime start, end, modified;

	in >> status;
	if ( status != 'A' && status != 'D' ) {
		throw invalid_argument( "invalid value for status" );
	}
	in >> id;
	e.name = e.readDoubleQuotedString( in );
	e.location = e.readDoubleQuotedString( in );
	in >> start; 
	in >> end;
	in >> modified;

	e.status = status;
	e.id = id;
	e.start = start;
	e.end = end;
	e.modified = modified;

	return in;
}