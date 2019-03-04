#include "bike.h"

Bike::Bike() {
    setID( "D00" );
    setName( "" );
    setGears( 1 );
}

Bike::Bike( string id, string name, int gears ) throw ( invalid_argument ) {
    setID( id );
    setName( name );
    setGears( gears );
}

Bike::~Bike() {

}

int Bike::getGears() const {
    return gears;
}

string Bike::getID() const {
    return id;
}

string Bike::getName() const {
    return name;
}

void Bike::print( ostream& out ) const {
    out << id << ' ' << '"' << name << '"' << ' ' << gears;
}

void Bike::read( istream& in ) throw ( invalid_argument ) {
    string temp_id, temp_name;
    int temp_gears;

    in >> temp_id;
    if ( in.good() ) {
        temp_name = readDoubleQuotedString( in );
        in >> temp_gears;
        setID( temp_id );
        setName( temp_name );
        setGears( temp_gears );
    }
}

void Bike::setGears ( int gears ) throw ( invalid_argument ) {
    if ( gears < 1 || gears > 24 ) {
        throw invalid_argument( "the inputted value of gears is out of bounds" );
    }
    this->gears = gears;
}

void Bike::setID ( string id ) throw ( invalid_argument ) {
    if ( id.length() != 3 || id.at(0) < 65 || id.at(0) > 90 || id.at(1) < 48 || id.at(1) > 58
        || id.at(2) < 48 || id.at(2) > 58 ) {
        throw invalid_argument( "the inputted format of the ID is incorrect" );            
    } 
    this->id = id;
}

void Bike::setName ( string name ) {
    this->name = name;
}

string Bike::readDoubleQuotedString( istream& in ) const {
    string dummy;
    string str;
    
    getline( getline( in, dummy, '"' ), str, '"' );

    return str;
}