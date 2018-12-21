#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H
#include <iostream>
#include "AbstractOption.h"
#include "AsianOption.h"
#include "EuropeanOption.h"
using namespace std;

class BlackScholes
{
public:
// Constructors :
	BlackScholes();
	
// Other Methods :
	double * TimeGeneration(int nbIterations, int init, int end); // h = pas de hachage ou de discrétisation
	double GenericGenerationRandomPathsUnderlyingPrices();
	double GenericComputationOptionPrice();
	
// Destructors : 
	~BlackScholes();
	
// Attributes : 
AbstractOption* option;
int nbRandomPaths; 
};

#endif // BLACKSCHOLES_H
