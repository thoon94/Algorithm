#include <iostream>
using namespace std;


int MinNum(int kg)
{
	int numA, numB, remain;

	numA = kg / 5;
	remain = kg % 5;

	if (remain % 3 == 0)
	{
		numB = remain / 3;
		return numA + numB;
	}

	numA = kg / 3;
	remain = kg % 3;
	if (remain == 0)
		return numA;
	else
		return -1;

	return -1;
}

void main()
{
	int Kg;
	while (1)
	{
		cin >> Kg;
		cout << MinNum(Kg) << endl;
	}


}