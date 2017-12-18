#include<iostream>
using namespace std;

class Time {
private:
	unsigned int hour;	// from 0 to 23
	unsigned int minutes;	// from 0 to 59
public:
	void input();
	void print();
	void addMinutes(unsigned int);
	unsigned int minutesFromBeginningOfTheDay();
	bool operator<(Time&);
	Time operator+(Time&);
	Time operator-(Time&);
	Time operator*(unsigned int);
};

void Time::input() {
	unsigned int hour;
	unsigned int minutes;
	cin >> hour >> minutes;
	if (hour > 24 || hour < 0) cout << "No such hour!\n";
	else this->hour = hour;
	if (minutes > 59 || minutes < 0) cout << "No such minutes!\n";
	else this->minutes = minutes;
}

void Time::print() {
	if (hour < 10) cout << 0;
	cout << hour << ":";
	if (minutes < 10) cout << 0;
	cout << minutes << endl;
}

void Time::addMinutes(unsigned int minutes) {
	unsigned int min = this->minutes + minutes;
	this->minutes = min % 60;
	this->hour += min / 60;
	this->hour %= 24;
}

unsigned int Time::minutesFromBeginningOfTheDay() {
	return hour * 60 + minutes;
}

bool Time::operator<(Time& time) {
	if (hour > time.hour) return false;
	if (hour < time.hour) return true;
	if (minutes < time.minutes) return true;
	return false;
}

Time Time::operator+(Time& time) {
	Time newTime;
	unsigned int minutes = this->minutesFromBeginningOfTheDay() + time.minutesFromBeginningOfTheDay();
	newTime.minutes = minutes % 60;
	newTime.hour = (minutes / 60) % 24;
	return newTime;
}

Time Time::operator-(Time& time) {
	if ((*this) < time) {
		cout << "Can not substract! Time 1 is less than time2!\n";
		return (*this);
	}
	Time newTime;
	unsigned int minutes = this->minutesFromBeginningOfTheDay() - time.minutesFromBeginningOfTheDay();
	newTime.minutes = minutes % 60;
	newTime.hour = (minutes / 60) % 24;
	return newTime;
}

Time Time::operator*(unsigned int number) {
	Time newTime;
	unsigned int minutes = this->minutesFromBeginningOfTheDay() * number;
	newTime.minutes = minutes % 60;
	newTime.hour = (minutes / 60) % 24;
	return newTime;
}

Time operator*(unsigned int number, Time& time) {
	return time * number;
}

int main() {
	Time time1, time2;

	time1.input();
	time2.input();

	time1.print();
	time2.print();

	time1.addMinutes(120);
	time2.addMinutes(384);

	cout << "----------------------\n";
	time1.print();
	time2.print();

	cout << "----------------------\n" ;
	cout << time1.minutesFromBeginningOfTheDay() << endl;
	cout << time2.minutesFromBeginningOfTheDay() << endl;

	cout << "----------------------\n";
	if (time1 < time2) cout << "Time 1 is earlier than time 2.\n";
	else cout << "Time 1 is the same or later than time 2.\n";

	Time time3 = time1 + time2;
	cout << "----------------------\n";
	time3.print();

	Time time4 = time1 - time2;
	cout << "----------------------\n";
	time4.print();

	Time time5 = time1 * 3;
	cout << "----------------------\n";
	time5.print();

	Time time6 = 3 * time1;
	cout << "----------------------\n";
	time6.print();

	system("pause");
	return 0;
}