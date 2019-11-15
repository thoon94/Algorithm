#include <iostream>
#include <string>
using namespace std;

int solution(string _a, string _b)
{
	int asize = _a.length();
	int bsize = _b.length();
	int diff = asize;
	int temp = 0;
	
	for (int i = 0; i < (bsize - asize) + 1; i++)
	{
		temp = 0;
		for (int j = 0; j < asize; j++)
		{
			if (!(_a[j] == _b[i + j]))
				temp++;
		}
		if (diff >= temp)
			diff = temp;
	}
	return diff;
}

void main()
{
	string a, b;
	cin >> a >> b;

	cout << endl;

	cout << solution(a, b) << endl;

}