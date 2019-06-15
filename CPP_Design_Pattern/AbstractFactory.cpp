
#include "pch.h"
#include "AbstractFactory.h"
#include <iostream>

class PrivateCar : public AbstractCar
{
public:
	PrivateCar()
	{

	}

	void AboutCar()
	{
		std::cout << "This is a private car\n";
	}
};

class Bus : public AbstractCar
{
public:
	Bus()
	{

	}

	void AboutCar()
	{
		std::cout << "This is a bus car\n";
	}
};

class IndiaCarFactory:public AbstractCarFactory
{
public:
	std::unique_ptr<AbstractCar> GetCar(CarType eCarType)
	{
		if (eCarType == CarType::PRIVATE_CAR)
			return std::move(std::unique_ptr<AbstractCar>(new PrivateCar()));
		else if (eCarType == CarType::BUS)
			return std::move(std::unique_ptr<AbstractCar>(new Bus()));

	}
};

class USACsrFactory: public AbstractCarFactory
{
public:
	std::unique_ptr<AbstractCar> GetCar(CarType eCarType)
	{
		if (eCarType == CarType::PRIVATE_CAR)
			return std::move(std::unique_ptr<AbstractCar>(new PrivateCar()));
		else if (eCarType == CarType::BUS)
			return std::move(std::unique_ptr<AbstractCar>(new Bus()));
	}
};


std::unique_ptr<AbstractCarFactory> AbstractFactoryProducer::getFactory(Location eLocation)
{
	if (eLocation == Location::INDIA)
		return std::move(std::unique_ptr<AbstractCarFactory>(new IndiaCarFactory()));
	else if (eLocation == Location::USA)
		return std::move(std::unique_ptr<AbstractCarFactory>(new USACsrFactory()));
}
