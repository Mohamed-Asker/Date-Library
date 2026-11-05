#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Date.h"
#include "../../String Library/String Library/clsString.h"



//Setters.
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

//Getters.
short clsDate::getDay() const
{
	return _Day;
}
short clsDate::getMonth() const 
{
	return _Month;
}
short clsDate::getYear() const 
{
	return _Year;
}

//Constructors
clsDate::clsDate()
{
	*this = SystemDate();
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
void clsDate::IncreaseDay(int Days)
{
	_Day += Days;
}
void clsDate::IncreaseMonth(int Months)
{
	_Month += Months;
}
void clsDate::IncreaseYear(int years)
{
	_Year += years;
}
void clsDate::DecreaseDay(int Days)
{
	_Day -= Days;
}
void clsDate::DecreaseMonth(int Months)
{
	_Month -= Months;
}
void clsDate::DecreaseYear(int Years)
{
	_Year -= Years;
}
void clsDate::CheckFebMonth()
{
	if ((this->Month == 2) && (this->Day >= 29))
	{
		short DaysInFeb = this->NumberOfDaysInAMonth();
		this->Day = (this->Day > DaysInFeb) ? DaysInFeb : Day;
	}
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
bool clsDate::isDate1BeforeDate2(const clsDate& Date1,const clsDate& Date2)
{
	if (Date1.Year != Date2.Year)	return Date1.Year < Date2.Year;
	if (Date1.Month != Date2.Month)	return Date1.Month < Date2.Month;
	return Date1.Day < Date2.Day;

	//Another Soultion:
	//return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;
}
bool clsDate::isDateBeforeDate2(const clsDate& Date2)
{
	return isDate1BeforeDate2(*this, Date2);
}

//Operation (20):
bool clsDate::isDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}
bool clsDate::isDateEqualDate2(const clsDate& Date2)
{
	return isDate1EqualDate2(*this, Date2);
}

//Operation (21):
bool clsDate::isLastDayInAMonth(clsDate& Date)
{
	return Date.Day == Date.NumberOfDaysInAMonth();
}
bool clsDate::isLastDayInAMonth()
{
	return isLastDayInAMonth(*this);
}

//Operation (22):
bool clsDate::isLastMonthInAYear(short month)
{
	return month == 12;
}
bool clsDate::isLastMonthInAYear()
{
	return isLastMonthInAYear(this->Month);
}

//Operation (23):
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

//Operation (24):
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

//Operation (25):
int clsDate::DiffInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay)
{
	short SwapFlagValue = 1;
	int Days = 0;
	if (!isDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (isDate1BeforeDate2(Date1, Date2))
	{
		Date1.AddOneDayToDate();
		Days++;
	}
	return (IncludeEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}
int clsDate::DiffInDays(clsDate Date2, bool IncludeEndDay)
{
	return DiffInDays(*this, Date2, IncludeEndDay);
}

//Operation (26):
clsDate clsDate::SystemDate()
{
	clsDate Date("0/0/0");
	std::time_t Time = std::time(0);
	std::tm* Now = std::localtime(&Time);

	Date.Year = Now->tm_year + 1900;
	Date.Month = Now->tm_mon + 1;
	Date.Day = Now->tm_mday;
	return Date;
}

//Operation (27):
int clsDate::YourAgeInDays(clsDate BirthDay)
{
	return DiffInDays(BirthDay, SystemDate(), false);
}
int clsDate::YourAgeInDays()
{
	return YourAgeInDays(*this);
}

//Operation (28):
clsDate clsDate::IncreaseDateByXDays(clsDate Date, int Days)
{
	for (int i = 1; i <= Days; i++)
		Date.AddOneDayToDate();
	return Date;
}
void clsDate::IncreaseDateByXDays(int Days)
{
	*this = IncreaseDateByXDays(*this, Days);
}
 
//Operation (29):
clsDate clsDate::IncreaseDateByOneWeek(clsDate Date)
{
	for (short i = 1; i <= 7; i++)
		Date.AddOneDayToDate();
	return Date;
}
void clsDate::IncreaseDateByOneWeek()
{
	*this = IncreaseDateByOneWeek(*this);
}

//Operation (30):
clsDate clsDate::IncreaseDateByXWeeks(clsDate Date, int Weeks)
{
	for (int i = 1; i <= Weeks; i++)
		Date.IncreaseDateByOneWeek();
	return Date;
}
void clsDate::IncreaseDateByXWeeks(int Weeks)
{
	*this = IncreaseDateByXWeeks(*this, Weeks);
}

//Operation (31):
clsDate clsDate::IncreaseDateByOneMonth(clsDate Date)
{
	if (Date.isLastMonthInAYear())
	{
		Date.IncreaseYear();
		Date.Month = 1;
	}
	else
		Date.IncreaseMonth();

	short DaysInNewMonth = Date.NumberOfDaysInAMonth();
	Date.Day = (Date.Day > DaysInNewMonth) ? DaysInNewMonth : Date.Day;
	return Date;
}
void clsDate::IncreaseDateByOneMonth()
{
	*this = IncreaseDateByOneMonth(*this);
}

//Operation (32):
clsDate clsDate::IncreaseDateByXMonths(clsDate Date, int Months)
{
	short DaysInTheCurrentMonth = Date.NumberOfDaysInAMonth();
	for (int i = 1; i <= Months; i++)
		Date.IncreaseDateByOneMonth();
	short DaysInTheNewMonth = Date.NumberOfDaysInAMonth();
	Date.Day = (DaysInTheCurrentMonth > DaysInTheNewMonth) ? DaysInTheNewMonth : DaysInTheCurrentMonth;
	return Date;
}
void clsDate::IncreaseDateByXMonths(int Months)
{
	*this = IncreaseDateByXMonths(*this, Months);
}

//Operation (33):
clsDate clsDate::IncreaseDateByOneYear(clsDate Date)
{
	Date.IncreaseYear();
	Date.CheckFebMonth();
	return Date;

}
void clsDate::IncreaseDateByOneYear()
{
	*this = IncreaseDateByOneYear(*this);
}

//Operation (34):
clsDate clsDate::IncreaseDateByXYears(clsDate Date,int Years)
{
	Date.IncreaseYear(Years);
	Date.CheckFebMonth();
	return Date;
}
void clsDate::IncreaseDateByXYears(int Years)
{
	IncreaseDateByXYears(*this, Years);
}

//Operation (35):
clsDate clsDate::IncreaseDateByOneDecade(clsDate Date)
{
	Date.IncreaseYear(10);
	Date.CheckFebMonth();
	return Date;
}
void clsDate::IncreaseDateByOneDecade()
{
	*this = IncreaseDateByOneDecade(*this);
}

//Operation (36):
clsDate clsDate::IncreaseDateByXDecade(clsDate Date, int Decade)
{
	Date.IncreaseYear(Decade * 10);
	Date.CheckFebMonth();
	return Date;
}
void clsDate::IncreaseDateByXDecade(int Decade)
{
	*this = IncreaseDateByXDecade(*this, Decade);
}

//Operation (37):
clsDate clsDate::IncreaseDateByOneCentury(clsDate Date)
{
	Date.IncreaseYear(100);
	Date.CheckFebMonth();
	return Date;
}
void clsDate::IncreaseDateByOneCentury()
{
	*this = IncreaseDateByOneCentury(*this);
}

//Operation (38):
clsDate clsDate::IncreaseDateByOneMillennium(clsDate Date)
{
	Date.IncreaseYear(1000);
	Date.CheckFebMonth();
	return Date;
}
void clsDate::IncreaseDateByOneMillennium()
{
	*this = IncreaseDateByOneMillennium(*this);
}

//Operation (39):
clsDate clsDate::DecreaseDateByOneDay(clsDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.DecreaseYear();
			Date.Month = 12;
			Date.Day = 31;
		}
		else
		{
			Date.DecreaseMonth();
			Date.Day = Date.NumberOfDaysInAMonth();
		}
	}
	else
	{
		Date.DecreaseDay();
	}
	
	return Date;
}
void clsDate::DecreaseDateByOneDay()
{
	*this = DecreaseDateByOneDay(*this);
}

