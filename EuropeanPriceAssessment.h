#ifndef EUROPEANPRICEASSESSMENT_H
#define EUROPEANPRICEASSESSMENT_H
#include <string>
#include "AbstractOption.h"
#include "EuropeanOption.h"
using namespace std;

class EuropeanPriceAssessment
{
public:
// Constructors :
	EuropeanPriceAssessment();
	
// Other Methods :
	double Computed1();
	double Computed2();
	double EstimateNd_MonteCarlo(double d, int n);
	double EstimateNd_RiemannLeft(double d, int n);
	double EstimateNd_RiemannRight(double d, int n);
	double ComputePriceOption(int n, string methodChoice);
	
// Destructors : 
	~EuropeanPriceAssessment();
// Attributes : 
EuropeanOption* option;
};

#endif // EUROPEANPRICEASSESSMENT_H
