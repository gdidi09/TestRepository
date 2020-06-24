#include "MyClock.h"

MyClock::MyClock()
{
	_amPm = false;
	_GMT = 27;
	tmp = time(0) % (24 * 3600);
	_hours = tmp / 3600 + _GMT;
	if (_hours >= 24)
		_hours = _hours % 24;
	tmp = tmp % 3600;
	_min = tmp / 60;
	tmp = tmp % 60;
	_sec = tmp;
}

MyClock& MyClock::operator++()
{
	_GMT++;
	return *this;
}

MyClock& MyClock::operator--()
{
	_GMT--;
	return *this;
}


void MyClock::chekSec()
{
	tmp = time(0) % (24 * 3600);
	tmp = tmp % 3600;
	tmp = tmp % 60;
	_sec = tmp;
}

void MyClock::chekMin()
{
	tmp = time(0) % (24 * 3600);
	tmp = tmp % 3600;
	_min = tmp / 60;
}

void MyClock::chekHour()
{
	tmp = time(0) % (24 * 3600);
	_hours = tmp / 3600 + _GMT;
	if (_hours >= 24)
		_hours = _hours % 24;
	if (_amPm)
	{
		if (_hours <= 12)
		{
			setCursorPosition(14, 1);
			std::cout << std::setfill(' ') << std::setw(2) << "AM";

		}
		if (_hours > 12)
		{
			_hours = _hours - 12;
			setCursorPosition(14, 1);
			std::cout << std::setfill(' ') << std::setw(2) << "PM";
		}
		else if (_hours < 0)
			_hours = 11;
	}
}

void MyClock::chekGMT()
{
	if (_GMT >= 37) _GMT = 13;
	if (_GMT < 13) _GMT = 36;
	setCursorPosition(0, 0);
	std::cout.setf(std::ios::showpos | std::ios::left);
	std::cout << "Timezone GMT" << std::setfill(' ') << std::setw(3) << _GMT - 24;
	std::cout.unsetf(std::ios::showpos | std::ios::left);
}


void MyClock::menu()const
{
	setCursorPosition(0,4);
	std::cout << "Press \"->\" for  GMT+\n";
	std::cout << "Press \"<-\" for  GMT-\n";
	std::cout << "Press \"spase\" for change format of time\n";
	std::cout << "Press \"ESC\" for Exit\n";
}


void MyClock::setAmPm(const bool flag)
{
	_amPm = flag;
}


bool MyClock::getAmPm()const
{
	return _amPm;
}


std::ostream& operator<<(std::ostream& out, const MyClock& obj)
{
	setCursorPosition(5, 1);
	out << std::setfill('0') << std::setw(2) << obj._hours << ":" << std::setfill('0') << std::setw(2) << obj._min << ":" << std::setfill('0') << std::setw(2) << obj._sec << "\n";
	return out;
}


void setCursorPosition(short x, short y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}


void showCursor(bool flag)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hOut, &structCursorInfo);
	structCursorInfo.bVisible = flag;
	SetConsoleCursorInfo(hOut, &structCursorInfo);
}