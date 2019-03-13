#include <iostream>
#include <string>

#include "Automobile.hpp"



/*******************************************************************************
** Member function definitions
*******************************************************************************/
Automobile::Automobile( const std::string & color,
                        const std::string & brand,
                        const std::string & model,
                        const std::string & plateNumber )
  : color_(color), brand_(brand), model_(model), plateNumber_(plateNumber)
{}






/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
bool operator==( const Automobile& lhs, const Automobile& rhs ) {
  /// To be completed:
  ///   Return true if each attribute of the left hand side (lhs) is
  ///   equal to the right hand side (rhs)
return (lhs.color_ == rhs.color_ && lhs.brand_ == rhs.brand_ && lhs.model_ == rhs.model_ && lhs.plateNumber_ == rhs.plateNumber_ );
}



bool operator!=( const Automobile& lhs, const Automobile& rhs )
{ return !( lhs == rhs ); }



std::ostream &operator<<( std::ostream& stream, const Automobile& vehicle )
{
  /// To be completed:
  ///   Insert the vehicle's color, brand, model, and license plate number into the stream, then return the stream
  stream << vehicle.color_ << " " << vehicle.brand_ << " " <<  vehicle.model_ << " " << vehicle.plateNumber_ << std::endl;
  return stream;
}
