#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("31/1/2000");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByXMonths(Date, 12);
	Date2.PrintDate();
	Date.IncreaseDateByXMonths(12);
	Date.PrintDate();

	system("pause>0");
	return 0;
}