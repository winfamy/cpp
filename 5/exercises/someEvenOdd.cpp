#include <string>
#include <iostream>

using namespace std;

int main() {
	char c;
	int oddsum = 0, evensum = 0, oddcount = 0, evencount = 0, num = 0;

	cout << "Numbers: ";
	// cin.get(c);
	while (cin >> num) {
		if (num % 2 == 0) {
			evensum += num;
			evencount++;
		} else {
			oddsum += num;
			oddcount++;
		}
	}

	cout << "Odd sum: " << oddsum << endl;
	cout << "Even sum: " << evensum << endl;

	return 0;
}