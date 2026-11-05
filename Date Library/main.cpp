#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/11/2026");
	clsDate Date2;


	std::cout << Date.CalCulateDaysToEndOfYear() << "\n";
	std::cout << clsDate::CalCulateDaysToEndOfYear(Date , true) << "\n";
	
	
	system("pause>0");
	return 0;
}