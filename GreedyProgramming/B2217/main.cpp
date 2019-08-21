#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/* Ascending Sort (insert Sort) */
void ASCSort(vector<int> &vec)
{
/*	int size = vec.size();
	int comp = 0;
	int temp = 0;
	for (int i = 1; i < size; i++)
	{
		comp = vec[i];
		for (int j = 0; j < i; j++)
		{
			if (vec[j] > comp)
			{
				vec[i] = vec[j];
				vec[j] = comp;
				comp = vec[i];
			}
		}
	}*/
	sort(vec.begin(), vec.end(), less<int>());
}

int Solution(vector<int> &vec)
{
	int size = vec.size();
	vector<int> sum(size);
	for (int i = 0; i < size ; i++)
		sum[i]= vec[i] * (size - i);

	vector<int>::iterator iter= max_element(sum.begin(), sum.end());
	return *iter;
}

void main()
{
	int num = 0;
	cin >> num;
	vector<int> weight(num);
	for (int i = 0; i < weight.size(); i++)
		cin >> weight[i];

	ASCSort(weight);
	cout << Solution(weight) << endl;
}