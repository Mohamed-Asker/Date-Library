#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("29/2/2000");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByXYears(Date, 10);
	Date.IncreaseDateByXYears(10);
	Date.PrintDate();
	Date2.PrintDate();

	system("pause>0");
	return 0;
}