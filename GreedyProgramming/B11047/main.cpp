#include <iostream>
#include <vector>
using namespace std;

int solution(const vector<int> &_vec, int _data)
{
	int retval = 0;
	size_t _size = _vec.size();

	for (int i= _size -1 ; i >= 0; i--)
	{
		retval += _data / _vec[i];
		_data = _data % _vec[i];
	}
	return retval;
}
void main()
{
	int data = 0;
	int size = 0;
	int value = 0;
	cin >> size >> data;

	vector<int> coin(size,0);
	
	for (int i = 0; i < size; i++)
		cin >> coin[i];
	

	cout << solution(coin, data) << endl;
}