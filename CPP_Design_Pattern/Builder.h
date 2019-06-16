#pragma once
#include <iostream>
class House
{
public:

	int no_of_windows;
	bool bHardWoodFloor;
	bool bEnsuite;
	bool bHousePool;
};

class HouseBuilder
{
protected:
	std::unique_ptr<House> pHouse;

public:
	HouseBuilder();
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



