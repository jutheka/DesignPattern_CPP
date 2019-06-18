#include "pch.h"
#include "Composite.h"

Employee::Employee(std::string eName, int ID)
{
	empName = eName;
	empId = ID;
}

void Employee::GetDetails()
{
	printf(" Employee name is : %s, ID is : %d", empName.c_str(), empId);
}

Manager::Manager(std::string sManagerName)
{
	managerName = sManagerName;
}

void Manager::GetDetails()
{
	std::vector<std::unique_ptr<IEmployee>>::iterator it;
	for ( it= subOrdinate.begin(); it != subOrdinate.end(); ++it)
	{
		it->get()->GetDetails();
	}

}

void Manager::AddSubordinate(std::unique_ptr<IEmployee> e)
{
	subOrdinate.push_back(std::move(e));
}

void Manager::RemoveSubordinate(int empId)
{
	std::vector<std::unique_ptr<IEmployee>>::iterator it;
	for ( it = subOrdinate.begin(); it != subOrdinate.end(); ++it)
	{
		Employee* e1 = (Employee *)it->get();
	

		if (e1->empId == empId)
			break;
	}
	if (it != subOrdinate.end())
		subOrdinate.erase(it);
}


