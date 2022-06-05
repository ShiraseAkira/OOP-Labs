#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../DriveCar/Car.h"

SCENARIO("Car engine can be turned on and off")
{
	GIVEN("A car with turned off engine")
	{
		Car myCar;
		REQUIRE(!myCar.IsTurnedOn());
		WHEN("engine is turned on") 
		{
			myCar.TurnOnEngine();
			THEN("it becomes turned on")
			{
				CHECK(myCar.IsTurnedOn());
			}

			AND_WHEN("it's turned off")
			{
				myCar.TurnOffEngine();
				THEN("it becomes turned off")
				{
					CHECK(!myCar.IsTurnedOn());
				}
			}
		}
	}
}

SCENARIO("Car engine can not be turned off when gear is not neutral or speed is not zero")
{
	GIVEN("A car with non neutral gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		THEN("engine can not be turned off")
		{
			CHECK(!myCar.TurnOffEngine());
		}
	}
	GIVEN("A car with non zero speed")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		myCar.SetSpeed(10);
		myCar.SetGear(0);
		THEN("engine can not be turned off")
		{
			CHECK(!myCar.TurnOffEngine());
		}
	}
}