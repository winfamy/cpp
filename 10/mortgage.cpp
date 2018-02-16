#include "mortgage.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Mortgage::Mortgage () {
	payment = 0;
	rate = 0;
	loan = 0;
	years = 0;
}

Mortgage::Mortgage (const Mortgage &m) {
	payment = m.payment;
	rate = m.rate;
	loan = m.loan;
	years = m.years;
}

Mortgage::Mortgage (double r, double l, int y) {
	rate = r;
	loan = l;
	years = y;
}

double Mortgage::getPayment() 	{ return payment; }
double Mortgage::getRate() 		{ return rate; }
double Mortgage::getLoan() 		{ return loan; }
int Mortgage::getYears() 		{ return years; }
void Mortgage::setPayment(double p) { payment = p; }
void Mortgage::setRate(double r) 	{ rate = r; }
void Mortgage::setLoan(double l) 	{ loan = l; }
void Mortgage::setYears(int y) 		{ years = y; }

float Mortgage::fetchMonthlyPayment() {
	float term = pow((1+rate/12), (12*years));
	return (loan*rate/12.0*term)/(term-1.0);
}

float Mortgage::fetchTotalPaid() {
	return fetchMonthlyPayment()*12*years;
}

int main() {
	double r, l;
	int y;

	cout << "Enter loan: ";
	cin >> l;
	cout << "Enter rate: ";
	cin >> r;
	cout << "Enter years: ";
	cin >> y;

	cout << l << " " << r << " " << y << endl;

	Mortgage myHouseMortgage = Mortgage(r, l, y);
	cout << "Your payment: " << myHouseMortgage.fetchMonthlyPayment() << endl;
	cout << "Your total paid: " << myHouseMortgage.fetchTotalPaid() << endl;

	return 0;
}