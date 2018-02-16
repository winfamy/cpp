#include <string>

using namespace std;

class Mortgage {
	public:
		Mortgage();
		Mortgage(const Mortgage &m);
		Mortgage(double, double, double, int);
	private:
		double payment;
		double loan;
		double rate;
		int years;
};