#include <iostream>
#include <vector>
using namespace std;

int solution(int _N)
{

	/* ���� �ڸ��� ���� +1, -1�� ���� �߰����ָ� �ȴ�. ������ ���ڸ��� 0�϶��� +1��, 9�϶��� -1�� ���־���Ѵ�.
	   DP[i][j]=DP[i-1][j-1]+DP[i-1][j+1] (i=����, j=���ڸ���)
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
	cout << "1���� 100������ ���̸� �Է��Ͻÿ�." << endl;
	cin >> N;
	cout << endl;

	cout << solution(N) << endl;
}
