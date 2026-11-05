#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("8/3/2000");
	clsDate Date2;

	Date.DecreaseDateByXWeek(2);
	Date.PrintDate();
	

	system("pause>0");
	return 0;
}