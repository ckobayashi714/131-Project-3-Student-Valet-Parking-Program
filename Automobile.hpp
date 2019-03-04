#pragma once
#include <iostream>
#include <string>


class Automobile {
  friend bool operator==( const Automobile& lhs, const Automobile& rhs );
  friend std::ostream & operator<<( std::ostream& stream, const Automobile& vehicle );

  private:
    std::string color_;
    std::string brand_;
    std::string model_;
    std::string plateNumber_;

  public:
    Automobile( const std::string & color,
                const std::string & brand,
                const std::string & model,
                const std::string & plateNumber );
};

bool operator!=( const Automobile& lhs, const Automobile& rhs );
