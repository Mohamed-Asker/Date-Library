#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"



int main()
{
	clsDate Date("20/1/2022");
	clsDate Date2("20/1/2022");
	clsDate Date1("1/1/2022");
	
	std::cout << clsDate::isDateBetween(Date, Date1, Date2) << "\n";
	


	
	system("pause>0");
	return 0;
}