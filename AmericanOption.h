#ifndef AMERICANOPTION_H
#define AMERICANOPTION_H
#include "AbstractOption.h"
#include "CRR.h"
using namespace std;

class AmericanOption: public AbstractOption
{
public:
// Constructors : 
	AmericanOption();
	AmericanOption(double r, double sigma, double K, double T, double S, double b, typeOption type);
	
// Other Methods : 
	virtual double Payoff(double underlyingValue);
	virtual double IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp);
// Pricing of American Options from CRR 
	double AmericanPricingFromCRR(CRR crr, int line, int column);
	
// Destructor :
	~AmericanOption();

};

#endif // AMERICANOPTION_H
