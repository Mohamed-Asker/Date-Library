#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/10/2026");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByXWeeks(Date, 2);
	Date2.PrintDate();
	Date.IncreaseDateByXWeeks(2);
	Date.PrintDate();

	system("pause>0");
	return 0;
}