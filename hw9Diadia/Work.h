#pragma once
#include"MyClock.h"

class Work
{
private:
	bool work = true;
	MyClock mc;
	int key;
public:
	void run();
	
};

