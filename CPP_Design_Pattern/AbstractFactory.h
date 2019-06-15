#pragma once
#include "pch.h"
#include <iostream>
class AbstractCar
{
public:
	virtual void AboutCar() = 0;
};

class AbstractCarFactory
{
public:
	virtual std::unique_ptr<AbstractCar> GetCar(CarType eCarType) = 0;
};

class AbstractFactoryProducer
{
public:
	static std::unique_ptr<AbstractCarFactory> getFactory(Location eLocation);
};

