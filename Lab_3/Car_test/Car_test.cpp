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

SCENARIO("Car can change speed within gear speed limit")
{
	GIVEN("A car with non neutral gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		THEN("speed can be changed within gear limits")
		{
			CHECK(myCar.SetSpeed(10));
			CHECK(myCar.GetSpeed() == 10);
			CHECK(myCar.SetSpeed(0));
			CHECK(myCar.GetSpeed() == 0);
			CHECK(myCar.SetSpeed(20));
			CHECK(myCar.GetSpeed() == 20);
			AND_WHEN("speed is not in gear limits")
			{
				THEN("speed is not changed")
				{
					CHECK(!myCar.SetSpeed(100));
					CHECK(myCar.GetSpeed() != 100);
					CHECK(myCar.GetSpeed() == 20);
				}
			}
		}
	}
}

SCENARIO("Car on neutral gear can only reduce it's speed")
{
	GIVEN("A car with non zero speed on neutral gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		myCar.SetSpeed(10);
		myCar.SetGear(0);
		WHEN("you try to increase speed")
		{
			THEN("it doesn't change")
			{
				CHECK(!myCar.SetSpeed(20));
				CHECK(myCar.GetSpeed() == 10);
			}
			AND_WHEN("you try to decrease it")
			{
				THEN("it does")
				{
					CHECK(myCar.SetSpeed(5));
					CHECK(myCar.GetSpeed() == 5);
					AND_WHEN("absolute value is increased")
					{
						THEN("speed does not change")
						{
							CHECK(!myCar.SetSpeed(-10));
							CHECK(myCar.GetSpeed() == 5);
						}
					}
				}
			}
		}
	}
}

SCENARIO("Car can change gear if speed requirement are met")
{
	GIVEN("A car with speed")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		myCar.SetSpeed(30);
		WHEN("you change gear")
		{
			THEN("it changes if requirements are met")
			{
				CHECK(myCar.SetGear(2));
				CHECK(myCar.GetGear() == 2);
				CHECK(myCar.SetGear(0));
				CHECK(myCar.GetGear() == 0);
				CHECK(myCar.SetGear(3));
				CHECK(myCar.GetGear() == 3);
				AND_WHEN("speed requirements are not met")
				{
					THEN("it does not change")
					{
						CHECK(myCar.GetSpeed() == 30);
						CHECK(!myCar.SetGear(4));
						CHECK(myCar.GetGear() == 3);
					}
				}
			}
		}
	}
}

SCENARIO("Car with engine turned off can only change on neutral gear")
{
	GIVEN("A car with engine turned off")
	{
		Car myCar;
		WHEN("you change gear on neutral")
		{
			THEN("it works")
			{
				CHECK(myCar.SetGear(0));
			}
		}
		WHEN("you change gear on 1 or reverse")
		{
			THEN("it does not work")
			{
				CHECK(!myCar.SetGear(1));
				CHECK(!myCar.SetGear(-1));
			}
		}
	}
}

SCENARIO("Car can change gear on reverse only if speed is zero")
{
	GIVEN("A car with speed")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(1);
		myCar.SetSpeed(10);
		WHEN("you try to change gear on reverse")
		{
			THEN("it does not change")
			{
				CHECK(!myCar.SetGear(-1));
				CHECK(myCar.GetGear() == 1);
				myCar.SetGear(0);
				CHECK(!myCar.SetGear(-1));
				CHECK(myCar.GetGear() == 0);
			}
		}
	}
	GIVEN("A car with speed that moves back on neutral gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(-1);
		myCar.SetSpeed(10);
		myCar.SetGear(0);
		WHEN("you try to change gear on reverse")
		{
			THEN("it does not change")
			{
				CHECK(!myCar.SetGear(-1));
				CHECK(myCar.GetGear() == 0);
			}
		}
	}
}

SCENARIO("Car can change reverse gear on gear 1 only if speed is 0")
{
	GIVEN("A car with speed that moves back on reverse gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(-1);
		myCar.SetSpeed(10);
		WHEN("you try to change on gear 1")
		{
			THEN("it does not")
			{
				CHECK(!myCar.SetGear(1));
				CHECK(myCar.GetGear() == -1);
				AND_WHEN("speed is zero")
				{
					myCar.SetSpeed(0);
					THEN("it does")
					{
						CHECK(myCar.SetGear(1));
						CHECK(myCar.GetGear() == 1);
					}
				}
			}
		}
	}
}

SCENARIO("Car that moves back on neutral gear can only change on gear 1 after stop")
{
	GIVEN("A car with speed that moves back on neutral gear")
	{
		Car myCar;
		myCar.TurnOnEngine();
		myCar.SetGear(-1);
		myCar.SetSpeed(10);
		myCar.SetGear(0);
		WHEN("you try to change gear on 1")
		{
			THEN("it does not change")
			{
				CHECK(!myCar.SetGear(1));
				CHECK(myCar.GetGear() == 0);
			}
		}
	}
}