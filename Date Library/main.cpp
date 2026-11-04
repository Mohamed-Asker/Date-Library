#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/10/2026");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByXDays(Date, 10);
	Date.PrintDate();
	Date.IncreaseDateByXDays(10);
	Date.PrintDate();

	system("pause>0");
	return 0;
}