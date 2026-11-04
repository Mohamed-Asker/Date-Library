#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("10/1/2000");
	clsDate Date2("20/1/2000");
	

	std::cout << Date.DiffInDays(Date2, false) << "\n";
	std::cout << Date2.DiffInDays(Date) << "\n";

	std::cout << clsDate::DiffInDays(Date, Date2) << "\n";
	

	system("pause>0");
	return 0;
}