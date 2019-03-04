#include <queue>
#include <stdexcept>
#include <string>

#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"


/*******************************************************************************
** ParkingLot Member function definitions
*******************************************************************************/
ClaimCheck ParkingLot::dropOff( const Automobile& vehicle ) {
  /// To be completed:
  ///   Create a claim check called ticket passing in the vehicle
  . . .
  ///

  /// To be completed:
  ///   Add the vehicle and the ticket's claim number to the collection of parked cars.
  ///   Hint:  Create a ParkedCar and set its vehicle and claim number attributes, then push it on to the stack.
  . . .
  ///

  return ticket;
}




Automobile ParkingLot::pickUp( const ClaimCheck& ticket ) {
  /// To be completed:
  ///   Move cars from the front of the queue to the back of the queue until you
  ///   find the one you're looking for or until you looked at them all.
  ///   Hint:  The vehicle you're looking for has a ticket claim number that matches the parked car's claim number.
  . . .
  ///

  /// To be completed:
  ///   If you reach this point, the vehicle you're looking for wasn't in the parking lot.
  ///   Optional:  Throw an invalid argument exception (highly recommended but not required).  Otherwise
  ///              print out an error message and return the ticket's vehicle.
  . . .
  ///
}




size_t ParkingLot::quantity()
{
  /// To be completed:
  ///   Return the number of parked cars that are currently in the parking lot
  . . .
  ///
}

