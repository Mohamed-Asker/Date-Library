#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("29/2/2000");
	clsDate Date2;

	Date.DecreaseDateByXYear(4);
	Date.PrintDate();
	
	
	system("pause>0");
	return 0;
}