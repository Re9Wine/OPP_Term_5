using namespace std;

#include <iomanip>
#include <iostream>
#include "Time.h"

const int minuteInSeconds = 60;
const int hourInSeconds = 3600;
const int maxTimeInSeconds = 86400;

Time::Time() {
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::~Time() {

}

void Time::add(int time)
{
	time += getInSeconds();

	while (time > maxTimeInSeconds) {
		time -= maxTimeInSeconds;
	}

	setHours(time / hourInSeconds);

	time -= hours * hourInSeconds;

	setMinutes(time / minuteInSeconds);

	time -= minutes * minuteInSeconds;

	setSeconds(time);
}

int Time::getInSeconds()
{
	return hours * hourInSeconds + minutes * minuteInSeconds + seconds;
}

void Time::setHours(int hours) {
	if (hours > 24 || hours < 0) {
		throw "Uncorrect hours";
	}

	this->hours = hours;
}

void Time::setMinutes(int minutes) {
	if (minutes > 60 || minutes < 0) {
		throw "Uncorrect minutes";
	}

	this->minutes = minutes;
}

void Time::setSeconds(int seconds) {
	if (seconds > 60 || seconds < 0) {
		throw "Uncorrect seconds";
	}

	this->seconds = seconds;
}

int Time::getHours() { return hours; }
int Time::getMinutes() { return minutes; }
int Time::getSeconds() { return seconds; }

ostream& operator<< (ostream& out, const Time& time) {
	out << setfill('0') << setw(2) << time.hours << ":" 
		<< setfill('0') << setw(2) << time.minutes << ":" 
		<< setfill('0') << setw(2) << time.seconds;

	return out;
}

istream& operator>>(istream& in, Time& time)
{
	in >> time.hours;
	in >> time.minutes;
	in >> time.seconds;

	return in;
}

Time operator+(Time time_1, Time time_2)
{
	time_1.add(time_2.getInSeconds());

	return time_1;
}
