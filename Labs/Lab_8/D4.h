using namespace std;

#pragma once
#include <string>
#include <iostream>
#include "D2.h"

class D4 : protected D2
{
private:
	string d4_value;

public:
	D4() {
		d4_value = "D4";
	}

	void show() {
		D2::show();

		cout << "Class D4, value = " << d4_value << endl;
	}
};

