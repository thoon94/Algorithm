#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> amount;
vector<int> mem;
int Solution(int num)
{
	mem[1] = amount[1];
	mem[2] = amount[2]+mem[1];
	if (num >= 3)
	{
		for (int i = 3; i <= num; i++)
		{
			mem[i] = max(max(mem[i - 1], mem[i - 2] + amount[i]), mem[i - 3] + amount[i] + amount[i - 1]);
		}
		return mem[num];
	}
	else
		return mem[num];
}
void main()
{
	int num = 0;

	cin >> num;
	amount.resize(num+1);
	mem.resize(num+1);
	for (int i = 1; i <= num; i++)
		cin >> amount[i];

	cout << Solution(num) << endl;
}