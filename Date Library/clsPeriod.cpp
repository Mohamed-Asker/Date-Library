#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"


//Constructor.
clsPeriod::clsPeriod() {};
clsPeriod::clsPeriod(const clsDate& StartDate, const clsDate& EndDate) : StartDate(StartDate), EndDate(EndDate) {}

//Operations:
//Operation(1):
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