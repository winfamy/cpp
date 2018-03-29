#include <string>
#include <iostream>

using namespace std;

int main() {
	double one, two;
	double *ptr;

	ptr = &one;
	*ptr = 1.25;
	ptr = &two;
	*ptr = 2.5;

	cout << one << endl;
	cout << *ptr << endl;
}