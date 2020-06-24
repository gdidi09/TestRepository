#include <iostream>
#include <conio.h>
#include"MyClock.h"
#include"Work.h"

int main()
{
	showCursor(FALSE);
	Work clock;
	clock.run();
	return 0;
}