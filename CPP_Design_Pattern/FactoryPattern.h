#pragma once
#include <iostream>


class Car
{
public:
	static std::unique_ptr<Car> BuildCar(CarType eCarType);

	virtual void AboutCar() = 0;
};

