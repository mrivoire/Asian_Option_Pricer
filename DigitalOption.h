#ifndef DIGITALOPTION_H
#define DIGITALOPTION_H
#include "AbstractOption.h"
class DigitalOption: public AbstractOption
{
public:
// Constructors : 
	DigitalOption();
	DigitalOption(double r, double sigma, double K, double T, double S, double b, typeOption type);

// Other Methods :
	virtual double Payoff(double* underlyingValue, int nbUnderlyingValue);
	virtual double GetNbMaturities();
	virtual double* GetMaturitiesCollection();
// Destructor :
	~DigitalOption();

};

#endif // DIGITALOPTION_H
