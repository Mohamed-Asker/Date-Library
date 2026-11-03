#pragma warning (disable : 4996);
#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "../../String Library/String Library/clsString.h"



//Properties set:
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

//Read Only Properties:
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

//Constructors
clsDate::clsDate()
{
	SystemDate();
}
clsDate::clsDate(std::string sDate)
{
	std::vector <std::string> vTokens = clsString::split(sDate, "/");
	Day = std::stoi(vTokens[0]);
	Month = std::stoi(vTokens[1]);
	Year = std::stoi(vTokens[2]);
}
clsDate::clsDate(short Day, short Month, short Year)
{
	this->Day = Day;
	this->Month = Month;
	this->Year = Year;
}

//Operations:
//Operation (1):
void clsDate::PrintDate()
{
	std::cout << Day << "/" << Month << "/" << Year << "\n";
}

//Operation (2):
bool clsDate::isLeapYear(short year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0);
}
bool clsDate::isLeapYear()
{
	return isLeapYear(Year);
}

//Operation (3):
short clsDate::NumberOfDaysInAYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
}
short clsDate::NumberOfDaysInAYear()
{
	return NumberOfDaysInAYear(Year);
}

//Operation (4):
int clsDate::NumberOfHoursInAYear(short year)
{
	return NumberOfDaysInAYear(year) * 24;
}
int clsDate::NumberOfHoursInAYear()
{
	return NumberOfHoursInAYear(Year);
}

//Operation (5):
int clsDate::NumberOfMinutesInAYear(short year)
{
	return NumberOfHoursInAYear(year) * 60;
}
int clsDate::NumberOfMinutesInAYear()
{
	return NumberOfMinutesInAYear(Year);
}

//Operation (6):
int clsDate::NumberOfSecondsInAYear(short year)
{
	return NumberOfMinutesInAYear(year) * 60;
}
int clsDate::NumberOfSecondsInAYear()
{
	return NumberOfSecondsInAYear(Year);
}

//Operation ():
void clsDate::SystemDate()
{
	std::time_t Time = std::time(0);
	std::tm* Now = std::localtime(&Time);

	Year = Now->tm_year + 1900;
	Month = Now->tm_mon + 1;
	Day = Now->tm_mday;
}



