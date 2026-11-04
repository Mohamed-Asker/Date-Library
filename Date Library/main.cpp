#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("1/11/2026");
	clsDate Date2("1/11/2026");

	std::cout << clsDate::isDate1EqualDate2(Date, Date2) << "\n";

	system("pause>0");
	return 0;
}