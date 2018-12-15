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

// Monte-Carlo Methods : 
// Estimation of the parameters required in Monte-Carlo and Riemann Methods
double AbstractOption::Computed1()
{
	double d1 = (log(S / K) + (r + 0.5*pow(sigma, 2)*(T))) / (sigma*sqrt(T));
	return(d1);
}

double AbstractOption::Computed2()
{
	double d1 = Computed1();
	double d2 = d1 - sigma * sqrt(T);
	return(d2);
}

double AbstractOption::EstimateNd_MonteCarlo(double d, int n)
{
	int nb_points_lower_d = 0;
	double estimate_Nd = 0;
	for (int i = 0; i < n; i++)
	{
		double s = 0;
		double x;
		double y;
		do
		{
			x = 1 - 2 * (rand() / (double)RAND_MAX);
			y = 1 - 2 * (rand() / (double)RAND_MAX);
			s = x * x + y * y;
		} while (s < 0 || s > 1);

		double z = x * sqrt(-2 * log(s) / s);
		if (z < d)
		{
			nb_points_lower_d++;
		}
	}
	estimate_Nd = ((double)nb_points_lower_d / n);
	return(estimate_Nd);
}

double AbstractOption::EstimateNd_RiemannLeft(double d, int n)
{
	double step = (0 - d) / n;
	double rectangleArea = 0;
	double LeftRiemannSum = 0;
	double EstimateNd = 0;
	for (int i = 0; i < n; i++)
	{
		rectangleArea = step * (1 / sqrt(2 * 3.14))*exp(-pow((d + i * step) - 0, 2) / (2 * pow(sigma, 2)));
		LeftRiemannSum = LeftRiemannSum + rectangleArea;
	}
	EstimateNd = 0.5 - LeftRiemannSum;
	//cout << EstimateNd << " pour d valant " << d << endl;
	return(EstimateNd);
}

double AbstractOption::EstimateNd_RiemannRight(double d, int n)
{
	double step = (0 - d) / n;
	double rectangleArea = 0;
	double RightRiemannSum = 0;
	double EstimateNd = 0;
	for (int i = 0; i < n; i++)
	{
		rectangleArea = step * (1 / sqrt(2 * 3.14))*exp(-pow((d + (i + 1) * step) - 0, 2) / (2 * pow(sigma, 2)));
		RightRiemannSum = RightRiemannSum + rectangleArea;
	}
	EstimateNd = 0.5 - RightRiemannSum;
	return(EstimateNd);
}

// Calculation of the Option Prices from the parameters estimated
double AbstractOption::ComputePriceOption(int n, string methodChoice)
{
	double d1 = Computed1();
	double d2 = Computed2();
	double price;
	if (methodChoice == "Monte-Carlo")
	{
		if (type == typeOption::call)
		{
			price = (S * EstimateNd_MonteCarlo(d1, n) - K * exp(-r * T)*EstimateNd_MonteCarlo(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (K * exp(-r * T)*EstimateNd_MonteCarlo(-d2, n) - S * EstimateNd_MonteCarlo(-d1, n));
			//cout << "put :" << price << endl;
		}
	}
	if (methodChoice == "Left Sum Riemann")
	{
		if (type == typeOption::call)
		{
			price = (S * EstimateNd_RiemannLeft(d1, n) - K * exp(-r * T)*EstimateNd_RiemannLeft(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (K * exp(-r * T)*EstimateNd_RiemannLeft(-d2, n) - S * EstimateNd_RiemannLeft(-d1, n));
			//cout << "put :" << price << endl;
		}
	}
	if (methodChoice == "Right Sum Riemann")
	{
		if (type == typeOption::call)
		{
			price = (S * EstimateNd_RiemannRight(d1, n) - K * exp(-r * T)*EstimateNd_RiemannRight(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (K * exp(-r * T)*EstimateNd_RiemannRight(-d2, n) - S * EstimateNd_RiemannRight(-d1, n));
			//cout << "put :" << price << endl;
		}
	}

	return(price);
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

