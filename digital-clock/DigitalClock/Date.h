#ifndef _DATE_INC_
#define _DATE_INC_

#include <string>
using namespace std;

class Date
{
public:
	Date();
	Date(int year, int month, int day);
	
	Date operator++(); // 日期增加1天
	Date operator--(); // 日期减少1天

	string GetDate() const;

	int MaxDay();

private:
	int _year;
	int _month;
	int _day;
};

#endif