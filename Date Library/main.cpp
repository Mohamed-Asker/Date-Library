#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("22/1/2000");
	clsDate Date2;

	Date.DecreaseDateByOneMonth();
	Date.PrintDate();
	
	
	system("pause>0");
	return 0;
}