#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/1/2022");
	clsDate Date2("10/11/2026");
	

	Date2 = Date.CalculateReturnVacationDays(23);
	Date2.PrintDate();
	
	system("pause>0");
	return 0;
}