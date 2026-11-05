#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("6/11/2026");
	clsDate Date2;


	std::cout << clsDate::isWeekEnd(Date) << "\n";
	
	
	system("pause>0");
	return 0;
}