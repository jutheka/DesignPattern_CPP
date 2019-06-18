// CPP_Design_Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "FactoryPattern.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Composite.h"

//Composite Pattern
int main()
{
	std::unique_ptr<IEmployee> e1(new Employee("Deba", 1));
	std::unique_ptr<IEmployee> e2(new Employee("Juth", 2));
	std::unique_ptr<IEmployee> e3(new Employee("Adrita", 3));

	std::unique_ptr<Manager> m1(new Manager("Boss"));

	m1->AddSubordinate(std::move(e1));
	m1->AddSubordinate(std::move(e2));

	m1->GetDetails();

	e3->GetDetails();

	m1->RemoveSubordinate(2);

	printf("\n\n\n");
	m1->GetDetails();
	return 0;
}



//End Composite Pattern

// Start: Builder pattern
//int main()
//{
//	std::unique_ptr<HouseBuilder> pHouseBuilder(new SayemHouse());
//	std::unique_ptr<Director> pDirector(new Director(std::move(pHouseBuilder)));
//
//	std::unique_ptr<House> pHouse = std::move(pDirector->Construct());
//	if (pHouse)
//		std::cout << "windows is : " << pHouse->no_of_windows << std::endl << " Ensuite:" << (pHouse->bEnsuite ? "Yes" : "No") << std::endl
//		<<"HardWood: "<< (pHouse->bHardWoodFloor ? "yes" : "no")<<std::endl<<"House Pool: "<< (pHouse->bHousePool ? "yes" : "No");
//	return 0;
//}

// End: Builder pattern


// Start::  Abstract Factory Pattern example
//int main()
//{
//	std::unique_ptr<Car> aCar = Car::BuildCar(CarType::BUS);
//
//	aCar->AboutCar();
//
//	std::unique_ptr<AbstractCarFactory> aUSACarFactory = AbstractFactoryProducer::getFactory(Location::USA);
//	std::unique_ptr<AbstractCar> anotherCar =  aUSACarFactory->GetCar(CarType::PRIVATE_CAR);
//	anotherCar->AboutCar();
//}
//End:: Abstract Factory Pattern example


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
