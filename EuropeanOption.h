#ifndef EUROPEANOPTION_H
#define EUROPEANOPTION_H
#include "AbstractOption.h"
#include "CRR.h"
class EuropeanOption: public AbstractOption
{
public:
// Constructors : 
	EuropeanOption();
	EuropeanOption(double r, double sigma, double K, double T, double S, double b, typeOption type);
	
// Other Methods : 
// Payoff : 
	virtual double Payoff(double underlyingValue);
	virtual double IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp);
// Pricing of European Options from CRR
	double EuropeanPricingFromCRR(CRR crr);
	
// Option Pricing :
	//virtual double ComputationOptionPrice(int N);
	
// Destructor : 
	~EuropeanOption();

};

#endif // EUROPEANOPTION_H
