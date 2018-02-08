#include <iostream>
#include <string>

using namespace std;

struct A {
	string kms;
};

struct B {
	string kms;
};

int main() {
	A test;
	B alsoTest;
	A alsoalsoTest;

	test.kms = "aa";
	alsoalsoTest = test;
	return 0;
}