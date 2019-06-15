#include "pch.h"
#include "FactoryPattern.h"
#include <iostream>


class Bus : public Car
{
public:
	Bus()
	{

	}

	void AboutCar()
	{
		std::cout << "This is a bus\n";
	}
};

class PrivateCar : public Car
{
public:
	PrivateCar()
	{

	}

	void AboutCar()
	{
		std::cout << "This is private car\n";
	}
};

std::unique_ptr<Car> Car::BuildCar(CarType eCarType)
{
	if (eCarType == CarType::PRIVATE_CAR)
		return std::move(std::unique_ptr<Car>(new PrivateCar()));
	else if (eCarType == CarType::BUS)
		return std::move(std::unique_ptr<Car>(new Bus()));
}
