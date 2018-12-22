#include "AbstractOption.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std; 
AbstractOption::AbstractOption()
{
}

AbstractOption::AbstractOption(double _r, double _sigma, double _K, double _T, double _S, double _b, typeOption _type)
{
	r = _r;
	sigma = _sigma;
	K = _K;
	T = _T;
	S = _S;
	b = _b;
	type = _type;
}

AbstractOption::AbstractOption(const AbstractOption& o)
{
	r = o.r;
	sigma = o.sigma;
	K = o.K;
	T = o.T;
	S = o.S;
	b = o.b;
}

// Getters :
double AbstractOption::GetSigma()
{
	return(sigma);
}

double AbstractOption::GetK()
{
	return(K);
}

double AbstractOption::GetS()
{
	return(S);
}

double AbstractOption::GetT()
{
	return(T);
}

double AbstractOption::Getr()
{
	return(r);
}

double AbstractOption::Getb()
{
	return(b);
}

// Setters : 
void AbstractOption::SetSigma(double newSigma)
{
	sigma = newSigma;
}

void AbstractOption::SetK(double newK)
{
	K = newK;
}

void AbstractOption::SetS(double newS)
{
	S = newS;
}

void AbstractOption::SetT(double newT)
{
	T = newT;
}

void AbstractOption::Setr(double newr)
{
	r = newr;
}

void AbstractOption::Setb(double newb)
{
	b = newb;
}

// Display of an option characteristics 
std::ostream& operator<<(std::ostream &strm, const AbstractOption& option)
{
	string optionType = "Call";
	if (option.type == typeOption::call) {
		optionType = "Call";
	}
	else 
	{
		optionType = "Put";
	}
	return strm << "Option : \nS (Stock Price) :\t" << option.S << "\nK (Exercice Price) :\t" << option.K << "\nsigma (Volatility) :\t" << option.sigma << "\nr (Interest Rate) :\t" << option.r << "\nT (Time To Maturity) :\t" << option.T << "\ntype :\t" << optionType << endl;
}

AbstractOption::~AbstractOption()
{
}

