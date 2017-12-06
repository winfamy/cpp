#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

char cardsDown[4][4];	// array of stars, changes when user picks a card
char cardsUp[4][4];		// array of special characters
int randArray[8];		// used by setCards()
bool over = false;		// whether or not game is over(all matches have been found)
int moves = 0;			// number of moves
int clear = 0;			// keeps track of the number of matches made

void printOut(char [4][4]);	// print out cardsDown each time
void move();				// asks user which cards to pick
							// keeps track of matches and moves
void setCards();			// initializes cards (partially done for you)

int main() {
	srand((unsigned)time(NULL));
	// initialize game(call setCards and set over, moves, and clear to default values)
	// keep printing out cards and making a move until all matches are found
	// Tell the user how many moves they won in
	setCards();

	printOut(cardsUp);
	sleep(10);
	system("clear");

	while (!over) {
		printOut(cardsDown);
		move();
	}

	cout << "You won in " << moves << " moves.";
	return 0;
}


void printOut(char a[4][4]) {
	//Clear the screen and print -------Memory-------
	system("clear");
	cout << "-------Memory-------" << endl;
	//print column numbers
	cout << "  0 1 2 3" << endl;
	//print row numbers and each element of cardsDown (a nested loop)
	for (int i = 0; i < 4; i++) {
		cout << i << " ";
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move() {
	int aGuessRow = -1;
	int aGuessCol = -1;
	int bGuessRow = -1;
	int bGuessCol = -1;

	while (aGuessRow == -1) {
		cout << "Row: ";
		cin >> aGuessRow;

		if (aGuessRow < 0) {
			cout << "\tRow < 0" << endl;
			aGuessRow = -1;
		} else if (aGuessRow > 3) {
			cout << "\tRow > 3" << endl;
			aGuessRow = -1;
		}

		for(int i = 0; i < 4; i++) {
			if (cardsDown[aGuessRow][i] == '*')
				break;
			if (i == 3) {
				cout << "\tRow already solved" << endl;
				aGuessRow = -1;
			}
		}
	}

	while (aGuessCol == -1) {
		cout << "Col: ";
		cin >> aGuessCol;

		if (aGuessCol < 0) {
			cout << "\tCol < 0" << endl;
			aGuessCol = -1;
		} else if (aGuessCol > 3) {
			cout << "\tCol > 3" << endl;
			aGuessCol = -1;
		}

		if (cardsDown[aGuessRow][aGuessCol] != '*') {
			cout << "\tCol solved" << endl;
			aGuessCol = -1;
		}
	}

	cardsDown[aGuessRow][aGuessCol] = cardsUp[aGuessRow][aGuessCol];
	cout << cardsUp[aGuessRow][aGuessCol] << endl;

	while (bGuessRow == -1) {
		cout << "Row: ";
		cin >> bGuessRow;

		if (bGuessRow < 0) {
			cout << "\tRow < 0" << endl;
			bGuessRow = -1;
		} else if (bGuessRow > 3) {
			cout << "\tRow > 3" << endl;
			bGuessRow = -1;
		}

		for(int i = 0; i < 4; i++) {
			if (cardsDown[bGuessRow][i] == '*')
				break;
			if (i == 3) {
				cout << "\tRow already solved" << endl;
				bGuessRow = -1;
			}
		}
	}

	while (bGuessCol == -1) {
		cout << "Col: ";
		cin >> bGuessCol;

		if (bGuessCol < 0) {
			cout << "\tRow < 0" << endl;
			bGuessCol = -1;
		} else if (bGuessCol > 3) {
			cout << "\tRow > 3" << endl;
			bGuessCol = -1;
		}

		if (cardsDown[bGuessRow][bGuessCol] != '*') {
			cout << "\tCol solved" << endl;
			bGuessCol = -1;
		}
	}

	moves++;
	if (cardsUp[aGuessRow][aGuessCol] == cardsUp[bGuessRow][bGuessCol]) {
		cout << "Found a match!" << endl;
		cardsDown[bGuessRow][bGuessCol] = cardsUp[bGuessRow][bGuessCol];
		clear += 2;
		if (clear == 16) {
			over = true;
		}
	} else {
		cout << "No match!" << endl;
		cardsDown[aGuessRow][aGuessCol] = '*';
		cardsDown[bGuessRow][bGuessCol] = '*';
	}

	sleep(2);
	// done // Ask user for row and column of first card to pick-error trap to make sure the card exists (use a while loop!)
	// set the correct element of b (the row and column the user chose) to the corresponding element of cardsUp and print out b
	// Ask user for row and column of second card to pick-error trap to make sure the card exists and isn't the same as the first card (use a while loop!)
	// set the correct element of b (the row and column the user chose) to the corresponding element of cardsUp and print out b
	// increase the number of moves
	// if both cards match, print "You got a match!", set the corresponding elements to spaces, increase clear by 2, call the Sleep function
	// if the cards don't match, print "No match!", set the corresponding elements to *'s and call the Sleep function
	// if clear=16, set over to true
}

void setCards()
{
	//this part fills cardsUp with characters
	//cardsUp part is done for you-don't touch it!!
	int randNum = 0;
	for(int r = 0; r < 8; r++)
		randArray[r] = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
				do {
					randNum=rand()%8;
				} while (randArray[randNum] > 1);

			cardsUp[i][j] = char(randNum+90);
			randArray[randNum]++;
		}
	}

	// fill cardsDown with *'s (nested loop)
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cardsDown[i][j] = '*';
		}
	}
}