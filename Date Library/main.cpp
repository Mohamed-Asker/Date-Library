#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("20/4/2000");
	Date.PrintDate();


	std::cout << Date.NumberOfDaysInAMonth() << "\n";
	std::cout << Date.NumberOfHoursInAMonth() << "\n";
	std::cout << clsDate::NumberOfMinutesInAMonth(2, 2000) << "\n";
	std::cout << clsDate::NumberOfSecondsInAMonth(2,2000) << "\n";




	system("pause>0");
	return 0;
}