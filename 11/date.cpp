#include "date.h"
#include <iostream>
#include <string>

using namespace std;

date::date() {
	this->day = 1;
	this->month = 1;
	this->year = 1990;
}

date::date(int d, int m, int y) {
	if (d < 1 || d > 31) {
		cout << "use a day > 1 and < 31" << endl;
	}

	if (m < 1 || m > 12) {
		cout << "use a month > 1 and < 12" << endl;
	}

	if (y < 1900) {
		cout << "use a year > 1900" << endl;
	}

	this->day = d;
	this->month = m;
	this->year = y;
}

int date::getDay() {
	return this->day;
}

int date::getMonth() {
	return this->month;
}

int date::getYear() {
	return this->year;
}

void date::setDay(int d) {
	this->day = d;
}

void date::setMonth(int m) {
	this->month = m;
}

void date::setYear(int y) {
	this->year = y;
}

void date::displayDate1() {
	cout << this->month << "/" << this->day << "/" << this->year << endl;
}

void date::displayDate2() {
	cout << date::monthNames[month-1] << " " << this->day << ", " << this->year << endl;
}

void date::displayDate3() {
	for (int i = 0; i < 12; i++) {
		cout << date::monthNames[i] << endl;
	}

	cout << this->day << " " << date::monthNames[month-1] << " " << this->year << endl;
}

string date::monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};