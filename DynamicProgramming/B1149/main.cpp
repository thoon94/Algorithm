#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> cost(1001, vector<int>(3, 0));
vector<vector<int>> mem(1001, vector<int>(3, 0));

int Solution(int num)
{
	
	for (int i = 1; i <= num; i++)
	{
		mem[i][0] = min(mem[i - 1][1], mem[i - 1][2]) + cost[i][0];
		mem[i][1] = min(mem[i - 1][0], mem[i - 1][2]) + cost[i][1];
		mem[i][2] = min(mem[i - 1][0], mem[i - 1][1]) + cost[i][2];
	}
	return min(min(mem[num][0], mem[num][1]), mem[num][2]);
}

void main()
{
	int size = 0;

	cin >> size;
	
	cost.resize(size + 1);
	mem.resize(size + 1);
	
	for (int i = 1; i <= size; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	cout << Solution(size) << endl;

	

}