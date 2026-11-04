#pragma warning (disable : 4996);
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
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

//Operation (7):
short clsDate::NumberOfDaysInAMonth(short year, short month)
{
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}
short clsDate::NumberOfDaysInAMonth()
{
	return NumberOfDaysInAMonth(Year, Month);
}

//Operation (8):
int clsDate::NumberOfHoursInAMonth(short year, short month)
{
	return NumberOfDaysInAMonth(year, month) * 24;
}
int clsDate::NumberOfHoursInAMonth()
{
	return NumberOfHoursInAMonth(Year, Month);
}

//Operation (9):
int clsDate::NumberOfMinutesInAMonth(short year, short month)
{
	return NumberOfHoursInAMonth(year, month) * 60;
}
int clsDate::NumberOfMinutesInAMonth()
{
	return NumberOfMinutesInAMonth(Year, Month);
}

//Operation (10):
int clsDate::NumberOfSecondsInAMonth(short year, short month)
{
	return NumberOfMinutesInAMonth(year, month) * 60;
}
int clsDate::NumberOfSecondsInAMonth()
{
	return NumberOfSecondsInAMonth(Year, Month);
}

//Operation (11):
short clsDate::DayOfWeekInOrder(short day, short month, short year)
{
	short A = (14 - month) / 12;
	short Y = year - A;
	short M = month + (12 * A) - 2;
	return (day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
}
short clsDate::DayOfWeekInOrder()
{
	return DayOfWeekInOrder(Day, Month, Year);
}

//Operation (12):
std::string clsDate::DayName(short day)
{
	std::string Days[] = { "Sun","Mon","Tue","Wed","Thr","Fri","Sat" };
	return Days[day];
}
std::string clsDate::DayName(short day, short month, short year)
{
	return DayName(DayOfWeekInOrder(day, month, year));
}
std::string clsDate::DayName()
{
	return DayName(DayOfWeekInOrder(Day, Month, Year));
}

//Operation (13):
std::string clsDate::MonthName(short month)
{
	std::string Months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return Months[month - 1];
}
std::string clsDate::MonthName()
{
	return MonthName(Month);
}

//Operation (14):
void clsDate::PrintHeaderOfMonthCalender(short year , short month)
{
	std::cout << "==============[" << MonthName(month) << " " << year << "]===============\n";
	for (short i = 0; i < 7; i++)
		std::cout << std::left << std::setw(6) << DayName(i);

	std::cout << std::endl;
}
void clsDate::MonthCalender(short year, short month)
{
	short DaysInAMonth = NumberOfDaysInAMonth(year, month);
	short DayIndex = DayOfWeekInOrder(1, month, year);
	PrintHeaderOfMonthCalender(year, month);

	for (short i = 0; i < DayIndex; i++)
		std::cout << std::left << std::setw(6) << "";

	for (short i = 1; i <= DaysInAMonth; i++)
	{
		std::cout << std::left << std::setw(6) << i;
		if (++DayIndex == 7)
		{
			std::cout << "\n";
			DayIndex = 0;
		}
	}
	std::cout << "\n=======================================\n";
}
void clsDate::MonthCalender()
{
	MonthCalender(Year, Month);
}


//Operation (15):
void clsDate::YearCalender(short year)
{
	for (short month = 1; month <= 12; month++)
	{
		MonthCalender(year, month);
		std::cout << std::endl;
	}
}
void clsDate::YearCalender()
{
	YearCalender(Year);
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