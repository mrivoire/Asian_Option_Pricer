#ifndef BINLATTICE_H
#define BINLATTICE_H

#include "iostream"
#include <string>
#include <vector>
#include "ConsoleColor.h"

using namespace std;
template <class Type>
class BinLattice
{
public:
// Constructors : 
	BinLattice();
	BinLattice(int N, vector< vector<Type> > Lattice);
	
// Other Methods : 
	void SetN(int n);
	void SetNode(int n, int i, Type value);
	Type GetNode(int n, int i);
	void Display();
	void Test();
	
// Destructor : 
	~BinLattice();

public:
int N;
vector<vector<Type>> Lattice;

};

template <class Type>
BinLattice<Type>::BinLattice()
{
	SetN(0);
}

template <class Type>
BinLattice<Type>::BinLattice(int _N, vector< vector<Type> > _Lattice)
{
	N = _N;
	Lattice = _Lattice;
}

template <class Type>
void BinLattice<Type>::SetN(int n)
{
	N = n;
	Lattice.resize(N+1);
	for (int i = 0; i < N + 1; i++)
	{
		Lattice[i].resize(i+1);
	}
}

template <class Type>
void BinLattice<Type>::SetNode(int n, int i, Type value)
{
	Lattice[n][i] = value;
}

template <class Type>
Type BinLattice<Type>::GetNode(int n, int i)
{
	return(Lattice[n][i]);
}

template <class Type>
void BinLattice<Type>::Display()
{
	cout << "Lattice valeurs :" << endl;
	cout << blue << "n/i\t";
	for (unsigned int j = 0; j < Lattice.size(); j++)
	{
		cout << j << "\t";
	}
	cout << white << endl;
	for (unsigned int i = 0; i < Lattice.size() ; i++)
	{
		cout << blue << i << white << "\t";
		for (unsigned int j = 0; j < Lattice[i].size(); j++)
		{
			cout << Lattice[i][j] << "\t";
		}
		cout << endl;
	}
}

template <class Type>
void BinLattice<Type>::Test()
{
	BinLattice<Type> b;
	b.SetN(3);
	b.SetNode(0, 0, 2);
	b.SetNode(2, 1, 3);
	b.SetNode(2, 2, 4);
	b.SetNode(3, 0, 5);
	b.SetNode(3, 2, 6);
	b.Display();
}

template <class Type>
BinLattice<Type>::~BinLattice()
{
}



#endif // BINLATTICE_H
