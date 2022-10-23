using namespace std;

#include <iostream>
#include "Time.h"

int main()
{
	try
	{
		Time time_1(1, 1, 1);
		Time time_2(2, 2, 2);
		Time time_3 = time_1 + time_2;

		cout << time_1 << endl;
		cout << time_3 << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}
}
