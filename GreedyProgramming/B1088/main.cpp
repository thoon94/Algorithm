#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ���� ���԰� ū ����ũ�� �����Ͽ� ������ ���� �� ���� ���� ���� ū ���� ���̸� ����ϰ� ����
  �Ŀ� ����� ���� ���� ���� ���� ���*/
double Solution(vector<double> &_vec, size_t _num)
{
	vector<double> gap(_num);
	size_t i = 0;
	vector<double>::iterator maxiter, miniter;
	
	for (i; i < _num; i++)
	{
		sort(_vec.begin(), _vec.end());
		maxiter = max_element(_vec.begin(), _vec.end());
		miniter = min_element(_vec.begin(), _vec.end());
		gap[i] = *maxiter - *miniter;
		*maxiter = *maxiter / 2;
	}
	
	return *min_element(gap.begin(), gap.end());
}

void main()
{
	size_t num = 0;
	size_t cut = 0;
	cin >> num;

	vector<double> weight(num, 0);
	for (int i = 0; i < num; i++)
		cin >> weight[i];
	cin >> cut;

	cout<<Solution(weight, cut) << endl;
}