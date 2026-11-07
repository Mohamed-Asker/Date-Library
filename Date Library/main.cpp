#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"



int main()
{
	
	clsPeriod Period(clsDate("25/12/2021"), clsDate("3/1/2022"));
	clsPeriod Period2(clsDate("1/1/2022"), clsDate("5/1/2022"));
	clsDate Date("6/1/2022");

	std::cout << Period.CountOverlapsDays(Period2) << "\n";
	
	
	
	system("pause>0");
	return 0;
}