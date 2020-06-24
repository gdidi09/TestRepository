#pragma once
#include <iostream>
#include<iomanip>
#include <conio.h>
#include <ctime>
#include <windows.h>

void setCursorPosition(short x, short y);
void showCursor(bool flag);

class MyClock
{
private:
	time_t _hours;
	time_t _min;
	time_t _sec;
	time_t tmp;
	int _GMT;
	bool _amPm;
public:
	explicit MyClock();
	MyClock& operator++();
	MyClock& operator--();
	void chekSec();
	void chekMin();
	void chekHour();
	void chekGMT();
	void menu()const;
	void setAmPm(const bool flag);
	bool getAmPm() const;
	friend std::ostream& operator<<(std::ostream& out, const MyClock& obj);
};

