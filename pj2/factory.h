#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <stdexcept>
#include "bike.h"
#include "urban.h"
#include "delivery.h"
#include "bikes.h"

using namespace std;

/**
 * The BikeFactory class, produces Bikes from an input stream.  Bikes
 * can be either Delivery or Urban bikes.
 *
 * @author Mark Maloof
 * @version 1.0, 1/24/13
 */

class BikeFactory
{
  friend class Bikes;

  private:
    static Bike* make( istream& in ) throw ( invalid_argument );

}; // BikeFactory class

#endif // FACTORY_H

