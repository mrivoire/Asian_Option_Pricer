#ifndef CRR_H
#define CRR_H
#include "AbstractOption.h"
#include "BinLattice.h"
#include "BinLatticeNode.h"
#include <iostream> 
#include <ctime>
#include <math.h>

class CRR
{
public:
// Constructors :
	CRR();
	CRR(AbstractOption* option, int nbIterations);
	
// Getters : 
	AbstractOption* GetOption();
	int GetNbIterations();
	BinLattice<BinLatticeNode> GetBinLattice();
	
// Setters : 
	void SetOption(AbstractOption* newOption);
	void SetNbIterations(int newNbIterations);
	void SetBinLattice(BinLattice<BinLatticeNode> newBinLattice);
	
// Other Methods :
double Up(int nbIterations, int nbU);
double Down(int nbIterations, int nbD);
double NeutralRiskProba(int nbIterations);
double ComputeUnderlyingValue(int nbU, int nbD);
void FillUnderlyingValue();
double ComputeUpdatePrice(double optionPriceDown, double optionPriceUP, double underlyingCurrent);
BinLattice<BinLatticeNode> CRRPricing();
//virtual double Payoff(double underlyingValue);
double GetPayoff(int i);
//double ComputeOptionPrice(int i, int j);
double ExercisePolicy(int i, int j);
BinLatticeNode GetFirstNode();
double Factorielle(int nbIterations);
double ClosedFormCRR(int nbIterations);

double GetUnderlyingValue(int line, int column);
double GetPayoff(int line, int column);
double GetUpdatePrice(int line, int column);
double GetOptionPrice(int line, int column);
double GetExercisePolicy(int line, int column);
	
// Destructor :
	~CRR();

public:
AbstractOption* option;
int nbIterations;
BinLattice<BinLatticeNode> binlattice;

};

#endif // CRR_H
