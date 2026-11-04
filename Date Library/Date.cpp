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
clsDate::clsDate(short DayOrderInYear, short year)
{
	clsDate Date = DateFromDayOrderInYear(DayOrderInYear, year);
	this->Day = Date.Day;
	this->Month = Date.Month;
	this->Year = Date.Year;
}

//Helpers Functions
void clsDate::IncreaseDay()
{
	_Day++;
}
void clsDate::IncreaseMonth()
{
	_Month++;
}
void clsDate::IncreaseYear()
{
	_Year++;
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

//Operation (16):
short clsDate::DaysFromBeginningOfYear(short day, short month, short year)
{
	short TotalDays = 0;
	for (short i = 1; i < month; i++)
		TotalDays += NumberOfDaysInAMonth(year, i);
	TotalDays += day;
	return TotalDays;
}
short clsDate::DaysFromBeginningOfYear()
{
	return DaysFromBeginningOfYear(Day, Month, Year);
}

//Operation (17):
clsDate clsDate::DateFromDayOrderInYear(short DayOrder, short year)
{
	clsDate Date;
	short RemainningDay = DayOrder;
	short MonthDays;

	Date.Year = year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = Date.NumberOfDaysInAMonth();
		if (MonthDays < RemainningDay)
		{
			RemainningDay -= MonthDays;
			Date.IncreaseMonth();
		}
		else
		{
			Date.Day = RemainningDay;
			break;
		}
	}
	return Date;
}

//Operation (18):
clsDate clsDate::AddDaysToDate(clsDate Date, int Days)
{
	int RemainningDays = Date.DaysFromBeginningOfYear() + Days;
	short MonthDays;
	Date.Month = 1;

	while (true)
	{
		MonthDays = Date.NumberOfDaysInAMonth();
		if (MonthDays < RemainningDays)
		{
			RemainningDays -= MonthDays;
			Date.IncreaseMonth();
			if (Date.Month > 12)
			{
				Date.IncreaseYear();
				Date.Month = 1;
			}
		}
		else
		{
			Date.Day = RemainningDays;
			break;
		}
	}
	return Date;
}
void clsDate::AddDaysToDate(int Days)
{
	*this = AddDaysToDate(*this, Days);
}

//Operation (19):
bool clsDate::isDate1BeforeDate2(clsDate Date1, clsDate Date2)
{
	if (Date1.Year != Date2.Year)	return Date1.Year < Date2.Year;
	if (Date1.Month != Date2.Month)	return Date1.Month < Date2.Month;
	return Date1.Day < Date2.Day;

	//Another Soultion:
	//return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;
}
bool clsDate::isDateBeforeDate2(clsDate Date2)
{
	return isDate1BeforeDate2(*this, Date2);
}

//Operation (19):
bool clsDate::isDate1EqualDate2(clsDate Date1, clsDate Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}
bool clsDate::isDateEqualDate2(clsDate Date2)
{
	return isDate1EqualDate2(*this, Date2);
}

//Operation (20):
bool clsDate::isLastDayInAMonth(clsDate& Date)
{
	return Date.Day == Date.NumberOfDaysInAMonth();
}
bool clsDate::isLastDayInAMonth()
{
	return isLastDayInAMonth(*this);
}

//Operation (21):
bool clsDate::isLastMonthInAYear(short month)
{
	return month == 12;
}
bool clsDate::isLastMonthInAYear()
{
	return isLastMonthInAYear(this->Month);
}

//Operation (22):
clsDate clsDate::AddOneDayToDate(clsDate Date)
{
	if (Date.isLastDayInAMonth())
	{
		if (Date.isLastMonthInAYear())
		{
			Date.IncreaseYear();
			Date.Month = 1;
			Date.Day = 1;
		}
		else
		{
			Date.IncreaseMonth();
			Date.Day = 1;
		}
	}
	else
	{
		Date.IncreaseDay();
	}
	return Date;
}
void clsDate::AddOneDayToDate()
{
	*this = AddOneDayToDate(*this);
}

//Operation (23):
void clsDate::SwapDates(clsDate& Date1, clsDate& Date2)
{
	clsDate tempDate;

	tempDate.Day = Date1.Day;
	tempDate.Month = Date1.Month;
	tempDate.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = tempDate.Day;
	Date2.Month = tempDate.Month;
	Date2.Year = tempDate.Year;
}
void clsDate::SwapDates(clsDate& Date2)
{
	SwapDates(*this, Date2);
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



 