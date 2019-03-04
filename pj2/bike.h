#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * Bike class for storing information about a bike, which has an identifier,
 * a name, and a number of gears.
 *
 * @author Mark Maloof
 * @version 1.0, 1/14/13
 */

class Bike
{
  public:
    Bike();
    Bike( string id, string name, int gears ) throw ( invalid_argument );
    void setID( string id ) throw ( invalid_argument );
    void setName( string name );
    void setGears( int gears ) throw ( invalid_argument );
    string getID() const;
    string getName() const;
    string readDoubleQuotedString( istream& in ) const;
    int getGears() const;
    virtual void print( ostream& out = cout ) const;
    virtual void read( istream& in ) throw ( invalid_argument );
    virtual ~Bike();
    

  protected:
    string id;
    string name;
    int gears;

}; // Bike class

#endif // BIKE_H

