#include <iostream>
#include <vector>
using namespace std;

vector<int> mem(91, 0);

/*TOP - DOWN */
int Solution(int num)
{
	if (num <= 2)
		return 1;
	if (mem[num] != 0)
		return mem[num];
	else
		return mem[num] = Solution(num - 1) + Solution(num - 2);
}

/* BOTTOM - UP */
int Solution2(int num)
{
	mem[1] = 1;
	mem[2] = 1;
	if (num >= 3)
	{
		for (int i = 3; i <= num; i++)
			mem[i] = mem[i - 1] + mem[i - 2];
		return mem[num];
	}
	else
		return 1;
}

void main()
{
	int num = 0;
	cin >> num;
	cout << Solution(num) << endl;
	cout << Solution2(num) << endl;
}