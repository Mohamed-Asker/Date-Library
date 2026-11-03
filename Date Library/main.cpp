#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("20/4/2000");
	Date.PrintDate();


	std::cout << Date.NumberOfDaysInAYear() << "\n";
	std::cout << Date.NumberOfHoursInAYear() << "\n";
	std::cout << clsDate::NumberOfMinutesInAYear(2000) << "\n";
	std::cout << clsDate::NumberOfSecondsInAYear(2000) << "\n";




	system("pause>0");
	return 0;
}