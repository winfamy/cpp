#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("./data/times.txt");
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

template <size_t rows, size_t cols>
void getValues(int i, double (&times)[rows][cols]) {
	string name;
	fin >> name;
	// cout << name;

	double sum = 0;
	for (int j = 0; j < 7; j++) {
		fin >> times[i][j];
		sum += times[i][j];
	}
	times[i][7] = sum/7;
}

template <size_t rows, size_t cols>
void displayTimes(int i, double (&times)[rows][cols], string (&names)[rows])  {
	if (i == 0) {
		cout << fixed << showpoint << setprecision(2);
		cout << setw(8) << "Name";
		cout << setw(8) << "Day 1";
		cout << setw(8) << "Day 2";
		cout << setw(8) << "Day 3";
		cout << setw(8) << "Day 4";
		cout << setw(8) << "Day 5";
		cout << setw(8) << "Day 6";
		cout << setw(8) << "Day 7";
		cout << setw(8) << "Avg.";
		cout << endl;
	}

	cout << setw(8) << names[i];
	for (int j = 0; j < 8; j++) {
		cout << setw(8) << times[i][j];
	}
	cout << endl;
}

int main() {
	string names[] = {"Abe", "Betty", "Cara", "Don", "Eli"};
	double times[5][8];
	for (int i = 0; i < array_size(names); i++) {
		getValues<5,8>(i, times);
		displayTimes<5,8>(i, times, names);
	}

	return 0;
}
