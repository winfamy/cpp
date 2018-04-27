#include <iostream>
#include <string>

using namespace std;

struct dog {
	char name[20];
	string breed;
	int age;
	dog * next;
};

int main() {
	dog* elvis = new dog;
	dog* A = new dog;
	dog* B = new dog;
	*A = *B;
}