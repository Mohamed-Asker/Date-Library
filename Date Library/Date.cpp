#include <iostream>
#include "Date.h"



//Properties set.
void clsDate::setDay(short Day)
{
	_Day = Day;
}
void clsDate::setMonth(short Month)
{
	_Month = Month;
}
void clsDate::setYear(short Year)
{
	_Year = Year;
}

//Read Only Properties.
short clsDate::getDay()
{
	return _Day;
}
short clsDate::getMonth()
{
	return _Month;
}
short clsDate::getYear()
{
	return _Year;
}