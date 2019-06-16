#include "pch.h"
#include "Builder.h"

void SayemHouse::constructWindows()
{
	std::cout << "This house has windows" << std::endl;
}

void SayemHouse::constructHardwoodFloor()
{
	std::cout << "This house has a Hard Wood Floor" << std::endl;
}

void SayemHouse::constructEnsuite()
{
	std::cout << "This house no ensuite" <<std::endl;
}

void SayemHouse::constructHousePool()
{
	std::cout << "this house has no pool" << std::endl;
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
	std::cout << "this house has no windows" << std::endl;
}

void JuthekaHouse::constructHardwoodFloor()
{
	std::cout << "this house has no hardwood pool" << std::endl;
}

void JuthekaHouse::constructEnsuite()
{
	std::cout << "this house has ensuite" << std::endl;
}

void JuthekaHouse::constructHousePool()
{
	std::cout << "this house has no pool" << std::endl;
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
	
	return m_pHouseBuilder->getHouse();
}
