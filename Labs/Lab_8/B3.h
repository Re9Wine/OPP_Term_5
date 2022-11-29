using namespace std;

#pragma once
#include <string>
#include <iostream>

class B3
{
private:
	string b3_value;

public:
	B3() {
		b3_value = "B3";
	}

	void show() {
		cout << "Class B3, value = " << b3_value << endl;
	}
};
