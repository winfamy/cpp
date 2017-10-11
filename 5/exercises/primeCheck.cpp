#include <iostream>

using namespace std;

bool isPrime(int number);

bool isPrime(int64_t number) {
	if (number <= 1) {
		return false;
	} else if (number <= 3) {
		return true;
	} else if (number % 2 == 0 || number % 3 == 0) {
		return false;
	}

	int64_t i = 5;
	while (i*i <= number) {
		if (number % i == 0 || number % (i + 2) == 0) {
			return false;
		}

		i += 6;
	}

	return true;
}

int main() {
	int64_t num;
	cout << "Number: ";
	cin >> num;

	cout << num << ((isPrime(num)) ? " is " : " is not ") << "prime";

	return 0;
}