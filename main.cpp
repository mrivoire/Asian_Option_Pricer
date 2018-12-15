#include <stdio.h>
#include "AbstractOption.h"
#include "EuropeanOption.h"
#include "AmericanOption.h"
#include "CRR.h"

using namespace std;
int main(int argc, char **argv)
{
	//AbstractOption* option = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	AbstractOption* optionA = new AmericanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	CRR crrA(optionA, 2);
	crrA.FillUnderlyingValue();
	crrA.CRRPricing();
	crrA.binlattice.Display();
	
	
	AbstractOption* optionE = new EuropeanOption(0.05, 0.3, 36, 1, 35, 0.5, typeOption::call);
	CRR crrE(optionE, 2);
	crrE.FillUnderlyingValue();
	crrE.CRRPricing();
	//crr.binlattice.Display();
	system("pause");
	return 0;
}
