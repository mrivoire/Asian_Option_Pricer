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
virtual double GetNbMaturities() = 0;
virtual double* GetMaturitiesCollection() = 0;

// Setters : 
void SetSigma(double newSigma);
void SetK(double newK);
void SetS(double newS);
void SetT(double newT);
void Setr(double newr);
void Setb(double newb);

// Other Methods : 
	
// Payoff : 
	virtual double Payoff(double* underlyingValue, int nbUnderlyingValue) = 0;
	virtual double IntermediateBinLatticeIteration(double UpdatePrice, double PayOffTemp) = 0;

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
