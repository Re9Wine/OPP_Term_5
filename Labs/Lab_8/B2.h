using namespace std;

#pragma once
#include <string>
#include <iostream>

class B2
{
private:
	string b2_value;

public:
	B2() {
		b2_value = "B2";
	}

	void show() {
		cout << "Class B2, value = " << b2_value << endl;
	}
};
