#include "card.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

Card* playerCards[21];
Card* dealerCards[21];
bool playerBust;
bool dealerBust;
bool playerDone;
bool dealerDone;
int playerIndex;
int dealerIndex;
bool playing;

void newGame() {
	system("clear");
	cout << 
		"$$$$$$$\\  $$\\        $$$$$$\\   $$$$$$\\  $$\\   $$\\   $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ " << '\n' << 
		"$$  __$$\\ $$ |      $$  __$$\\ $$  __$$\\ $$ | $$  |  \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |" << '\n' << 
		"$$ |  $$ |$$ |      $$ /  $$ |$$ /  \\__|$$ |$$  /      $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / " << '\n' << 
		"$$$$$$$\\ |$$ |      $$$$$$$$ |$$ |      $$$$$  /       $$ |$$$$$$$$ |$$ |      $$$$$  /  " << '\n' << 
		"$$  __$$\\ $$ |      $$  __$$ |$$ |      $$  $$<  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   " << '\n' << 
		"$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$\\ $$ |\\$$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  " << '\n' << 
		"$$$$$$$  |$$$$$$$$\\ $$ |  $$ |\\$$$$$$  |$$ | \\$$\\\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ " << '\n' << 
		"\\_______/ \\________|\\__|  \\__| \\______/ \\__|  \\__|\\______/ \\__|  \\__| \\______/ \\__|  \\__|" << '\n' << endl << endl;
	cout << "Welcome to Blackjack" << endl;
	cout << "Press enter to begin..." << endl;
	system("read");
	system("clear");

	playerBust = false;
	dealerBust = false;
	playerDone = false;
	dealerDone = false;
	playerIndex = 1;
	dealerIndex = 1;

	for (int i = 0; i < 21; i++) {
		delete playerCards[i];
		delete dealerCards[i];
	}

	playerCards[0] = new Card();
	playerCards[1] = new Card();
	dealerCards[0] = new Card();
	dealerCards[1] = new Card();
}

int getSum(string person) {
	int sum = 0;
	for (int i = 0; i < 21; i++) {
		if (person == "dealer") {
			if (dealerCards[i] != NULL) {
				sum += dealerCards[i]->getValue();
			}
		} else {
			if (playerCards[i] != NULL) {
				sum += playerCards[i]->getValue();
			}
		}
	}

	return sum;
}

void playPlayerHand() {
	char choice = 'x';
	system("clear");
	while (!playerBust && !playerDone) {
		cout << "Your cards: " << endl;
		for (int i = 0; i < 21; i++) {
			if (playerCards[i] != NULL) 
				playerCards[i]->show();
		}

		cout << "Your total: " << getSum("player") << endl;
		choice = 'x';
		while (choice == 'x') {
			cout << "Hit (Y/N): ";
			cin >> choice;
			switch (choice) {
				case 'Y':
				case 'y':
					playerCards[++playerIndex] = new Card();
					break;
				case 'N':
				case 'n':
					playerDone = true;
					break;
				default:
					cout << "Invalid choice" << endl;
					choice = 'x';
			}
		}

		if (getSum("player") > 21) {
			if (playerCards[playerIndex]->getValue() == 1) {
				playerCards[playerIndex]->setValue(1);
			} else {
				playerBust = true;
				cout << "You busted from a " << playerCards[playerIndex]->getFace() << "." << endl;
			}
		} else if (getSum("player") == 21) {
			playerDone = true;
			cout << "Blackjack! You got 21!" << endl;
		}
	}

	cout << "Press enter to continue..." << endl;
	system("read");
}

void playDealerHand() {
	system("clear");
	while(!dealerDone && !dealerBust) {
		if (getSum("dealer") < 18) {
			dealerCards[++dealerIndex] = new Card();
		}

		if (getSum("dealer") > 21) {
			dealerBust = true;
		} else if (getSum("dealer") >= 18) {
			dealerDone = true;
		}
	}

	cout << "Your total: " << getSum("player") << endl;
	cout << "Dealer's cards: " << endl;
	for (int i = 0; i < 21; i++) {
		if (dealerCards[i] != NULL) {
			dealerCards[i]->show();
		}
	}
	cout << "Dealer total: " << getSum("dealer") << endl;
}

int main() {
	srand(time(NULL));

	char choice;
	playing = true;
	while (playing) {
		newGame();
		playPlayerHand();
		playDealerHand();

		if (playerBust && dealerBust) {
			cout << "You tied! ";
		} else if ((playerBust && !dealerBust) || getSum("dealer") > getSum("player")) {
			cout << "You lost! :( ";	
		} else if ((!playerBust && dealerBust) || getSum("player") > getSum("dealer")) {
			cout << "You won! ";
		} else {
			cout << "You tied! ";
		}

		choice = 'x';
		while (choice == 'x') {
			cout << "Play again? (Y/N): ";
			cin >> choice;
			switch (choice) {
				case 'Y':
				case 'y':
					break;
				case 'N':
				case 'n':
					playing = false;
					break;
				default:
					cout << "Invalid choice" << endl;
					choice = 'x';
			}
		}
	}
}