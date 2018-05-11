//Time.h Time类的声明
#ifndef _TIME_INC_
#define _TIME_INC_

#include <string>
using namespace std;

class Time
{
public:
	Time() :hour(0), minute(0), sec(10){}
	void Reset();

	Time operator++();
	Time operator--();

	string GetTime()const;

private:
	int hour;
	int minute;
	int sec;
};

#endif
