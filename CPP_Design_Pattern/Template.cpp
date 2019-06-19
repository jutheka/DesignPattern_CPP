#include "pch.h"
#include "Template.h"




void Game::play()
{
	StartPlay();
	EndPlay();
}


void Cricket::StartPlay()
{
	printf("Cricket has started\n");
}

void Cricket::EndPlay()
{
	printf("Cricket has ended\n");
}



void FootBall::StartPlay()
{
	printf("Football has started\n");
}

void FootBall::EndPlay()
{
	printf("Football has ended\n");
}


