#include <iostream>
#include <vector>
using namespace std;

/* n-2�� (1*2)�� Ÿ���� �߰��ϴ� ����� (2*2)�� Ÿ���� �߰��ϴ� ��� ���� 2��������
	n-1�� (2*1)�� Ÿ���� �߰��ϴ� ��� 1���� ����
	���� ��ȭ������ ǥ���ϸ� n= 2 * (n-2) + (n-1) �� �ȴ�.
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