//Operation (40):
clsDate clsDate::DecreaseDateByXDay(clsDate Date, int Days)
{
	for (int i = 1; i <= Days; i++)	Date.DecreaseDateByOneDay();
	return Date;
}
void clsDate::DecreaseDateByXDay(int Days)
{
	*this = DecreaseDateByXDay(*this, Days);
}

//Operation (41):
clsDate clsDate::DecreaseDateByOneWeek(clsDate Date)
{
	if (Date.Day > 7)
		Date.DecreaseDay(7);
	else
	{
		for (short i = 1; i <= 7; i++)
			Date.DecreaseDateByOneDay();
	}
	return Date;
}
void clsDate::DecreaseDateByOneWeek()
{
	*this = DecreaseDateByOneWeek(*this);
}

//Operation (42):
clsDate clsDate::DecreaseDateByXWeek(clsDate Date, int Weeks)
{
	for (int i = 1; i <= Weeks; i++)
		Date.DecreaseDateByOneWeek();
	return Date;
}
void clsDate::DecreaseDateByXWeek(int Weeks)
{
	*this = DecreaseDateByXWeek(*this, Weeks);
}

//Operation (43):
clsDate clsDate::DecreaseDateByOneMonth(clsDate Date)
{
	if (Date.Month == 1)
	{
		Date.DecreaseMonth();
		Date.Month = 12;
	}
	else
		Date.DecreaseMonth();

	short DaysInNewMonth = Date.NumberOfDaysInAMonth();
	Date.Day = (Date.Day > DaysInNewMonth) ? DaysInNewMonth : Date.Day;
	return Date;
}
void clsDate::DecreaseDateByOneMonth()
{
	*this = DecreaseDateByOneMonth(*this);
}

//Operation (44):
clsDate clsDate::DecreaseDateByXMonth(clsDate Date, int Months)
{
	short DaysInTheCurrentMonth = Date.NumberOfDaysInAMonth();
	for (int i = 1; i <= Months; i++)
		Date.DecreaseDateByOneMonth();

	short DaysInNewMonth = Date.NumberOfDaysInAMonth();
	Date.Day = (DaysInTheCurrentMonth > DaysInNewMonth) ? DaysInNewMonth : DaysInTheCurrentMonth;
	return Date;
}
void clsDate::DecreaseDateByXMonth(int Months)
{
	*this = DecreaseDateByXMonth(*this, Months);
}