#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/11/2026");
	clsDate Date2("10/10/2026");

	std::cout << Date2.isDateAfterDate2(Date) << "\n";
	
	
	system("pause>0");
	return 0;
}