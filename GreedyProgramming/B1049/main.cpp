#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  2���� ����� �� ���� 
	1. ��Ű�� ���� ���� 6�� ���� ���� ������ ���: ��Ű���� �����ϰ� �������� ������ ����
	2. ��Ű�� ���� ���� 6�� ���� ���� ��� ���: ������ ��� �����Ѵ�.

	�� 2���� ����� ���� �����ϰ� �־��� �귣�� ������� �ּڰ��� ���Ѵ�.
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