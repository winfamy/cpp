#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class date {
	public:
		date();
		date(int, int, int);
		int getMonth();
		int getDay();
		int getYear();
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		void displayDate1();
		void displayDate2();
		void displayDate3();
	private:
		int month;
		int day;
		int year;
		static string monthNames[12];
};

#endif