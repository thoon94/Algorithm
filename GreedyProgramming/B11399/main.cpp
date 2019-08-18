#include<iostream>
#include<vector>
using namespace std;

/*Bubble Sort*/
void sort(vector<int> &vec) 
{
	int size = vec.size();
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < (size-i)-1; j++)
		{
			if (vec[j] > vec[j+1])
			{
				int temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

/*SJF(Shortest Job First) ±â¹ý*/
int scheduling(const vector<int> &vec)  
{
	int ret = 0,total = 0;
	int size = vec.size();
	vector<int> sum;
	for (int i = 0; i < size; i++)
	{
		ret += vec[i];
		sum.push_back(ret);
	}
	for (int i = 0; i < size; i++)
		total += sum[i];
	return total;
}

void main()
{
	vector<int> time;
	int count = 0;
	int value = 0;
	cin >> count;
	time.reserve(count);

	for (int i = 0; i < count; i++)
	{
		cin >> value;
		time.push_back(value);
	}
	sort(time);
	value = scheduling(time);
	cout << value << endl;
}