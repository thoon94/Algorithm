#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1000);
int solve(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (v[n - 1] != 0)
		return v[n - 1];
	v[n - 1] = solve(n - 1) + solve(n - 2);
	return v[n - 1];
}

void main()
{
	int num = 0;
	cin >> num;
	int val = solve(num);
	cout << val << endl;

}