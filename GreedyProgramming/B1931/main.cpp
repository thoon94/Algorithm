#include "table.h"
#include <vector>

/*Start time Ascending Bubble Sort*/
void ASCsortStart(vector<Timetable<int>> &vec)
{
	int size = vec.size();
	Timetable<int> temp(0, 0);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - i) - 1; j++)
		{
			if (vec[j].StartTime > vec[j + 1].StartTime)
			{
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

int Solution(vector<Timetable<int>> &vec)
{
	int size = vec.size();
	vector<int> Select(size, 0);
	Timetable<int> temp = vec[0];  
	int SelectPoint = 0;
	Select[0] = 1;
	int ret = 1;

	for (int i = 1; i < size; i++)
	{
		if (temp.EndTime <= vec[i].StartTime)
		{
			temp = vec[i];
			ret++;
			Select[i] = 1;
			SelectPoint = i;
		}
		else
		{
			if (temp.Hours > vec[i].Hours)
			{
				temp = vec[i];
				Select[SelectPoint] = 0;
				Select[i] = 1;
				SelectPoint = i;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (Select[i] == 1)
			cout << "(" << vec[i].StartTime << "," << vec[i].EndTime << ")  ";
	}
	return ret;
}

void main()
{
	int num = 0;
	int start, end;
	cin >> num;
	vector<Timetable<int>> time(num, 0);
	for (int i = 0; i < num; i++)
	{
		cin >> start >> end;
		time[i] = Timetable<int>(start, end);
	}
	ASCsortStart(time);
	cout << Solution(time) << endl;
}
