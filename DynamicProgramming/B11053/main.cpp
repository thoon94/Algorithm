#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  ���� ������� �迭�� �����ϰ� �׿� ���� DP �迭�� 0���� �ʱ�ȭ
	�ι�° ��Һ��� �˻��Ͽ� ������ ��Ұ����� ũ�� DP ����� �� +1  (ù��° ��Ҵ� 0���� �ʱ�ȭ �ֳĸ� ù��° ���� ���� +1�� �ϱ����ؼ�)
*/
int solution(vector<int> _arr, vector<int> _DP)
{

	int size = _arr.size();

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (_arr[i] > _arr[j])
			{
				_DP[i] = max(_DP[i], _DP[j] + 1);
			}
		}
	}
	vector<int>::iterator ele = max_element(_DP.begin(), _DP.end());
	return *ele;
}

void main()
{
	int N = 0;
	cin >> N;
	vector<int> arr(N + 1, 0);
	vector<int> DP(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cout << solution(arr, DP) << endl;
}