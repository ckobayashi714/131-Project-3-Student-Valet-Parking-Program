#pragma once
#include <iostream>

#include "Automobile.hpp"



class ClaimCheck {
  friend bool operator==( const ClaimCheck & lhs, const ClaimCheck & rhs );
  friend std::ostream & operator<<( std::ostream & stream, const ClaimCheck & ticket );

  private:
    const  Automobile   vehicle_;
    const  size_t       claimNumber_;
    static size_t       nextAvailableClaimNumber;

  public:
    ClaimCheck( const Automobile & vehicle );

    Automobile   vehicle    () const;
    size_t       claimNumber() const;
};

bool operator!=( const ClaimCheck & lhs, const ClaimCheck & rhs );
