#pragma once
#include <queue>

#include "ClaimCheck.hpp"
#include "Automobile.hpp"



struct ParkedCar {
  Automobile  vehicle_;
  size_t      claimNumber_;
};



class ParkingLot {
  private:
    std::queue<ParkedCar> parkedCars_; // aisles closed on one end

  public:
    ClaimCheck dropOff( const Automobile& vehicle );
    Automobile pickUp ( const ClaimCheck& ticket  );

    size_t quantity();
  };
