#include<iostream>
#include<vector>
using namespace std;

/* 입력받는 서류심사와 면접심사의 값은 순위이기 때문에 서류심사를 오름차순으로 먼저 정렬한다.
	그 중 서류심사 1등은 무조건 합격이므로 2등부터는 1등의 면접 순위를 비교하면서 합격자를 추린다.
	만약 3등이 합격자로 판단이 된다면 4등부터는 3등의 면접 순위를 비교하면서 내려간다.
*/
int solution(vector<vector<int>> _arr)
{
	int retval = 0;
	int size = _arr.size();
	int comp = _arr[1][1];
	retval++;

	for (int i = 1; i < size; i++)
	{
		if (comp > _arr[i][1])
		{
			comp = _arr[i][1];
			retval++;
		}
			
	}
	return retval;
}

void main()
{
	int T = 0;
	int N = 0;
	int score1 = 0;
	int score2 = 0;
	cin >> T;
	cin >> N;

	vector<vector<int>> arr(N+1, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> score1 >> score2;
		arr[score1][0] = score1;
		arr[score1][1] = score2;
	}

	cout << solution(arr) << endl;
}