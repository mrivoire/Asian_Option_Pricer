#include "BinLatticeNode.h"

BinLatticeNode::BinLatticeNode()
{
}

// Getters :
double BinLatticeNode::GetNodeUnderlyingValue()
{
	return(underlyingValue);
}

double BinLatticeNode::GetNodeUpdatePrice()
{
	return(updatePrice);
}

bool BinLatticeNode::GetNodeExercisePolicy()
{
	return(exercisePolicy);
}

// Setters : 
void BinLatticeNode::SetNodeUnderlyingValue(double newNodeUnderlyingValue)
{
	underlyingValue = newNodeUnderlyingValue;
}

void BinLatticeNode::SetNodeUpdatePrice(double newNodeUpdatePrice)
{
	updatePrice = newNodeUpdatePrice;
}

void BinLatticeNode::SetNodeExercisePolicy(bool newNodeExercisePolicy)
{
	exercisePolicy = newNodeExercisePolicy;
}

ostream& operator<<(ostream& os, const BinLatticeNode& node)
{
	os << node.underlyingValue << " / " << node.updatePrice <<  " / " << node.exercisePolicy << endl;
	return(os);
}

BinLatticeNode::~BinLatticeNode()
{
}

