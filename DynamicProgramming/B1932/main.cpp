#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Solution(vector<vector<int>> &_tree)
{
	int size = _tree.size();
	vector<vector<int>> mem(size, vector<int>(size));
	
	/* 해당 노드에서 왼쪽으로 연결된 부모노드의 누적된 값과 오른쪽으로 연결된 부모노드의 누적된 값을 
	   비교하여 큰값을 고르는 방법으로 동적 계획법*/
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			mem[i][j] = max(mem[i - 1][j - 1], mem[i - 1][j]) + _tree[i][j];
		}
	}
	vector<int>::iterator iter = max_element(mem[size-1].begin(), mem[size-1].end());
	return *iter;
}

void main()
{
	int num = 0;
	cin >> num;
	vector<vector<int>> tree(num + 1, vector<int>(num + 1));

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> tree[i][j];
	}
	cout << Solution(tree) << endl;
}