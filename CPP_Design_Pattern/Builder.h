#pragma once
#include <iostream>
class House
{
public:

	virtual void buildWindows() = 0;
	virtual void buildHardwoodFloor() = 0;
	virtual void buildEnsuite() = 0;
	virtual void buildHousePool() = 0;
};

class HouseBuilder
{
protected:
	std::unique_ptr<House> pHouse;

public:
	virtual void constructWindows() = 0;
	virtual void constructHardwoodFloor() = 0;
	virtual void constructEnsuite() = 0;
	virtual void constructHousePool() = 0;

	virtual std::unique_ptr<House> getHouse() = 0;
};

class SayemHouse : public HouseBuilder
{
public:
	void constructWindows();
	void constructHardwoodFloor();
	void constructEnsuite();
	void constructHousePool();

	std::unique_ptr<House> getHouse();

	
};

class JuthekaHouse : public HouseBuilder
{
public:
	void constructWindows();
	void constructHardwoodFloor();
	void constructEnsuite();
	void constructHousePool();

	std::unique_ptr<House> getHouse();
};

class Director
{
private:
	std::unique_ptr<HouseBuilder> m_pHouseBuilder;
public:
	Director(std::unique_ptr<HouseBuilder> pHouseBuilder);

	std::unique_ptr<House> Construct();

};



