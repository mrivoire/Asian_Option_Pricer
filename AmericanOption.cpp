#include "AmericanOption.h"

AmericanOption::AmericanOption()
{
}

AmericanOption::AmericanOption(double r, double sigma, double K, double T, double S, double b, typeOption type) :AbstractOption(r, sigma, K, T, S, b, type)
{
}

double AmericanOption::IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp){
	return max(UpdatePrice, PayOffTemp);
}

double AmericanOption::Payoff(double underlyingValue)
{
	double payoff = 0;
	if (type == typeOption::call)
	{
		//cout << "The option is a call : " << endl;
		if (underlyingValue - K > 0)
		{
			payoff = underlyingValue - K;
			//cout << "payoff : " << payoff << endl;
		}
		else
		{
			payoff = 0;
			//cout << "payoff : " << payoff << endl;
		}
	}
	else
	{
		//cout << "The option is a put : " << endl;
		if (K - underlyingValue > 0)
		{
			payoff = K - underlyingValue;
			//cout << "payoff : " << payoff << endl;
		}
		else
		{
			payoff = 0;
			//cout << "payoff : " << payoff << endl;
		}
	}
	return(payoff);
}

double AmericanOption::AmericanPricingFromCRR(CRR crr, int ligne, int column)
{
	BinLatticeNode node = crr.binlattice.Lattice[ligne][column];
	double americanOptionPrice = node.updatePrice;
	return(americanOptionPrice);
}

AmericanOption::~AmericanOption()
{
}

