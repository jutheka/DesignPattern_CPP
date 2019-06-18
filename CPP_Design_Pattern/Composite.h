#pragma once
#include <iostream>
#include <vector>
class IEmployee
{
	public:

		virtual void GetDetails() = 0;
};

class Employee : public IEmployee
{
public:
	std::string empName;
	int empId;

	Employee(std::string eName, int ID);

	void GetDetails();
};

class Manager : public IEmployee
{
public:
	std::string managerName;
	int ManagerID;

	Manager(std::string sManagerName);

	std::vector<std::unique_ptr<IEmployee>> subOrdinate;
	void GetDetails();
	void AddSubordinate(std::unique_ptr<IEmployee> e);
	void RemoveSubordinate(int empId);
};