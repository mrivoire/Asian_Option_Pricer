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
	cout << "------ AMERICAN OPTION ------" << endl;
	//AbstractOption* optionA = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	AmericanOption* optionA = new AmericanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	CRR crrA((AbstractOption*)optionA, 2);
	crrA.FillUnderlyingValue();
	crrA.CRRPricing();
	crrA.binlattice.Display();
	
	cout << "------ Eruopean OPTION ------" << endl;
	EuropeanOption* optionE = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	CRR crrE((AbstractOption*)optionE, 2);
	crrE.FillUnderlyingValue();
	crrE.CRRPricing();
	cout << "Racine CRR " << optionE->EuropeanPricingFromCRR(crrE) << endl;
	//((EuropeanOption*)p_abstract_optionE)->EuropeanPricingFromCRR(crrE);
	//crr.binlattice.Display();
	
	cout << "------ Asian OPTION ------" << endl;
	int nbVal = 5;
	double* maturValues = (double*) malloc (sizeof(double)*nbVal);
	for (int i=0; i<nbVal; i++){
		maturValues[i] = i;
	}
	AsianOption* optionas = new AsianOption(0.05, 0.3, 36, 1, 35, 0.5, nbVal, maturValues, typeOption::call);
	BlackScholes bs;
	bs.nbRandomPaths = 5;
	bs.option = (AbstractOption*)optionas; 
	bs.GenericGenerationRandomPathsUnderlyingPrices();
	cout << "BS " << bs.GenericComputationOptionPrice() << endl;
	system("pause");
	return 0;
}
