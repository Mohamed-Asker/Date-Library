#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("10/3/2000");
	clsDate Date2;

	Date.DecreaseDateByXDay(5);
	Date.PrintDate();
	

	system("pause>0");
	return 0;
}