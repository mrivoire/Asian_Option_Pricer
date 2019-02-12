#include <stdio.h>
#include "AbstractOption.h"
#include "EuropeanOption.h"
#include "AsianOption.h"
#include "AmericanOption.h"
#include "BlackScholes.h"
#include "CRR.h"
#include "EuropeanPriceAssessment.h"
#include <string>
using namespace std;
int main(int argc, char **argv)
{	
	cout<< "------ PARAMETERS ------" << endl;
	double interestRate = 0.03;//0.05;
	double volatility = 0.05;//0.3;
	double strike = 1800; //36;
	double maturity = 1;
	double underlying = 1800; //35;
	double constb = 3; //0.5;
	typeOption type = typeOption::call;
	
	cout << endl;
	cout << "Option Properties : " << endl;
	cout << "Interest Rate : " << interestRate << endl;
	cout << "Volatility :" << volatility << endl;
	cout << "Strike : " << strike << endl;
	cout << "Maturity :" << maturity << endl;
	cout << "Underlying Value : " << underlying << endl;
	cout << "Constant b : " << constb << endl;
	
	cout << endl;
	double nbIterations = 10000;
	string assessmentMethod1 = "Monte-Carlo";
	string assessmentMethod2 = "Left Sum Riemann";
	string assessmentMethod3 = "Right Sum Riemann";
	
	cout << endl;
	cout << "Iterations Number : " << nbIterations << endl;
	cout << "Assessment Method 1 : " << assessmentMethod1 << endl;
	cout << "Assessment Method 2 : " << assessmentMethod2 << endl;
	cout << "Assessment Method 3 : " << assessmentMethod3 << endl;
	
	cout << endl;
	int crrDepth = 2;
	cout << "CRR Tree Depth : " << crrDepth << endl;
	
	cout << endl;
	int nbVal = 5;
	cout << "Number of Maturity Values : " << nbVal << endl;
	double* maturValues = (double*) malloc (sizeof(double)*nbVal);
	for (int i=0; i<nbVal; i++){
		maturValues[i] = i;
	}
	
	cout << endl;
	cout << "------ EUROPEAN OPTION ------" << endl;
	EuropeanOption* optionE = new EuropeanOption(interestRate, volatility, strike, maturity, underlying, constb, type);
	// CRR appliqué à européenne et méthodes de monte-carlo et riemann
	
	cout << endl;
	cout << "PRICING WITH BLACK SCHOLES METHOD" << endl;
	EuropeanPriceAssessment euroAssess;
	euroAssess.option = optionE;
	double euroPriceByMonteCarlo = euroAssess.ComputePriceOption(nbIterations, assessmentMethod1);
	cout << "European Price By Monte-Carlo :" << euroPriceByMonteCarlo << endl;
	double euroPriceByRiemannLeft = euroAssess.ComputePriceOption(nbIterations, assessmentMethod2);
	cout << "European Price By Riemann Left :" << euroPriceByRiemannLeft << endl;
	double euroPriceByRiemannRight = euroAssess.ComputePriceOption(nbIterations, assessmentMethod3);
	cout << "European Price By Riemann Right :" << euroPriceByRiemannRight << endl;
	
	cout << endl;
	cout << "PRICING WITH CRR METHOD" << endl;
	CRR crrE((AbstractOption*)optionE, 2);
	crrE.FillUnderlyingValue();
	crrE.CRRPricing();
	cout << "European Option Price : " << optionE->EuropeanPricingFromCRR(crrE) << endl;
	//((EuropeanOption*)p_abstract_optionE)->EuropeanPricingFromCRR(crrE);
	//crr.binlattice.Display();
	
	cout << endl;
	cout << "------ AMERICAN OPTION ------" << endl;
	cout << endl;
	cout << "Pricing With Cox Ross Rubinstein (CRR) Method / Binomial Tree Method : " << endl;
	AmericanOption* optionA = new AmericanOption(interestRate, volatility, strike, maturity, underlying, constb, type);
	CRR crrA((AbstractOption*)optionA, crrDepth);
	crrA.FillUnderlyingValue();
	crrA.CRRPricing();
	crrA.binlattice.Display();
	
	cout << endl;
	cout << "------ ASIAN OPTION ------" << endl;
	cout << "Pricing With Wiener Process : " << endl;
	cout << endl;
	BlackScholes bs;
	//srand(time(NULL));
	srand(0);
	//maturValues = bs.TimeGeneration(10,1,2);
	AsianOption* optionas = new AsianOption(interestRate, volatility, strike, maturity, underlying, constb, nbVal, maturValues, type);
	bs.nbRandomPaths = 500;
	bs.option = (AbstractOption*)optionas;
	//bs.GenericGenerationRandomPathsUnderlyingPrices();
	double test = bs.GenericComputationOptionPrice();
	cout << endl;
	cout << "Asian Option Price : " << test << endl;
	
	system("pause");
	return 0;
	// nb tirages dans monte-carlo 10 000 
	// durées en années : diviser par 365
}
