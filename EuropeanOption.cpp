#include "EuropeanOption.h"

EuropeanOption::EuropeanOption()
{
}

EuropeanOption::EuropeanOption(double r, double sigma, double K, double T, double S, double b, typeOption type) :AbstractOption(r, sigma, K, T, S, b, type)
{

}

double EuropeanOption::IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp){
	return UpdatePrice;
}
double EuropeanOption::Payoff(double* underlyingValue, int nbUnderlyingValue)
{
	double payoff = 0;
	if (type == typeOption::call)
	{
		//cout << "The option is a call : " << endl;
		if (underlyingValue[0] - K > 0)
		{
			payoff = underlyingValue[0] - K;
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
		if (K - underlyingValue[0] > 0)
		{
			payoff = K - underlyingValue[0];
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

double EuropeanOption::GetNbMaturities()
{
	return 1;
}
double* EuropeanOption::GetMaturitiesCollection()
{
	return &T;
}
double EuropeanOption::EuropeanPricingFromCRR(CRR crr)
{
	BinLatticeNode firstNodeCRR = crr.GetFirstNode();
	double europeanOptionPrice = firstNodeCRR.updatePrice;
	return(europeanOptionPrice);
	
	//return crr.GetFirstNode().updatePrice;
}

EuropeanOption::~EuropeanOption()
{
}

