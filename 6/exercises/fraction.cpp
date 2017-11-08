#include <string>
#include <iostream>

using namespace std;

void reduceF(int&, int&, int);
int gcf(int, int);

int gcf(int a, int b) {
	int f;

	// cout << ((a < b) ? a : b) << endl;

	for (int i = 1; i <= ((a < b) ? a : b); i++)
		if (a % i == 0 && b % i == 0)
			f = i;

	return f;
}

void reduceF(int &n, int &d, int f) {
	n = n/f;
	d = d/f;
}

int main() {
	int num = 0, denom = 0;

	cout << "---- Fraction Reducer ----" << endl;

	cout << "Numerator: ";
	cin >> num;

	while (denom == 0) {
		cout << "Denominator: ";
		cin >> denom;
	}

	cout << num << "/" << denom << " = ";
	if (num == 0)
		cout << 0 << endl;
	else {
		reduceF(num, denom, gcf(num, denom));
		cout << num << "/" << denom << endl;
	}

	return 0;
}
