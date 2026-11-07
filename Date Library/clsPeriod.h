#pragma once
#include <iostream>
#include "clsDate.h"


class clsPeriod
{
public:
	clsDate StartDate;
	clsDate EndDate;

	//Constructors.
	clsPeriod();
	clsPeriod(const clsDate& StartDate, const clsDate& EndDate);

	//Operations:
	//Operation(1):
	void PrintPeriod();
	
	//Operation(2):
	static bool isOverlapPeriods(const clsPeriod& Period1, const clsPeriod& Period2);
	bool isOverlapWith(const clsPeriod& Period2);

	//Operation(3):
	static int PeriodLength(clsPeriod Period, bool includeCurrentDay = true);
	int PeriodLength(bool includeCurrentDay = true);

	//Operation(4):
	static bool isDateInPeriod(const clsPeriod& Period, const clsDate& Date);
	bool isDateInPeriod(const clsDate& Date);
};