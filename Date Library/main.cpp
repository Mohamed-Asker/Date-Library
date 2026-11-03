#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("3/11/2026");
	Date.PrintDate();


	std::cout << Date.DayOfWeekInOrder() << "\n";
	std::cout << clsDate::DayOfWeekInOrder(2, 11, 2026) << "\n";




	system("pause>0");
	return 0;
}