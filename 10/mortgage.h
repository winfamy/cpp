#include <string>

using namespace std;

class Mortgage {
	public:
		Mortgage();
		Mortgage(const Mortgage&);
		Mortgage(double, double, int);
		double getPayment();
		double getLoan();
		double getRate();
		int getYears();
		void setPayment(double);
		void setLoan(double);
		void setRate(double);
		void setYears(int);
		float fetchMonthlyPayment();
		float fetchTotalPaid();
	private:
		double payment;
		double loan;
		double rate;
		int years;
};