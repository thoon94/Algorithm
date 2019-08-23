#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Solution(vector<int> &_vec)
{
	int size = _vec.size();
	int sum = 0;
	int retval = 0;
	bool check = false;
	for (int i = 0; i < size; i++)
	{
		sum += _vec[i];
		if (_vec[i] == 0)
			check = true;
	}
		

	if ((sum % 3 == 0)&&(check))
	{
		sort(_vec.begin(), _vec.end());
		for (int i = size-1; i >= 0; i--)
		{
			retval += _vec[i] * pow(10, i);
		}
		return retval;
	}
	else
		return -1;
}

void main()
{
	int num = 0;
	cin >> num;
	vector<int> digit;
	while (!num==0)
	{
		digit.push_back(num % 10);
		num = num / 10;
	}

	cout << Solution(digit) << endl;

}