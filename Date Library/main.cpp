#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/11/2026");
	clsDate Date2("10/11/2026");

	std::cout << Date.CalculateWorkDays(Date2) << "\n";
	std::cout << Date2.CalculateWorkDays(Date) << "\n";
	
	
	system("pause>0");
	return 0;
}