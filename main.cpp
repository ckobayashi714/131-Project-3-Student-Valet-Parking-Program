#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>  // typeid
#include <vector>

#include "Automobile.hpp"
#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"






// Helper Class Definitions
struct AssertEquals {
  template <typename T, typename U>
  void operator() ( const std::string & test_name, const T & expected, const U & actual, bool equality_test = true ) {

    if( (actual == expected)  ==  equality_test )
    {
      std::cout << "[PASSED] " << test_name << '\n';
    }
    else
    {
      std::cout << "[FAILED] " << test_name << " - Expected: \"" << expected << "\" to "
                << ( equality_test ? "match " : "not match ")
                << "Actual: \"" << actual << "\"\n";
    }
  }
};






// Helper Function Declarations
void testAutomobile();
void testClaimCheck();
void testParkingLot();





int main( /* int argc, char* argv[] */ )
{
  std::cout << std::boolalpha;  // Display boolean values as true and false

  testAutomobile();
  testClaimCheck();
  testParkingLot();
}










// Helper Function Definitions
void testAutomobile()
{
  AssertEquals assertEquals;
  std::cout << "\n\n******  Automobile tests  ******\n";

  Automobile myCar = {"Pearl White", "Nissan", "Altima", "3S CMPY"};
  assertEquals( "User Defined Construction and Equality", myCar, myCar );

  Automobile myMomsCar( myCar );
  assertEquals( "Copy Construction and Equality", myCar, myMomsCar );


  std::ostringstream stream1, stream2;
  stream1 << myCar;
  stream2 << myMomsCar;
  assertEquals( "Stream insertion 1", stream1.str(), stream2.str() );

  myMomsCar = {"Midnight Blue", "Chevy", "Astro", "TAXY SRV"};
  assertEquals( "Inequality operator", true, myCar != myMomsCar ); // assertEqual only calls operator==, so let's explicitly call operator!=

  stream2.seekp(0);
  stream2.clear();
  stream2 << myMomsCar;
  assertEquals( "Stream insertion 2", stream1.str(), stream2.str(), false );
}






void testClaimCheck()
{
  AssertEquals assertEquals;
  std::cout << "\n\n******  Claim Check tests  ******\n";

  std::vector<Automobile> cars = { {"White", "Honda",  "Civic",     "BE BEEP" },   // cars[0]
                                   {"Blue",  "Chevy",  "Silverado", "TRUK N"  },   // cars[1]
                                   {"Red",   "Toyota", "Supra",     "SPEEDY"  }    // cars[2]
                                 };

  std::vector<ClaimCheck> tickets = { cars[0],    // tickets[0]
                                      cars[1],    // tickets[1]
                                      cars[2],    // tickets[2]
                                      cars[0] };  // tickets[3]



  assertEquals( "User Defined Construction and Equality", cars[0], cars[0] );

  ClaimCheck anotherTicket( tickets[0] );
  assertEquals( "Copy Construction and Equality", tickets[0], anotherTicket );
  assertEquals( "Claim check inequality", false, tickets[3] != tickets[3]);  // assertEqual only calls operator==, so let's explicitly call operator!=


  assertEquals( "Claim check identifies correct automobile",             tickets[0].vehicle(), cars[0] );
  assertEquals( "Another unique claim check identifies same automobile", tickets[3].vehicle(), cars[0] );
  assertEquals( "All claim checks don't identify the same automobile",   tickets[2].vehicle(), cars[0], false );


  assertEquals( "Claim check with same vehicle parked at different times has different claim number", tickets[0].claimNumber(), tickets[3].claimNumber(), false);
  assertEquals( "Claim check numbers are increasing", true,     tickets[0].claimNumber()+1 == tickets[1].claimNumber()
                                                            &&  tickets[1].claimNumber()+1 == tickets[2].claimNumber()
                                                            &&  tickets[2].claimNumber()+1 == tickets[3].claimNumber() );


  std::ostringstream stream1, stream2;
  stream1 << tickets[0];
  stream2 << tickets[0];
  assertEquals( "Stream insertion 1", stream1.str(), stream2.str() );

  stream2.seekp(0);
  stream2.clear();
  stream2 <<tickets[3];
  assertEquals( "Stream insertion 2", stream1.str(), stream2.str(), false );
}






