#include <iostream>
#include <vector>
using namespace std;

/* n-2의 (1*2)의 타일을 추가하는 방법과 (2*2)의 타일을 추가하는 방법 각각 2가지존재
	n-1의 (2*1)의 타일을 추가하는 방법 1가지 존재
	따라서 점화식으로 표현하면 n= 2 * (n-2) + (n-1) 이 된다.
*/
int solution(int _N)
{
	vector<int> DP(_N+1, 0);
	

	if (_N == 1)
		return 1;
	else if (_N == 2)
		return 3;
	else
	{
		DP[1] = 1;
		DP[2] = 3;

		for (int i = 3; i <= _N; i++)
		{
			DP[i] = (2 * (DP[i - 2]) + DP[i - 1]) % 10007;
		}
		return DP[_N];
	}
	
}


void main()
{
	int N = 0;
	cin >> N;
	cout << endl;

	cout << solution(N) << endl;
}