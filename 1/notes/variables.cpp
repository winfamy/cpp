#include <iostream>
#include <string>

using namespace std;

int main() {
	string name;
	int num1, num2;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter an integer: ";
	cin >> num1;

	cout << "Enter an integer: ";
	cin >> num2;

	cout << "Hello, " << name << endl;

	cout << num1 + num2 << endl;
	cout << num1 * num2 << endl;
	cout << num1 % num2 << endl;
	cout << (double)num1 / num2 << endl;

	return 0;
}