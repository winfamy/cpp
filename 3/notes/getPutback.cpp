/*

	Error trapping using get() and putback()

	cin.get(char) gets the next character in the input stream and stores it in chm even if it is a space.

	cin.putback(char) lets you put the last characters obtained
	from the get() function back into the input stream.

	Program checks to see if the first charactere entered is a number 0 - 9

	Note: Only 1st character is checked. If invalid character
	occurs after 1st character, the program enters fail state
	and all other characters in the input stream are ignored.

*/

#include <iostream>
using namespace std;

int main() {
	int age = 0;
	char firstChar = ' ';
	bool good = false;

	while (!good) {
		cout << "Enter age: ";
		cin.get(firstChar);

		// Note: ACSII between 48 and 57 are digits 0-9

		if ((int)firstChar >= 48 && (int)firstChar <= 57) {
			good = true;
			cin.putback(firstChar);

			// can read it in with cin

			cin >> age;
		} else {
			cin.ignore(80, '\n');
		}
	}

	cout << "Your age is: " << age << endl;

	return 0;
}