using namespace std;

#pragma once
#include <string>
#include <iostream>

class B1
{
private:
	string b1_value;

public:
	B1() {
		b1_value = "B1";
	}

	void show() {
		cout << "Class B1, value = " << b1_value << endl;
	}
};

