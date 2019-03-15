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
// This function overloads the equality operator. It checks for equality on every attribute.
bool operator==( const Automobile& lhs, const Automobile& rhs ) {
return (lhs.color_ == rhs.color_ && lhs.brand_ == rhs.brand_ && lhs.model_ == rhs.model_ && lhs.plateNumber_ == rhs.plateNumber_ );
}

bool operator!=( const Automobile& lhs, const Automobile& rhs ) { return !( lhs == rhs ); }

// This function overloads the << operator. It prints all the car's atributes.
std::ostream &operator<<( std::ostream& stream, const Automobile& vehicle ) {
  stream << vehicle.color_ << " " << vehicle.brand_ << " " <<  vehicle.model_ << " " << vehicle.plateNumber_ << std::endl;
  return stream;
}
