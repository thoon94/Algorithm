#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  2가지 경우의 수 존재 
	1. 패키지 값이 낱개 6개 보다 값이 저렴한 경우: 패키지로 구매하고 나머지는 낱개로 구매
	2. 패키지 값이 낱개 6개 보다 값이 비싼 경우: 낱개로 모두 구매한다.

	위 2가지 경우의 수를 생각하고 주어진 브랜드 순서대로 최솟값을 구한다.
*/
int solution(vector<vector<int>> _price, int _N, int _M)
{
	int retval = 100000000;
	for (int i = 0; i < _M; i++)
	{
		if (_price[i][0] > _price[i][1] * 6)
		{
			retval = min(_price[i][1] * _N, retval);
		}
		else
			retval = min((_price[i][0] * (_N / 6)) + (_price[i][1] * (_N % 6)), retval);
	}
	return retval;
}

void main()
{
	int N = 0;
	int M = 0;
	cin >> N >> M;
	vector<vector<int>> price(M, vector<int>(2, 0));

	for (int i = 0; i < M; i++)
		cin >> price[i][0] >> price[i][1];

	cout << solution(price, N, M) << endl;
}