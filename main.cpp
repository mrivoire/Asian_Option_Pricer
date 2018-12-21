#include <stdio.h>
#include "AbstractOption.h"
#include "EuropeanOption.h"
#include "AsianOption.h"
#include "AmericanOption.h"
#include "BlackScholes.h"
#include "CRR.h"

using namespace std;
int main(int argc, char **argv)
{
	cout << "------ ABSTRACT OPTION ------" <<endl;
	//AbstractOption* option = new AbstractOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	
	cout << "------ AMERICAN OPTION ------" << endl;
	//AbstractOption* optionA = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	AmericanOption* optionA = new AmericanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	CRR crrA((AbstractOption*)optionA, 2);
	crrA.FillUnderlyingValue();
	crrA.CRRPricing();
	crrA.binlattice.Display();
	
	cout << "------ EUROPEAN OPTION ------" << endl;
	EuropeanOption* optionE = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	
	cout << "PRICING WITH BLACK SCHOLES METHOD" << endl;
	
	
	cout << "PRICING WITH CRR METHOD" << endl;
	CRR crrE((AbstractOption*)optionE, 2);
	crrE.FillUnderlyingValue();
	crrE.CRRPricing();
	cout << "European Option Price : " << optionE->EuropeanPricingFromCRR(crrE) << endl;
	//((EuropeanOption*)p_abstract_optionE)->EuropeanPricingFromCRR(crrE);
	//crr.binlattice.Display();
	
	cout << "------ ASIAN OPTION ------" << endl;
	int nbVal = 5;
	double* maturValues = (double*) malloc (sizeof(double)*nbVal);
	for (int i=0; i<nbVal; i++){
		maturValues[i] = i;
	}
	BlackScholes bs;
	//srand(time(NULL));
	srand(0);
	//maturValues = bs.TimeGeneration(10,1,2);
	AsianOption* optionas = new AsianOption(0.05, 0.3, 36, 1, 35, 0.5, nbVal, maturValues, typeOption::call);
	bs.nbRandomPaths = 500;
	bs.option = (AbstractOption*)optionas;
	//bs.GenericGenerationRandomPathsUnderlyingPrices();
	double test = bs.GenericComputationOptionPrice();
	cout << "BS : " << test << endl;
	
	system("pause");
	return 0;
	// nb tirages dans monte-carlo 10 000 
	// durées en années : diviser par 365
}
