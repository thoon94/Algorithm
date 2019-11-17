#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  수열 순서대로 배열에 저장하고 그에 따른 DP 배열은 0으로 초기화
	두번째 요소부터 검사하여 이전의 요소값보다 크면 DP 저장된 값 +1  (첫번째 요소는 0으로 초기화 왜냐면 첫번째 수열 값을 +1을 하기위해서)
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