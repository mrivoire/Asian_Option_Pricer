#include "CRR.h"
CRR::CRR()
{
	nbIterations = 0;
	binlattice.SetN(0);
}

CRR::CRR(AbstractOption* _option, int _nbIterations)
{
	option = _option;
	nbIterations = _nbIterations;
	binlattice.SetN(nbIterations);
}

// Getters : 
AbstractOption* CRR::GetOption()
{
	return(option);
}

int CRR::GetNbIterations()
{
	return(nbIterations);
}

BinLattice<BinLatticeNode> CRR::GetBinLattice()
{
	return(binlattice);
}

// Setters : 
void CRR::SetOption(AbstractOption* newOption)
{
	option = newOption;
}

void CRR::SetNbIterations(int newNbIterations)
{
	nbIterations = newNbIterations;
}

void CRR::SetBinLattice(BinLattice<BinLatticeNode> newBinLattice)
{
	binlattice = newBinLattice;
}

double CRR::Up(int nbIterations, int nbU)
{
	double upValue = pow(exp(option->sigma*sqrt(option->T / nbIterations)), nbU); // U = 1 + u ==> S(1+u) = S*U
	return(upValue);
}

double CRR::Down(int nbIterations, int nbD)
{
	double downValue = pow(exp(-option->sigma*sqrt(option->T / nbIterations)), nbD);
	return(downValue);
}

double CRR::NeutralRiskProba(int nbIterations)
{
	double p = (exp(option->r*(option->T / nbIterations)) - Down(nbIterations, 1)) / (Up(nbIterations, 1) - Down(nbIterations, 1));
	return(p);
}

void CRR::FillUnderlyingValue()
{
	binlattice.Lattice[0][0].underlyingValue = option->S;
	for (unsigned int i = 1; i < binlattice.Lattice.size() ; i++)
	{
		binlattice.Lattice[i][0].underlyingValue = Up(nbIterations,1)*binlattice.Lattice[i-1][0].underlyingValue;
		for (unsigned int j = 1; j < binlattice.Lattice[i].size(); j++)
		{
			binlattice.Lattice[i][j].underlyingValue =  Down(nbIterations,1)*binlattice.Lattice[i-1][j-1].underlyingValue;
		}
	}
}

double CRR::ComputeUnderlyingValue(int nbU, int nbD)
{
	double underlyingValue = option->S*Up(nbU + nbD, nbU)*Down(nbU + nbD, nbD);
	return(underlyingValue);
}

double CRR::ComputeUpdatePrice(double optionPriceDown, double optionPriceUP, double underlyingCurrent)
{
	double updatePrice = exp(-option->r * option->T/nbIterations)*(NeutralRiskProba(nbIterations)*optionPriceUP + (1 - NeutralRiskProba(nbIterations))*optionPriceDown);
	
	updatePrice = option->IntermediateBinLatticeIteration(updatePrice, option->Payoff(underlyingCurrent));
	cout << "Update Price :" << updatePrice << " -- " << NeutralRiskProba(nbIterations) <<  endl;
	
	return(updatePrice);
}

BinLattice<BinLatticeNode> CRR::CRRPricing()
{
	double updatePriceUp, updatePriceDown, underlyingCurrent;
	for(int j = 0; j <= nbIterations; j++)
	{
		binlattice.Lattice[nbIterations][j].updatePrice = option->Payoff(binlattice.Lattice[nbIterations][j].underlyingValue);
		binlattice.Lattice[nbIterations][j].exercisePolicy = false;
			if (binlattice.Lattice[nbIterations][j].updatePrice <= option->Payoff(binlattice.Lattice[nbIterations][j].underlyingValue))
			{ 
				binlattice.Lattice[nbIterations][j].exercisePolicy = true;
			}
	}

	for(int i = nbIterations - 1; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			underlyingCurrent = binlattice.Lattice[i][j].underlyingValue;
			updatePriceUp = binlattice.Lattice[i+1][j].updatePrice;
			updatePriceDown = binlattice.Lattice[i+1][j+1].updatePrice;
			binlattice.Lattice[i][j].updatePrice = ComputeUpdatePrice(updatePriceDown, updatePriceUp, underlyingCurrent);
			binlattice.Lattice[i][j].exercisePolicy = false;
			if (binlattice.Lattice[i][j].updatePrice < option->Payoff(underlyingCurrent))
			{ 
				binlattice.Lattice[i][j].exercisePolicy = true;
			}
			
		}
	}
	
	return(binlattice);
}

double CRR::GetUnderlyingValue(int line, int column)
{
	double underlyingValue = binlattice.Lattice[line][column].underlyingValue;
	return(underlyingValue);
}

double CRR::GetPayoff(int line, int column)
{
	double payoff = option->Payoff(binlattice.Lattice[line][column].underlyingValue);
	return(payoff);
}

double CRR::GetUpdatePrice(int line, int column)
{
	double updatePrice = binlattice.Lattice[line][column].updatePrice;
	return(updatePrice);
}

double CRR::GetExercisePolicy(int line, int column)
{
	double exercisePolicy = binlattice.Lattice[line][column].exercisePolicy;
	return(exercisePolicy);
}

BinLatticeNode CRR::GetFirstNode()
{
	BinLatticeNode firstNode = binlattice.Lattice[0][0];
	return(firstNode);
}

double CRR::Factorielle(int nbIterations)
{
	int result = 0;
	if (nbIterations <= 1)
	{
		result = 1;
	}
	else
	{
		result = nbIterations * Factorielle(nbIterations - 1);
	}
	return(result);
}

double CRR::ClosedFormCRR(int nbIterations)
{
	double binomialCoeff = 0;
	double underlyingValue;
	double payoff = 0;
	double pricingExpectancy = 0;
	double price = 0;
	
	for (int i = 0; i <= nbIterations; i++)
	{
		binomialCoeff = Factorielle(nbIterations) / (Factorielle(i)*Factorielle(nbIterations - i));
		underlyingValue = ComputeUnderlyingValue(i, nbIterations - i);
		payoff = option->Payoff(underlyingValue);
		pricingExpectancy = pow(1 - NeutralRiskProba(nbIterations), nbIterations - i) * pow(NeutralRiskProba(nbIterations), i) * payoff;
		price = price + binomialCoeff * pricingExpectancy;
	}
	price = price * pow(exp(option->r * (option->T / nbIterations)), nbIterations);
	//cout << price << endl;
	return(price);
}

CRR::~CRR()
{
}

