#pragma once
#include <iostream>




class Game
{
public: 

	virtual void StartPlay() = 0;
	virtual void EndPlay() = 0;

	void play();
};

class Cricket : public Game
{
public:

	void StartPlay();
	void EndPlay();
};

class FootBall : public Game
{
public:

	void StartPlay();
	void EndPlay();
};



class Base
{
	int x;
public:
	virtual void fun() = 0;
	int getX();
};

// This class inherits from Base and implements fun() 
class Derived : public Base
{
	int y;
public:
	void fun() { std::cout << "fun() called"; }
};

