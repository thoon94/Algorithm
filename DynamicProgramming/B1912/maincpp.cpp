#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> _v)
{
	int max = 0;
	int temp = 0;
	int len = _v.size();
	for (int i = 0; i < len; i++)
	{
		temp = 0;
		for (int j = i; j < len; j++)
		{
			temp += _v[j];
			if (max < temp)
				max = temp;
		}
	}
	return max;
}

void main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(-4);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(-35);
	vec.push_back(12);
	vec.push_back(21);
	vec.push_back(-1);

	cout << solution(vec) << endl;
	
}