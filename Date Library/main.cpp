#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("28/2/1999");
	clsDate Date2;

	Date2 = clsDate::IncreaseDateByOneYear(Date);
	Date.IncreaseDateByOneYear();
	Date.PrintDate();

	system("pause>0");
	return 0;
}