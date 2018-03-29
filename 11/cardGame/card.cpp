#include "card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

struct CardValues {
	string face;
	int value;
};

const CardValues cards[] = {
	{"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, 
	{"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
	{"J", 10}, {"Q", 10}, {"K", 10}, {"A", 11}
};

const char suits[] = {
	'S', 'H', 'D', 'C'
};

Card::Card() {
	deal();
}

char Card::getSuit() {
	return suit;
}

string Card::getFace() {
	return face;
}

int Card::getValue() {
	return value;
}

void Card::setSuit(char s) {
	suit = s;
}

void Card::setFace(string f) {
	face = f;
}

void Card::setValue(int v) {
	value = v;
}

void Card::deal() {
	int cindex = (rand() % 13);
	int sindex = (rand() % 4);
	setSuit(suits[sindex]);
	setValue(cards[cindex].value);
	setFace(cards[cindex].face);
}

void Card::show() {
	cout << getFace() << " " << getSuit() << endl;
}