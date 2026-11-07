#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"


//Constructor.
clsPeriod::clsPeriod() {};
clsPeriod::clsPeriod(const clsDate& StartDate, const clsDate& EndDate) : StartDate(StartDate), EndDate(EndDate) {}

//Operations:
// 	//Operation(1):
void clsPeriod::PrintPeriod()
{
	std::cout << "Period Start: ";
	StartDate.PrintDate();

	std::cout << "Period End  : ";
	EndDate.PrintDate();
}

//Operation(2):
bool clsPeriod::isOverlapPeriods(const clsPeriod& Period1, const clsPeriod& Period2)
{
	return !(clsDate::CompareDate(Period2.EndDate, Period1.StartDate) == clsDate::Before || clsDate::CompareDate(Period2.StartDate, Period1.EndDate) == clsDate::After);
	
	//Another Solution:
	/*return clsDate::CompareDate(Period1.StartDate, Period2.EndDate) != clsDate::After && clsDate::CompareDate(Period1.EndDate, Period2.StartDate) != clsDate::Before;*/
}
bool clsPeriod::isOverlapWith(const clsPeriod& Period2)
{
	return isOverlapPeriods(*this, Period2);
}

//Operation(3):
int clsPeriod::PeriodLength(clsPeriod Period, bool includeCurrentDay)
{
	return Period.StartDate.DiffInDays(Period.EndDate, includeCurrentDay);
}
int clsPeriod::PeriodLength(bool includeCurrentDay)
{
	return PeriodLength(*this, includeCurrentDay);
}