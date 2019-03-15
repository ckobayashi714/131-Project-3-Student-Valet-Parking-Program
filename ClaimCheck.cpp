#include <iostream>

#include "Automobile.hpp"
#include "ClaimCheck.hpp"



/*******************************************************************************
** Class attributes
*******************************************************************************/
size_t ClaimCheck::nextAvailableClaimNumber = 100;

/*******************************************************************************
** Member function definitions
*******************************************************************************/
ClaimCheck::ClaimCheck( const Automobile & vehicle )
  : vehicle_(vehicle),
    // This will initialize claimNumber to the next available claim number,
    // making sure that nextAvailableClaimNumber is post-incremented.
    claimNumber_(nextAvailableClaimNumber++)
{}

Automobile ClaimCheck::vehicle() const
{ return vehicle_; }

size_t ClaimCheck::claimNumber() const
{ return claimNumber_;  }

/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
// Compare if two claim checks are equal.
bool operator==( const ClaimCheck & lhs, const ClaimCheck & rhs ) {
  return (lhs.claimNumber_ == rhs.claimNumber_);
}

bool operator!=( const ClaimCheck & lhs, const ClaimCheck & rhs )
{ return ! (lhs == rhs); }

std::ostream & operator<<( std::ostream & stream, const ClaimCheck & ticket ) {
  // Insert the ticket's vehicle and claim number into the stream then return the stream
  stream << ticket.vehicle_ << "/n" << ticket.claimNumber_ << std::endl;
  return stream;
}
