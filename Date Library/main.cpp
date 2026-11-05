#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("6/11/2026");
	clsDate Date2;


	std::cout << Date.CalCulateDaysToEndOfMonth() << "\n";
	std::cout << clsDate::CalCulateDaysToEndOfMonth(Date2) << "\n";
	
	
	system("pause>0");
	return 0;
}