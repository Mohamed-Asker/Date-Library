#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("15/1/2026");

	std::cout << Date.DaysFromBeginningOfYear() << "\n";
	std::cout << clsDate::DaysFromBeginningOfYear(1, 3, 2000);
	



	system("pause>0");
	return 0;
}