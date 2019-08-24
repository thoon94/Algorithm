#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int men;
	int women;
	int intern;
}student;

/* �����ο�/2�� �����ο��� ���Ͽ� ���ڰ� ũ�� �����ο��� �����ο� ������ 0���� ���ҽ�Ų ���� ���鼭 ���� �Ἲ�ϴ� �ִ밪�� ���Ѵ�.
	���ڰ� ũ�� �����ο��� �����ο� ������ 0���� ���ҽ�Ų ���� ���鼭 ���� �Ἲ�ϴ� �ִ밪�� ���Ѵ�*/
int Solution1(student *_stu)
{
	int max = 0;
	int temp = 0;
	if (_stu->women >= (_stu->men) * 2)
	{
		for (int i = 0; i < _stu->intern; i++)
		{
			if (_stu->women - (_stu->intern - i) >= (_stu->men - i) * 2)
				temp = (_stu->men) - i;
			else
				temp = (_stu->women - (_stu->intern - i)) / 2;
			if (temp > max)
				max = temp;
			else
				break;
		}
	}
	else
	{
		for (int i = 0; i < _stu->intern; i++)
		{
			if ((_stu->men - (_stu->intern - i))*2 <= (_stu->women - i))
				temp = _stu->men - (_stu->intern - i);
			else
				temp = (_stu->women - i) / 2;
			if (temp > max)
				max = temp;
			else
				break;
		}
		
	}
	return max;
}

/* ���� �ο��� �����ο� ��� �����Ҷ�, ���� �ο��� �����ο� ��� �����Ҷ�, �����ο�+ ���� �ο� - �����ο��� ���� 3���� ������ 
	3���� ��쿡�� �ּڰ�*/
int Solution2(student *_stu)
{
	int ret;
	ret = min((_stu->women + _stu->men - _stu->intern) / 3, _stu->women / 2);
	return ret = min(ret, _stu->men);	
}
void main()
{
	student stu;
	cin >> stu.women >> stu.men >> stu.intern;
	cout << Solution1(&stu) << endl;
	cout << Solution2(&stu) << endl;
}