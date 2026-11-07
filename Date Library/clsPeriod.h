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
};