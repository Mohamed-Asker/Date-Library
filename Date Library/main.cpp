#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("3/11/2026");
	Date.PrintDate();


	std::cout << clsDate::DayName(2, 11, 2026) << "\n";
	std::cout << Date.DayName() << "\n";
	std::cout << clsDate::DayName(0) << "\n";




	system("pause>0");
	return 0;
}