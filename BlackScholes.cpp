#include "BlackScholes.h"
#include <math.h>
BlackScholes::BlackScholes()
{
}

// Options Pricer by Random Path Generation : Monte-Carlo Methods and Wiener Process
double * BlackScholes::TimeGeneration(int nbIterations, int init, int end)
{
	double h = (end - init) / nbIterations;
	double * residualMaturities = (double*)malloc(((end - init)/h + 1)*sizeof(double));
	for (int i = init; i < end; i++)
	{
		residualMaturities[i] = init + i * h;
	}
	return(residualMaturities);
}

double BlackScholes::GenericGenerationRandomPathsUnderlyingPrices()
{
	int m = option->GetNbMaturities();
	double * t_k = option->GetMaturitiesCollection();
	double * z_k = (double*)malloc(m * sizeof(double));
	double s = 0;
	double x = 0;
	double y = 0;
	double z = 0;
	double * s_k = (double*)malloc(m * sizeof(double));
//	double * payoff_k = (double*)malloc(m * sizeof(double));
	for (int i = 0; i < m; i++)
	{
		do
		{
			x = 1 - 2 * (rand() / (double)RAND_MAX);
			y = 1 - 2 * (rand() / (double)RAND_MAX);
			s = x * x + y * y;
		} while (s <= 0 || s > 1);

		z = x * sqrt(-2 * log(s) / s);
		z_k[i] = z; // Contient les variables aléatoires gaussiennes permettant de calculer les valeurs du sous-jacent à différentes dates t_k 
	}

	double underlying_k = 0;
	s_k[0] = option->S;
	double payoff = 0;

	for (int i = 1; i < m; i++)
	{
		underlying_k = s_k[i - 1] * exp((option->r - pow(option->sigma, 2) / 2)*(t_k[i] - t_k[i - 1]) + option->sigma * sqrt(t_k[i] - t_k[i - 1])*z_k[i]);
		//z=t_k[i] - t_k[i - 1];
		s_k[i] = underlying_k;
	}

	payoff = option->Payoff(s_k,m);
	cout << payoff << " " ;
	cout << "Random Paths Generation : " << endl;
	cout << endl;
	for (int l=0; l<m; l++){
		cout << t_k[l] << "/" << z_k[l] << "/" << s_k[l] << " -- ";
	}
	cout << endl;
	/*for (int l=0; l<m; l++){
		cout << z_k[l] << endl;
	}*/
	return(payoff);
}

double BlackScholes::GenericComputationOptionPrice()
{
	double payoff_k = 0;
	double sumPayoff = 0;
	double meanPayoff = 0;
	double optionPrice = 0;
	for (int i = 1; i < nbRandomPaths; i++)
	{
		payoff_k = GenericGenerationRandomPathsUnderlyingPrices();
		sumPayoff = sumPayoff + payoff_k;
	}
	meanPayoff = sumPayoff / nbRandomPaths;
	optionPrice = exp(-option->r * option->T)*meanPayoff;
	return(optionPrice);
}


BlackScholes::~BlackScholes()
{
}

