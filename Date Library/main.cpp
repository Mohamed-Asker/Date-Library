#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("3/11/2026");
	Date.PrintDate();

	std::cout << clsDate::MonthName(2) << "\n";
	std::cout << Date.MonthName();




	system("pause>0");
	return 0;
}