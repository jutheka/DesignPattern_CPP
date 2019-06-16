#include "pch.h"
#include "Builder.h"

void SayemHouse::constructWindows()
{
	std::cout << "This house has windows" << std::endl;
	pHouse->no_of_windows = 5;
}

void SayemHouse::constructHardwoodFloor()
{
	std::cout << "This house has a Hard Wood Floor" << std::endl;
	pHouse->bHardWoodFloor = true;
}

void SayemHouse::constructEnsuite()
{
	std::cout << "This house no ensuite" <<std::endl;
	pHouse->bEnsuite = false;
}

void SayemHouse::constructHousePool()
{
	std::cout << "this house has no pool" << std::endl;
	pHouse->bHousePool = false;
}

std::unique_ptr<House> SayemHouse::getHouse()
{
	if (pHouse)
		return std::move(pHouse);
	else
		return std::unique_ptr<House>();
}

void JuthekaHouse::constructWindows()
{
	std::cout << "this house has  windows" << std::endl;
	pHouse->no_of_windows = 10;
}

void JuthekaHouse::constructHardwoodFloor()
{
	std::cout << "this house has no hardwood pool" << std::endl;
	pHouse->bHardWoodFloor = false;
}

void JuthekaHouse::constructEnsuite()
{
	std::cout << "this house has ensuite" << std::endl;
	pHouse->bEnsuite = true;
}

void JuthekaHouse::constructHousePool()
{
	std::cout << "this house has no pool" << std::endl;
	pHouse->bHousePool = false;
}

std::unique_ptr<House> JuthekaHouse::getHouse()
{
	if (!pHouse)
		return std::unique_ptr<House>();
	else
		return std::move(pHouse);
}

Director::Director(std::unique_ptr<HouseBuilder> pHouseBuilder)
{
	m_pHouseBuilder = std::move(pHouseBuilder);
}

std::unique_ptr<House> Director::Construct()
{
	m_pHouseBuilder->constructEnsuite();
	m_pHouseBuilder->constructHardwoodFloor();
	m_pHouseBuilder->constructHousePool();
	m_pHouseBuilder->constructWindows();
	
	return m_pHouseBuilder->getHouse();
}

HouseBuilder::HouseBuilder()
{
	pHouse.reset(new House());
}
