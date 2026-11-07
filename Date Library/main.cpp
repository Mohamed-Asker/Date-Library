#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"



int main()
{
	clsDate Date("6/1/2022");

	std::cout << Date.FormatDate("dd/mm/yyyy") << "\n";
	std::cout << Date.FormatDate("dd-mm-yyyy") << "\n";
	std::cout << Date.FormatDate("yyyy/mm/dd") << "\n";
	std::cout << Date.FormatDate("dd/mm/yyyy") << "\n";
	std::cout << Date.FormatDate("dd/mm/yyyy") << "\n";
	std::cout << Date.FormatDate("Day: dd, Month/mm, year/yyyy") << "\n";
	
	
	
	system("pause>0");
	return 0;
}