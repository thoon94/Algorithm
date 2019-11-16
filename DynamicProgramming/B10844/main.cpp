#include <iostream>
#include <vector>
using namespace std;

int solution(int _N)
{

	/* 이전 자릿수 끝에 +1, -1을 각각 추가해주면 된다. 하지만 끝자리가 0일때는 +1만, 9일때는 -1만 해주어야한다.
	   DP[i][j]=DP[i-1][j-1]+DP[i-1][j+1] (i=길이, j=끝자리수)
	*/
	long MOD = 1000000000;
	vector<vector<int>> DP(101,vector<int>(10,0));
	int retval = 0;
	
	for (int i = 1; i <= 9; i++)
		DP[1][i] = 1;

	for (int i = 2; i <= _N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				DP[i][j] = DP[i - 1][1];
			else if (j == 9)
				DP[i][j] = DP[i - 1][8];
			else
				DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
		}
	}
	for (int i = 0; i <= 9; i++)
		retval += DP[_N][i];
	
	return retval;
}

void main()
{
	int N = 0;
	cout << "1부터 100까지의 길이를 입력하시오." << endl;
	cin >> N;
	cout << endl;

	cout << solution(N) << endl;
}
