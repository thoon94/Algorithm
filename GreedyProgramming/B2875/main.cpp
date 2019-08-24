#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int men;
	int women;
	int intern;
}student;

/* 여자인원/2와 남자인원을 비교하여 전자가 크면 여자인원을 인턴인원 값부터 0까지 감소시킨 값을 빼면서 팀을 결성하는 최대값을 구한다.
	후자가 크면 남자인원을 인턴인원 값부터 0까지 감소시킨 값을 빼면서 팀을 결성하는 최대값을 구한다*/
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

/* 여자 인원에 인턴인원 모두 뺄셈할때, 남자 인원에 인턴인원 모두 뺄셈할때, 여자인원+ 남자 인원 - 인턴인원의 값을 3으로 나눌때 
	3가지 경우에서 최솟값*/
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