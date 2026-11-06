#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/1/2026");
	clsDate Date2("1/1/2026");
	

	std::cout << Date.CompareDate(Date2) << "\n";
	
	system("pause>0");
	return 0;
}