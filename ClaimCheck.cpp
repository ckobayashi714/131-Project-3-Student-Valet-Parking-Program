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
    /// To be completed:
    ///   Initialize claimNumber_ to the next available claim number while
    ///   post-incrementing the next available claim number
    claimNumber_(nextAvailableClaimNumber++)
    ///
{}



Automobile ClaimCheck::vehicle() const
{ return vehicle_; }



size_t ClaimCheck::claimNumber() const
{ return claimNumber_;  }



/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
bool operator==( const ClaimCheck & lhs, const ClaimCheck & rhs )
{
  /// To be completed:
  ///   Two claim checks are equal if they have equal claim check numbers.
return (lhs.claimNumber_ == rhs.claimNumber_);
  ///
}



bool operator!=( const ClaimCheck & lhs, const ClaimCheck & rhs )
{ return ! (lhs == rhs); }



std::ostream & operator<<( std::ostream & stream, const ClaimCheck & ticket )
{
  /// To be completed:
  ///   insert the ticket's vehicle and claim number into the stream then return the stream
  stream << ticket.vehicle_ << " " << ticket.claimNumber_ << std::endl;
  return stream;
  ///
}
