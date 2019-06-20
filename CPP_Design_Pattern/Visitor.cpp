#include "pch.h"
#include "Visitor.h"

int Burger::getPrice()
{
	return 5;
}

int Burger::accept(std::shared_ptr<Visitor> visitor)
{
	std::shared_ptr<Burger> b = std::make_shared<Burger>();
	return visitor->visit(b);
}

int Pizza::getPrice()
{
	return 10;
}

int Pizza::accept(std::shared_ptr<Visitor> visitor)
{
	std::shared_ptr<Pizza> p = std::make_shared<Pizza>();
	return visitor->visit(p);
}

int ConcreteVisitor::visit(std::shared_ptr<Burger> item)
{
	return item->getPrice();
}

int ConcreteVisitor::visit(std::shared_ptr<Pizza> item)
{
	return item->getPrice();
}