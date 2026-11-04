#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("28/2/2000");
	clsDate Date2("1/5/2026");
	

	clsDate::SwapDates(Date, Date2);

	Date.PrintDate();
	Date2.PrintDate(); 

	system("pause>0");
	return 0;
}