#include <queue>
#include <stdexcept>
#include <string>

#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"


/*******************************************************************************
** ParkingLot Member function definitions
*******************************************************************************/
ClaimCheck ParkingLot::dropOff( const Automobile& vehicle ) {
  ///   Create a claim check called ticket passing in the vehicle
  ClaimCheck ticket(vehicle);
  ///   Add the vehicle and the ticket's claim number to the collection of parked cars.
  ///   Hint:  Create a ParkedCar and set its vehicle and claim number attributes, then push it on to the stack.
  ParkedCar car{vehicle, ticket.claimNumber()};
  parkedCars_.push(car);
  return ticket;
}
/* This function will cycle through the queue and check if the car's claim number
matches the ticket's claim number. If so, the car will be returned. If not, the
front car will be pushed into the back of the queue and the next car will be
checked. If the car isn't found, an exception will be thrown. */
Automobile ParkingLot::pickUp( const ClaimCheck& ticket ) {
  size_t count = 0;
  while (count <= quantity()) {
    ParkedCar temp = parkedCars_.front();
    parkedCars_.pop();
    if(temp.claimNumber_ == ticket.claimNumber())
      return temp.vehicle_;
    parkedCars_.push(temp);
    count++;
  }
  // At this point, the vehicle you're looking for wasn't in the parking lot.
  throw std::invalid_argument("No Matching Car Was Found");
}
// This function returns the number of parked cars that are currently in the parking lot.
size_t ParkingLot::quantity() {
  return parkedCars_.size();
}
