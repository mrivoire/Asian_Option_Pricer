#ifndef BINLATTICENODE_H
#define BINLATTICENODE_H
#include <iostream>
using namespace std;

class BinLatticeNode
{
public:
// Constructors :
	BinLatticeNode();
	
// Getters : 
	double GetNodeUnderlyingValue();
	double GetNodeUpdatePrice();
	bool GetNodeExercisePolicy();
	
// Setters : 
	void SetNodeUnderlyingValue(double newNodeUnderlyingValue);
	void SetNodeUpdatePrice(double newNodeUpdatePrice);
	void SetNodeExercisePolicy(bool newNodeExercisePolicy);
	
// Other Methods :

	friend ostream& operator<<(ostream& os, const BinLatticeNode& node);
// Destructor : 
	~BinLatticeNode();
	
public:
double underlyingValue;
double updatePrice;
bool exercisePolicy;
};

#endif // BINLATTICENODE_H
