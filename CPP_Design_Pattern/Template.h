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





