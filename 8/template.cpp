#include <string>
#include <iostream>

using namespace std;

template <class Type, int length>
Type getMin(Type a[length]) {
	Type min = a[0];

	for(int i = 0; i < length; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}

	return min;
}

template <class Type, int length>
void printArray(Type a[length]) {
	cout << "(";
	for (int i = 0; i < length; i++) {
		//cout << i;
		if (i == length - 1)
			cout << a[i];
		else
			cout << a[i] << ", ";
	}
	cout << ")" << endl;
}

int main() {
	int intArray[15] = {7,8,-9,5,6,-8,3,5,4,2,3,5,6,8,4};
	double doubleArray[15] = {7.32,8.12,-9.51,5.14,6.87,-8.98,3.34,5.43,4.23,2.2,3.2,5.2,6.2,.8,.4};
	string stringArray[15] = {"Grady","potato","idk","random","str","aaaa","lol","Aafa","hey there","abc","=3=","c++","string","another","string"};


	printArray<int, 15>(intArray);
	cout << "getMin<int>: " << getMin<int, 15>(intArray) << endl << endl;
	printArray<double, 15>(doubleArray);
	cout << "getMin<double>: " << getMin<double, 15>(doubleArray) << endl << endl;
	printArray<string, 15>(stringArray);
	cout << "getMin<string>: " << getMin<string, 15>(stringArray) << endl << endl;



	return 0;
}