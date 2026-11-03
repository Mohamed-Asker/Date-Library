#pragma once
#include <iostream>


class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:
	//Properties set.
	void setDay(short Day);
	void setMonth(short Month);
	void setYear(short Year);

	//Read Only Properties.
	short getDay();
	short getMonth();
	short getYear();

	//Properties.
	__declspec(property(get = getDay, put = setDay)) short Day;
	__declspec(property(get = getMonth, put = setMonth))short Month;
	__declspec(property(get = getYear, put = setYear))short Year;

	//Constructors
	clsDate();
	clsDate(std::string sDate);
	clsDate(short Day, short Month, short Year);


	//Operations:
    //Operation (1):
	void PrintDate();

	//Operation (2):
	static bool isLeapYear(short year);
	bool isLeapYear();

	//Operation (3):
	static short NumberOfDaysInAYear(short year);
	short NumberOfDaysInAYear();

	//Operation (4):
	static int NumberOfHoursInAYear(short year);
	int NumberOfHoursInAYear();

	//Operation (5):
	static int NumberOfMinutesInAYear(short year);
	int NumberOfMinutesInAYear();

	//Operation (6):
	static int NumberOfSecondsInAYear(short year);
	int NumberOfSecondsInAYear();

	//Operation (7):
	static short NumberOfDaysInAMonth(short year, short month);
	short NumberOfDaysInAMonth();

	//Operation (8):
	static int NumberOfHoursInAMonth(short year, short month);
	int NumberOfHoursInAMonth();

	//Operation (9):
	static int NumberOfMinutesInAMonth(short year, short month);
	int NumberOfMinutesInAMonth();

	//Operation (10):
	static int NumberOfSecondsInAMonth(short year, short month);
	int NumberOfSecondsInAMonth();

	

	//Operation ():
	void SystemDate();

};