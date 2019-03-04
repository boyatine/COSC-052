#include "datetime.h"

DateTime::DateTime() {
	setDate( 1, 1, 0 );
	setTime( 12, 0, "AM");
}

DateTime::DateTime( int mm, int dd, int yy, int h, int m, string period ) 
	throw ( invalid_argument ) {
	setDate( mm, dd, yy );
	setTime( h, m, period );
}

void DateTime::setDate( int mm, int dd, int yy ) throw ( invalid_argument ) {
	if ( yy < 0 || yy > 99 ) {
		throw invalid_argument( "year is out of range" );		
	}

	if ( mm < 1 || mm > 12 ) {
		throw invalid_argument( "month is out of range" );
	}

	switch ( mm ) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if ( dd < 1 || dd > 31 ) {
				throw invalid_argument( "day is out of range" );
			}
			break;
		case 4: case 6: case 9: case 11:
			if (dd < 1 || dd > 30) {
				throw invalid_argument( "day is out of range" );
			}
			break;
		case 2:
			if (dd < 1 || dd > 28) {
				throw invalid_argument( "day is out of range" );
			}
			break;
	} // switch

	this->mm = mm;
	this->dd = dd;
	this->yy = yy;
}

void DateTime::setTime( int h, int m, string period ) throw ( invalid_argument ) {
	if ( h < 1 || h > 12 ) {
		throw invalid_argument( "hour is out of range" );
	}

	if ( m < 0 || m > 59 ) {
		throw invalid_argument( "minute is out of range" );
	}

	if ( period != "AM" && period != "PM" ) {
		throw invalid_argument( "incorrect value for period " );
	}

	this->h = h;
	this->m = m;
	this->period = period;
}

bool DateTime::operator!=( const DateTime& dt ) const {
	return !( yy == dt.yy && mm == dt.mm && dd == dt.dd && h == dt.h && m == dt.m 
		&& period == dt.period );
}

bool DateTime::operator<( const DateTime& dt ) const {
	return ( yy < dt.yy || mm < dt.mm || dd < dt.dd || ( period == "AM" && dt.period == "PM" )
		|| h < dt.h || m < dt.m );
}

bool DateTime::operator>( const DateTime& dt ) const {
	return ( yy > dt.yy || mm > dt.mm || dd > dt.dd || ( period == "PM" && dt.period == "AM" )
		|| h > dt.h || m > dt.m );
}

bool DateTime::operator==( const DateTime& dt ) const {
	return ( yy == dt.yy && mm == dt.mm && dd == dt.dd && h == dt.h && m == dt.m
		&& period == dt.period );
}

void DateTime::print( ostream& out ) const {
	out << setw(2) << setfill('0') << mm << '/' << setw(2) << setfill('0') << dd << '/' 
		<< setw(2) << setfill('0') << yy << ' ' << setw(2) << setfill('0') << h << ':' 
		<< setw(2) << setfill('0') << m << ' ' << period << ' ';
}

unsigned long DateTime::toLong() const {
}

ostream& operator<<( ostream& out, const DateTime& dt ) {
	out << dt.mm << '/' << dt.dd << '/' << dt.yy << ' ' << dt.h << ':' << dt.m << ' ' << dt.period;
	return out;
}

istream& operator>>( istream& in, DateTime& dt ) throw ( invalid_argument ) {
	char ch1, ch2, ch3;
	int mm, dd, yy, h, m;
	string period;
	in >> mm;
	if ( in.good() ) {
		in >> ch1 >> dd >> ch2 >> yy >> h >> ch3 >> m >> period;
		if ( ch1 != '/' || ch2 != '/' || ch3 != ':') {
			in.setstate( ios::failbit );
		} else {
		dt.setDate( mm, dd, yy );
		dt.setTime( h, m, period );
	}
}

	return in;
}