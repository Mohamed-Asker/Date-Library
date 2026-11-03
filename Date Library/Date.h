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

	//Operation ():
	void SystemDate();

};