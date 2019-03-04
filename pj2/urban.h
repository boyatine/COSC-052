#ifndef URBAN_H
#define URBAN_H

#include <iostream>
#include <fstream>
#include <string>
#include "bike.h"

using namespace std;

/**
 * Urban class for storing information about urban bike.
 *
 * @author Mark Maloof
 * @version 1.0, 1/14/13
 */

class Urban : public Bike
{
  public:
    Urban();
    Urban( string id, string name, int gears ) throw ( invalid_argument );
    void setID( string id ) throw ( invalid_argument );
    virtual void print( ostream &out = cout ) const;
    virtual void read( istream &in ) throw ( invalid_argument );

}; // Urban class

#endif // URBAN_H

