#include "DigitalOption.h"

DigitalOption::DigitalOption()
{
}

DigitalOption::DigitalOption(double r, double sigma, double K, double T, double S, double b, typeOption type) :AbstractOption(r, sigma, K, T, S, b, type)
{

}

double DigitalOption::Payoff(double underlyingValue)
{
	double payoff = 0;
	if (type == typeOption::call)
	{
		if (K < underlyingValue)
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
		if (K < underlyingValue)
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

double DigitalOption::ComputationOptionPrice(int n)
{
	double t_k[1];
	t_k[0] = T;
	return this->GenericComputationOptionPrice(1, n, t_k);
}

DigitalOption::~DigitalOption()
{
}

