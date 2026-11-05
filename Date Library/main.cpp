#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/3/2000");
	clsDate Date2;

	Date.DecreaseDateByOneDay();
	Date.PrintDate();
	

	system("pause>0");
	return 0;
}