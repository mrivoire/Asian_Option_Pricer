#ifndef ABSTRACTOPTION_H
#define ABSTRACTOPTION_H
#include <string>
using namespace std;
enum class typeOption{call, put};
class AbstractOption
{
public:

// Constructors : 
	AbstractOption();
	AbstractOption(double r, double sigma, double K, double T, double S, double b, typeOption type);
	AbstractOption(const AbstractOption& option);
	
// Getters : 
double GetSigma();
double GetK();
double GetS();
double GetT();
double Getr();
double Getb();

// Setters : 
void SetSigma(double newSigma);
void SetK(double newK);
void SetS(double newS);
void SetT(double newT);
void Setr(double newr);
void Setb(double newb);

// Other Methods : 
// Monte-Carlo / Riemann Method : 
	double Computed1();
	double Computed2();
	double EstimateNd_MonteCarlo(double d, int n);
	double EstimateNd_RiemannLeft(double d, int n);
	double EstimateNd_RiemannRight(double d, int n);
	double ComputePriceOption(int n, string methodChoice);
	
// Payoff : 
	virtual double Payoff(double underlyingValue) = 0;
	virtual double IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp) = 0;

// Pricing by Random Paths Generation : Monte-Carlo Method and Wiener Process
	double * TimeGeneration(int nbIterations, double init, double end); // h = pas de hachage ou de discrétisation
	double GenericGenerationRandomPathsUnderlyingPrices(int m, double * t_k);
	double GenericComputationOptionPrice(int m, int N, double * t_k);
	
// Display of an option characteristics :
	friend std::ostream& operator<<(std::ostream&, const AbstractOption& option);
	
// Destructor : 
	~AbstractOption();
	
public:

// Attributes : 
double sigma;
double K;
double S;
double T;
double r;
double b;

typeOption type;

};

#endif // ABSTRACTOPTION_H
