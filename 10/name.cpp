#include "name.h"
#include <string>
#include <iostream>

using namespace std;

name::name () {
	first 	= "Grady";
	middle 	= "Lachlan";
	last 	= "Phillips";
}

name::name (const name& n) {
	first 	= n.first;
	middle 	= n.middle;
	last 	= n.last;
}

name::name (string f, string m, string l) {
	first 	= f;
	middle 	= m;
	last 	= l;
}

string name::getFirst() {
	return first;
}

string name::getMiddle() {
	return middle;
}

string name::getLast() {
	return last;
}

void name::setFirst(string f) {
	first = f;
}

void name::setMiddle(string m) {
	middle = m;
}

void name::setLast(string l) {
	last = l;
}

void name::displayName() {
	cout << first << " " << middle << " " << last << endl;
}

void name::marry(string lastName) {
	setLast(lastName);
	cout << "New name: ";
	displayName();
	cout << endl;
}

void name::displayInvert() {
	cout << last << ", " << first << endl;
}

int main() {
	name myName = name("Grady", "Lachlan", "Phillips");
	myName.displayName();
	myName.marry("Otherlastname");
	myName.displayInvert();

	return 0;
}