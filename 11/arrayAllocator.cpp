#include <string>
#include <iostream>

using namespace std;

int main() {
	int size;
	cout << "Size: ";
	cin >> size;

	int *array = new int[size];
	cout << "The array has been " << ((array == NULL) ? "un" : "") << "successfully initialized" << endl; 
}