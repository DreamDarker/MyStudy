#include "Time.h"
#include "Date.h"

Date Dt(2012, 3, 1);

void Time::Reset()
{
	hour = 0;
	minute = 0;
	sec = 0;
};

Time Time::operator++()
{
	if (++sec >= 60){
		sec = 0;
		++minute;
	}

	if (minute >= 60){
		minute = 0;
		++hour;
	}

	if (hour >= 24) {
		hour = 0;
		++Dt;
	}

	return *this;
}

Time Time::operator--()
{
	if (--sec < 0){
		sec = 59;
		--minute;
	}

	if (minute < 0){
		minute = 59;
		--hour;
	}

	if (hour < 0) {
		hour = 23;
		--Dt;
	}

	return *this;
}

string Time::GetTime()const
{
	char c[32];
	sprintf_s(c, 32, "%02d:%02d:%02d", hour, minute, sec);
	return string(c);
}

Date::Date()
{
	_year = 1970;
	_month = 1;
	_day = 1;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

int Date::MaxDay()
{
	int max_day = 30;
	switch (_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:max_day = 31;	break;
	case 2:if ((((_year % 4) == 0) && (_year % 100) != 0) || (((_year % 100) == 0) && (_year % 400) == 0))
	{
		max_day = 28;	break;
	}
		   else max_day = 29;	break;
	case 4:
	case 6:
	case 9:
	case 11:max_day = 30;	break;
	};
	return max_day;
}

Date Date::operator++()
{
	if (++_day > MaxDay())
	{
		_day = 1;
		++_month;
	}

	if (_month > 12)
	{
		_month = 1;
		++_year;
	}

	return *this;
}

Date Date::operator--()
{
	if (--_day < 1)
	{
		--_month;
		_day = MaxDay();
	}

	if (_month < 1)
	{
		_month = 12;
		--_year;
	}

	return *this;
}

string Date::GetDate() const
{
	char c[32];
	sprintf_s(c, 32, "%04d-%02d-%02d", _year, _month, _day);
	return string(c);
}