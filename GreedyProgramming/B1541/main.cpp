#include <iostream>
#include <string>
using namespace std;

int solution(string _in)
{
	bool flag = false;
	int size = _in.length();
	string temp = _in;
	int sum = 0;
	int split = 0;
	int data = 0;
	int pos = 0;
	split=_in.find("-");
	temp = temp.substr(split, size - split);
	data = stoi(_in.substr(0, split));
		
	for (int i = 0; i < temp.length(); ++i)
	{
		if (temp[i] == '+')
		{
			int npos1 = temp.find("-", pos);
			sum += stoi(temp.substr(pos+1, npos1-pos));
			pos = i;
		}
		else if (temp[i] == '-')
		{
			int npos = temp.find("+", pos);
			sum += stoi(temp.substr(pos+1, npos - pos));
			pos = i;
		}
	}
	sum += stoi(temp.substr(pos+1, temp.length()-pos+1));
	
	return data-sum;
}

void main()
{
	cout << solution("30-15+55-32+65-27+32-98") << endl;
	//cin >> in;
	//cout << endl;
}