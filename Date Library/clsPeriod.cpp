#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"


//Constructor.
clsPeriod::clsPeriod() {};
clsPeriod::clsPeriod(const clsDate& StartDate, const clsDate& EndDate) : StartDate(StartDate), EndDate(EndDate) {}