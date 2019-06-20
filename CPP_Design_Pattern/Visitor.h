#pragma once
#include <iostream>

class Item;
class Burger;
class Pizza;
class Visitor
{
public:
	virtual int visit(std::shared_ptr<Burger> item) = 0;
	virtual int visit(std::shared_ptr<Pizza> item) = 0;
};

class Item
{
public:
	virtual int accept(std::shared_ptr<Visitor> visitor) = 0;
};

class Burger : public Item
{
public:
	int getPrice();
	int accept(std::shared_ptr<Visitor> visitor);
};

class Pizza : public Item
{
public:
	int getPrice();
	int accept(std::shared_ptr<Visitor> visitor);
};


class ConcreteVisitor : public Visitor
{
public:
	int visit(std::shared_ptr<Burger> item);
	int visit(std::shared_ptr<Pizza> item);
};