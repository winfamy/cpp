#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
	int value;
	ofstream fout;
	fout.open("./outfiles/property.txt");

	cout << "Value: ";
	cin >> value;
	cout << "\n";

	fout << setprecision(2) << fixed;
	fout << setw(20) << left << "Assessed Value: " << right << setw(20) << double(value) << endl;
	fout << setw(20) << left << "Property Value: " << right << setw(20) << value*.92 << endl;
	fout << setw(20) << left << "Rate for $100.00: " << right << setw(20) << 1.05 << endl;
	fout << setw(20) << left << "Taxes: " << right << setw(20) << value*.92/100*1.05 << endl;

	return 0;
}