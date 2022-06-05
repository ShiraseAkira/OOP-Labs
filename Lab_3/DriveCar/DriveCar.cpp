#include <iostream>
#include "Car.h"

int main()
{
	Car myCar;
	myCar.TurnOnEngine();
	myCar.SetGear(-1);
	myCar.SetSpeed(10);
	myCar.SetGear(0);
	myCar.GetGear();
	myCar.SetGear(-1);
	myCar.GetGear() == 0;
    std::cout << "Hello World!\n";
}
