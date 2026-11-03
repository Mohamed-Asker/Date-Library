#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("20/4/2000");
	Date.PrintDate();


	std::cout << Date.isLeapYear() << "\n";
	std::cout << clsDate::isLeapYear(2001) << "\n";




	system("pause>0");
	return 0;
}