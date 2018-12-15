#ifndef ASIANOPTION_H
#define ASIANOPTION_H
#include "AbstractOption.h"
using namespace std;

class AsianOption:public AbstractOption
{
public:
// Constructors : 
	AsianOption();
	AsianOption(double r, double sigma, double K, double T, double S, double b, int nbUnderlyingValues, double * residualMaturities, typeOption type);
	
// Getters : 
	int GetNbUnderlyingValues();
	double* GetUnderlyingCollection();
	double* GetResidualMaturities();
	
// Setters : 
	void SetNbUnderlyingValues(int newNbUnderlyingValues);
	void SetUnderlyingCollection(double* newUnderlyingCollection);
	void SetResidualMaturities(double* newResidualMaturities);

// Other Methods :
	virtual double Payoff(double* underlyingValue, int nbUnderlyingValue);// = 0, double * underlyingCollection = NULL);
	virtual double GetNbMaturities();
	virtual double* GetMaturitiesCollection();
	
// Destructor :
	~AsianOption();
	
public:
// Attributes :
	int nbUnderlyingValues;
	double* underlyingCollection;
	double* residualMaturities;

};

#endif // ASIANOPTION_H
