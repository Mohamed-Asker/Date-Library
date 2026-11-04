#include <iostream>
#include "Date.h"



int main()
{
	clsDate Date("31/11/2026");
	clsDate Date2("30/12/2026");
	clsDate Date3("29/2/2000");
	clsDate Date4("29/2/2001");

	std::cout << Date.isLastMonthInAYear() << "\n";
	std::cout << Date2.isLastMonthInAYear() << "\n";

	system("pause>0");
	return 0;
}