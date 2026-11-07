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
	static bool isOverlapPeriods(const clsPeriod& Period1, const clsPeriod& Period2);
	bool isOverlapWith(const clsPeriod& Period2);

	//Operation(2):
	static int PeriodLength(clsPeriod Period, bool includeCurrentDay = true);
	int PeriodLength(bool includeCurrentDay = true);
};