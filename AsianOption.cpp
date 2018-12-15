#include "AsianOption.h"

AsianOption::AsianOption()
{
}

AsianOption::AsianOption(double r, double sigma, double K, double T, double S, double b, int _nbUnderlyingValues, double* _residualMaturities, typeOption type):AbstractOption(r, sigma, K, T, S, b, type)
{
	nbUnderlyingValues = _nbUnderlyingValues;
	residualMaturities = _residualMaturities;
}

int AsianOption::GetNbUnderlyingValues()
{
	return(nbUnderlyingValues);
}

double* AsianOption::GetUnderlyingCollection()
{
	return(underlyingCollection);
}

double* AsianOption::GetResidualMaturities()
{
	return(residualMaturities);
}

// Setters : 
void AsianOption::SetNbUnderlyingValues(int newNbUnderlyingValues)
{
	nbUnderlyingValues = newNbUnderlyingValues;
}

void AsianOption::SetUnderlyingCollection(double* newUnderlyingCollection)
{
	underlyingCollection = newUnderlyingCollection;
}

void AsianOption::SetResidualMaturities(double* newResidualMaturities)
{
	residualMaturities = newResidualMaturities;
}

double AsianOption::Payoff(double* underlyingValue, int nbUnderlyingValue)
{
	int m = nbUnderlyingValues;
	double payoff = 0;
	double meanUnderlyingValues = 0;
	for (int i = 0; i < m; i++)
	{
		meanUnderlyingValues = meanUnderlyingValues + underlyingValue[i];
	}
	meanUnderlyingValues = meanUnderlyingValues / m;
	if (type == typeOption::call)
	{
		if (meanUnderlyingValues - K > 0)
		{
			payoff = meanUnderlyingValues - K;
		}
		else
		{
			payoff = 0;
		}
	}
	else
	{
		if (meanUnderlyingValues - K > 0)
		{
			payoff = K - meanUnderlyingValues;
		}
		else
		{
			payoff = 0;
		}
	}
	return(payoff);
}

double AsianOption::GetNbMaturities()
{
	return nbUnderlyingValues;
}

double* AsianOption::GetMaturitiesCollection()
{
	return residualMaturities;
}

AsianOption::~AsianOption()
{
}

