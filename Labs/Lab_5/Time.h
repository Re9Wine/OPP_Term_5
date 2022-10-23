using namespace std;

#include <iostream>
#include <istream>
#pragma once

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time();
	Time(int hours, int minutes, int seconds);
	~Time();
	void add(int time);
	int getInSeconds();
	void setHours(int hours);
	void setMinutes(int minutes);
	void setSeconds(int seconds);
	int getHours();
	int getMinutes();
	int getSeconds();
	friend ostream& operator << (ostream& out, const Time& time);
	friend istream& operator >> (istream& in, Time& time);
	friend Time operator+ (Time time_1, Time time_2);
};

