#include <string>

using namespace std;

class Card {
	public:
		Card();
		char getSuit();
		string getFace();
		int getValue();
		void setSuit(char s);
		void setFace(string f);
		void setValue(int v);
		void deal();
		void show();
	private:
		char suit;
		string face;
		int value;
};