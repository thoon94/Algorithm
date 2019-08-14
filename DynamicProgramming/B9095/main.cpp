#include <iostream>
#include <vector>
using namespace std;
vector<int> v(12, 0);
int solve(int n)
{
	if (n < 0) return 0;
	if (n <= 1) return 1;
	if (v[n] != 0)
		return v[n];

	v[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
	return v[n];
}

void main()
{
	int cnt = 0;
	cin >> cnt;
	int val;
	vector<int> num;
	for (int i = 0; i < cnt; i++)
	{
		cin >> val;
		num.push_back(val);
	}
	for (vector<int>::size_type i = 0; i < num.size(); i++)
	{
		cout << solve(num[i]) << endl;
	}

}