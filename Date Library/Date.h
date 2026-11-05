#pragma once
#include <iostream>


class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

protected:
	//Following To Operation (14).
	static void PrintHeaderOfMonthCalender(short year, short month);

	//Helpers Functions
	void IncreaseDay(int Days = 1);
	void IncreaseMonth(int Months = 1);
	void IncreaseYear(int Years = 1);
	void DecreaseDay(int Days = 1);
	void DecreaseMonth(int Months = 1);
	void DecreaseYear(int Years = 1);
	void CheckFebMonth();

public:
	//Setters.
	void setDay(short Day);
	void setMonth(short Month);
	void setYear(short Year);

	//Getters.
	short getDay() const;
	short getMonth() const;
	short getYear() const;

	//Properties.
	__declspec(property(get = getDay, put = setDay)) short Day;
	__declspec(property(get = getMonth, put = setMonth))short Month;
	__declspec(property(get = getYear, put = setYear))short Year;

	//Constructors
	clsDate();
	clsDate(std::string sDate);
	clsDate(short Day, short Month, short Year);
	clsDate(short DayOrderInYear, short year);

	//Operations:
    //Operation (1):
	void PrintDate();

	//Operation (2):
	static bool isLeapYear(short year);
	bool isLeapYear(); 

	//Operation (3):
	static short NumberOfDaysInAYear(short year);
	short NumberOfDaysInAYear();

	//Operation (4):
	static int NumberOfHoursInAYear(short year);
	int NumberOfHoursInAYear();

	//Operation (5):
	static int NumberOfMinutesInAYear(short year);
	int NumberOfMinutesInAYear();

	//Operation (6):
	static int NumberOfSecondsInAYear(short year);
	int NumberOfSecondsInAYear();

	//Operation (7):
	static short NumberOfDaysInAMonth(short year, short month);
	short NumberOfDaysInAMonth();

	//Operation (8):
	static int NumberOfHoursInAMonth(short year, short month);
	int NumberOfHoursInAMonth();

	//Operation (9):
	static int NumberOfMinutesInAMonth(short year, short month);
	int NumberOfMinutesInAMonth();

	//Operation (10):
	static int NumberOfSecondsInAMonth(short year, short month);
	int NumberOfSecondsInAMonth();

	//Operation (11):
	static short DayOfWeekInOrder(short day, short month, short year);
	short DayOfWeekInOrder();

	//Operation (12):
	static std::string DayName(short Day);
	static std::string DayName(short day, short month, short year);
	std::string DayName();

	//Operation (13):
	static std::string MonthName(short month);
	std::string MonthName();

	//Operation (14):
	static void MonthCalender(short year, short month);
	void MonthCalender();

	//Operation (15):
	static void YearCalender(short year);
	void YearCalender();

	//Operation (16):
	static short DaysFromBeginningOfYear(short day, short month, short year);
	short DaysFromBeginningOfYear();

	//Operation (17):
	static clsDate DateFromDayOrderInYear(short DayOrder, short year);

	//Operation (18):
	static clsDate AddDaysToDate(clsDate Date, int Days);
	void AddDaysToDate(int Days);

	//Operation (19):
	static bool isDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2);
	bool isDateBeforeDate2(const clsDate& Date2);

	//Operation (20):
	static bool isDate1EqualDate2(const clsDate& Date1, const clsDate& Date2);
	bool isDateEqualDate2(const clsDate& Date2);

	//Operation (21):
	static bool isLastDayInAMonth(clsDate& Date);
	bool isLastDayInAMonth();

	//Operation (22):
	static bool isLastMonthInAYear(short month);
	bool isLastMonthInAYear();

	//Operation (23):
	static clsDate AddOneDayToDate(clsDate Date);
	void AddOneDayToDate();

	//Operation (24):
	static void SwapDates(clsDate& Date1, clsDate& Date2);
	void SwapDates(clsDate& Date2);

	//Operation (25):
	static int DiffInDays(clsDate Date1, clsDate Date2, bool IncludeCurrentDay = false);
	int DiffInDays(clsDate Date2, bool IncludeCurrentDay = false);

	//Operation (26):
	static clsDate SystemDate();

	//Operation (27):
	static int YourAgeInDays(clsDate BirthDay);
	int YourAgeInDays();

	//Operation (28):
	static clsDate IncreaseDateByXDays(clsDate Date, int Days);
	void IncreaseDateByXDays(int Days);

	//Operation (29):
	static clsDate IncreaseDateByOneWeek(clsDate Date);
	void IncreaseDateByOneWeek();

	//Operation (30):
	static clsDate IncreaseDateByXWeeks(clsDate Date, int Weeks);
	void IncreaseDateByXWeeks(int Weeks);

	//Operation (31):
	static clsDate IncreaseDateByOneMonth(clsDate Date);
	void IncreaseDateByOneMonth();

	//Operation (32):
	static clsDate IncreaseDateByXMonths(clsDate Date, int Months);
	void IncreaseDateByXMonths(int Months);

	//Operation (33):
	static clsDate IncreaseDateByOneYear(clsDate Date);
	void IncreaseDateByOneYear();

	//Operation (34):
	static clsDate IncreaseDateByXYears(clsDate Date, int Years);
	void IncreaseDateByXYears(int Years);

	//Operation (35):
	static clsDate IncreaseDateByOneDecade(clsDate Date);
	void IncreaseDateByOneDecade();

	//Operation (36):
	static clsDate IncreaseDateByXDecade(clsDate Date, int Decade);
	void IncreaseDateByXDecade(int Decade);

	//Operation (37):
	static clsDate IncreaseDateByOneCentury(clsDate Date);
	void IncreaseDateByOneCentury();

	//Operation (38):
	static clsDate IncreaseDateByOneMillennium(clsDate Date);
	void IncreaseDateByOneMillennium();

	//Operation (39):
	static clsDate DecreaseDateByOneDay(clsDate Date);
	void DecreaseDateByOneDay();

	//Operation (40):
	static clsDate DecreaseDateByXDay(clsDate Date, int Days);
	void DecreaseDateByXDay(int Days);

	//Operation (41):
	static clsDate DecreaseDateByOneWeek(clsDate Date);
	void DecreaseDateByOneWeek();

	//Operation (42):
	static clsDate DecreaseDateByXWeek(clsDate Date, int Weeks);
	void DecreaseDateByXWeek(int Weeks);

	//Operation (43):
	static clsDate DecreaseDateByOneMonth(clsDate Date);
	void DecreaseDateByOneMonth();

	//Operation (44):
	static clsDate DecreaseDateByXMonth(clsDate Date, int Months);
	void DecreaseDateByXMonth(int Months);

	//Operation (45):
	static clsDate DecreaseDateByOneYear(clsDate Date);
	void DecreaseDateByOneYear();

	//Operation (46):
	static clsDate DecreaseDateByXYear(clsDate Date, int Years);
	void DecreaseDateByXYear(int Years);

	//Operation (47):
	static clsDate DecreaseDateByOneDecade(clsDate Date);
	void DecreaseDateByOneDecade();

	//Operation (48):
	static clsDate DecreaseDateByXDecade(clsDate Date, int Decades);
	void DecreaseDateByXDecade(int Decades);

	//Operation (49):
	static clsDate DecreaseDateByOneCentury(clsDate Date);
	void DecreaseDateByOneCentury();

	//Operation (50):
	static clsDate DecreaseDateByOneMillennium(clsDate Date);
	void DecreaseDateByOneMillennium();

	//Operation (51):
	static bool isEndOfWeek(clsDate& Date);
	bool isEndOfWeek();

	//Operation (52):
	static bool isWeekEnd(clsDate& Date);
	bool isWeekEnd();

	//Operation (53):
	static bool isWordDay(clsDate& Date);
	bool isWordDay();

	//Operation (54):
	static short CalCulateDaysToEndOfWeek(clsDate& Date);
	short CalCulateDaysToEndOfWeek();

	//Operation (55):
	static short CalCulateDaysToEndOfMonth(clsDate Date, bool IncludeCurrentDay = false);
	short CalCulateDaysToEndOfMonth(bool IncludeCurrentDay = false);
};
