#ifndef BIKES_H
#define BIKES_H

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cmath>
#include "bike.h"
#include "urban.h"
#include "delivery.h"
#include "factory.h"

using namespace std;

/**
 * The Bikes class.
 * vector class, stores information about bikes.  The vector stores
 * pointers to these objects, and provides methods for destructing,
 * reading, printing, and totaling the volume of such objects.
 *
 * @author Mark Maloof
 * @version 1.0, 1/24/13
 */

class Bikes
{

  public:
    Bikes();
    int getTotalGears() const;
    int getTotalCapacity() const;
    void print( ostream &out = cout ) const;
    void read( string filename ) throw ( logic_error, invalid_argument );
    unsigned size() const;
    ~Bikes();

  private:
    vector<Bike *> bikes;

}; // Bikes class

#endif // BIKES_H

