#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("29/2/2000");
	clsDate Date2;

	Date.IncreaseDateByXDecade(10);
	Date.PrintDate();
	

	system("pause>0");
	return 0;
}