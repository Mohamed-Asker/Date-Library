#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"



int main()
{
	
	clsPeriod Period(clsDate("1/1/2022"), clsDate("5/1/2022"));
	clsPeriod Period2(clsDate("3/1/2022"), clsDate("10/1/2022"));

	std::cout << Period.isOverlapWith(Period2) << "\n";
	
	
	
	system("pause>0");
	return 0;
}