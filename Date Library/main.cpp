#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("28/2/2000");
	Date.AddOneDayToDate();
	
	Date.PrintDate();

	system("pause>0");
	return 0;
}