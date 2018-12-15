#include "DigitalOption.h"

DigitalOption::DigitalOption()
{
}

DigitalOption::DigitalOption(double r, double sigma, double K, double T, double S, double b, typeOption type) :AbstractOption(r, sigma, K, T, S, b, type)
{

}

double DigitalOption::Payoff(double* underlyingValue, int nbUnderlyingValue)
{
	double payoff = 0;
	if (type == typeOption::call)
	{
		if (K < underlyingValue[0])
		{
			payoff = 1;
		}
		else
		{
			payoff = 0;
		}
	}
	else
	{
		if (K < underlyingValue[0])
		{
			payoff = 0;
		}
		else
		{
			payoff = 1;
		}
	}
	return(payoff);
}

double DigitalOption::GetNbMaturities()
{
	return 1;
}

double* DigitalOption::GetMaturitiesCollection()
{
	return &T;
}

DigitalOption::~DigitalOption()
{
}

