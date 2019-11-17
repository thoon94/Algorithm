#include<iostream>
#include<vector>
using namespace std;

/* �Է¹޴� �����ɻ�� �����ɻ��� ���� �����̱� ������ �����ɻ縦 ������������ ���� �����Ѵ�.
	�� �� �����ɻ� 1���� ������ �հ��̹Ƿ� 2����ʹ� 1���� ���� ������ ���ϸ鼭 �հ��ڸ� �߸���.
	���� 3���� �հ��ڷ� �Ǵ��� �ȴٸ� 4����ʹ� 3���� ���� ������ ���ϸ鼭 ��������.
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