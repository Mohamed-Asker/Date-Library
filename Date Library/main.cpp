#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("31/3/2000");
	clsDate Date2;

	Date.DecreaseDateByXYear(3);
	Date.PrintDate();
	
	
	system("pause>0");
	return 0;
}