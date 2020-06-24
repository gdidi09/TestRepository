#include "Work.h"

void Work::run()
{
	mc.menu();

	while (work)
	{
		mc.chekGMT();
		mc.chekSec();
		mc.chekMin();
		mc.chekHour();
		std::cout << mc;
		if (_kbhit())
		{
			key = (int)_getch();
			switch (key)
			{
			case (27):		// ESC
				setCursorPosition(0, 8);
				work = false;
				break;
			case (75):
				--mc;	 // <-
				break;
			case (77):

				++mc;	 // ->
				break;
			case (32):
				system("cls");
				mc.menu();
				mc.setAmPm(!mc.getAmPm()); // spase
				break;
			}
		}
	}
}
