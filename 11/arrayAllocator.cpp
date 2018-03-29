#include <string>
#include <iostream>

using namespace std;

int* allocator1(int size) {
	int *array = new int[size];
	return array;
}

int main() {
	int size;
	cout << "Size: ";
	cin >> size;

	int* array = allocator1(size);
	cout << "The array has been " << ((array == NULL) ? "un" : "") << "successfully initialized" << endl; 
}