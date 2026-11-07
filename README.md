 
<div align="center">

# 📅 Date & Period Library

**A simple C++ library for working with dates and date periods.**

---

### 🏅 Badges

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?logo=c%2B%2B)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-purple?logo=visualstudio&logoColor=white)
![Git](https://img.shields.io/badge/Tool-Git-orange?logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/Platform-GitHub-black?logo=github&logoColor=white)
![MIT License](https://img.shields.io/badge/License-MIT-green)

</div>

---

## 📖 About The Library

Date & Period Library is a C++ library designed to make working with dates and date periods easier.

It provides useful functions for date calculations, comparisons, calendar generation, and period management.

## ✨ Features

### 📅 clsDate

- Create dates using different constructors.
- Check leap years.
- Calculate days, hours, minutes, and seconds.
- Get day and month names.
- Generate monthly and yearly calendars.
- Increase and decrease dates.
- Compare two dates.
- Calculate age in days.
- Calculate working days and vacation days.
- Format dates into strings.
- Validate dates.

### 📆 clsPeriod

- Create date periods using start and end dates.
- Print date periods.
- Check whether two periods overlap.
- Calculate period length.
- Check whether a date belongs to a period.
- Count overlapping days between two periods.

## 💻 Usage Example

```cpp
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"

int main()
{
    clsDate Date1(1, 1, 2026);
    clsDate Date2(10, 1, 2026);

    Date1.PrintDate();

    clsPeriod Period(Date1, Date2);

    Period.PrintPeriod();

    return 0;
}
```

## 🛠️ Technologies & Tools

- C++
- Visual Studio
- Git
- GitHub

## 📂 Project Structure

```text
DateLibrary/
│
├── clsDate.h
├── clsDate.cpp
│
├── clsPeriod.h
├── clsPeriod.cpp
│
└── main.cpp
```

## 📜 License

This project is licensed under the MIT License.

## 👨‍💻 Author

**Mohamed Askar**

