#include <iostream>

using namespace std;

int main() {
	int n = 3;
	while (n >= 0) {
		cout << n*n << endl;
		n--;
	}
	cout << n << endl;
	while (n < 4 ) {
		n++;
		cout << n << endl;
	}

	cout << n << endl;
	while (n >= 1)
		cout << (n /= 2) << endl;
	return 0;
}