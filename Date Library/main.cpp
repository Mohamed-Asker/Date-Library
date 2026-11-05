#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("31/7/2000");
	clsDate Date2;

	Date.DecreaseDateByXMonth(8);
	Date.PrintDate();
	
	
	system("pause>0");
	return 0;
}