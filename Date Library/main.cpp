#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("25/1/2000");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByOneMonth(Date);
	Date2.PrintDate();
	Date.IncreaseDateByOneMonth();
	Date.PrintDate();

	system("pause>0");
	return 0;
}