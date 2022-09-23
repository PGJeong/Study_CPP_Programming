#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Date {
private:
	int year; int month; int day;
	string date;
public:
	Date(int year, int month, int day) { this->year = year; this->month = month; this->day = day; }
	Date(string date) { this->date = date; }
	void show();
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

void Date::show() {
	char date[30] = "";
	char* context = NULL;
	int year, month, day;
	for (int i = 0; i < this->date.length(); i++)
		date[i] = this->date[i];
	year = atoi(strtok_s(date, "/ ", &context));
	month = atoi(strtok_s(NULL, "/ ", &context));
	day = atoi(strtok_s(NULL, "/ ", &context));
	cout << year << "³â " << month << "¿ù " << day << "ÀÏ" << endl;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}