void testParkingLot()
{
  AssertEquals assertEquals;
  std::cout << "\n\n******  Parking Lot tests  ******\n";

  ParkingLot parkingLot;

  std::vector<Automobile> cars = {
                                    { "White",  "Honda",  "Civic",      "BEP BEP"   },   // cars[0]
                                    { "Blue",   "Chevy",  "Silverado",  "TRUK N"    },   // cars[1]
                                    { "Red",    "Toyota", "Supra",      "SPEEDY"    },   // cars[2]
                                    { "Black",  "Ford",   "Escape",     "GDY UP"    },   // cars[3]
                                    { "Orange", "Ford",   "Fiesta",     "PAR T CAR" }    // cars[4]
                                 };



  // Classes are starting - here they come!
  ClaimCheck ticket1 = parkingLot.dropOff( cars[0] );
  ClaimCheck ticket2 = parkingLot.dropOff( cars[1] );
  ClaimCheck ticket3 = parkingLot.dropOff( cars[2] );
  assertEquals( "Cars in lot-1", 3U, parkingLot.quantity() );


  // Some want their car back
  Automobile myCar = parkingLot.pickUp( ticket1 );
  assertEquals( "Pickup-1", myCar, ticket1.vehicle() );
  assertEquals( "Cars in lot-2", 2U, parkingLot.quantity() );



  // Here's a couple more for the afternoon classes
  ClaimCheck ticket4 = parkingLot.dropOff( cars[3] );
  ClaimCheck ticket5 = parkingLot.dropOff( cars[4] );
  assertEquals( "Cars in lot-3", 4U, parkingLot.quantity() );

  myCar = parkingLot.pickUp( ticket2 );
  assertEquals( "Pickup-2", myCar, ticket2.vehicle() );
  assertEquals( "Cars in lot-4", 3U, parkingLot.quantity() );

  // They're back ...
  ClaimCheck ticket6 = parkingLot.dropOff( ticket1.vehicle() );
  ClaimCheck ticket7 = parkingLot.dropOff( ticket2.vehicle() );
  assertEquals( "Dup Ticket Check-1", ticket6, ticket1, false );
  assertEquals( "Dup Ticket Check-2", ticket7, ticket2, false );
  assertEquals( "Cars in lot-5", 5U, parkingLot.quantity() );


  // Long day, but lets get our car and go home.
  myCar = parkingLot.pickUp( ticket4 );
  assertEquals( "Pickup-3", myCar, ticket4.vehicle() );

  try
  {
    // Wait, you're using an old ticket, throw that away and use your current ticket!
    myCar = parkingLot.pickUp( ticket1 );

    // pickup() failed to throw an exception when it should have
    std::cout << "[FAILED] An attempt was made to claim an automobile not in the parking lot, and that error was not detected.\n"
      << "         No points have been deducted, but defensive programming and error checking is encouraged\n";
  }
  catch( const std::invalid_argument & )
  {  // ignore the expected error
    assertEquals( "Error Detection-1", true, true );
  }
  catch( ... )
  {
    // pickup() failed to throw an invalid_argument exception
    std::cout << "[FAILED] An attempt was made to claim an automobile not in the parking lot, and that error was not properly communicated.\n"
      << "         An exception appears to have been thrown, but it wasn't the expected std::invalid_argument exception\n"
      << "         No points have been deducted, but defensive programming and error checking is encouraged\n";
  }

  myCar = parkingLot.pickUp( ticket6 ); // Okay, I'll use the current ticket, sorry ...
  assertEquals( "Pickup-4", myCar, ticket6.vehicle() );

  myCar = parkingLot.pickUp( ticket3 );
  assertEquals( "Pickup-5", myCar, ticket3.vehicle() );

  myCar = parkingLot.pickUp( ticket5 );
  assertEquals( "Pickup-6", myCar, ticket5.vehicle() );

  myCar = parkingLot.pickUp( ticket7 );
  assertEquals( "Pickup-7", myCar, ticket7.vehicle() );

  assertEquals( "Cars in lot-6", 0U, parkingLot.quantity() );
}
