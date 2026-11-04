#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/10/2026");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByOneWeek(Date);
	Date2.PrintDate();
	Date.IncreaseDateByOneWeek();
	Date.PrintDate();

	system("pause>0");
	return 0;
}