#ifndef __TABLE__
#define __TABLE__


#include <iostream>
using namespace std;

template <typename T>
class Timetable
{
public:
	T StartTime, EndTime, Hours;
public:
	Timetable(T _StartTime = 0, T _EndTime = 0) : StartTime(_StartTime), EndTime(_EndTime), Hours(_EndTime - _StartTime)
	{}

};

#endif // !__TABLE__

