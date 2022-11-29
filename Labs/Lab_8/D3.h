using namespace std;

#pragma once
#include <string>
#include <iostream>
#include "B3.h"

class D3 : public B3
{
private:
	string d3_value;

public:
	D3() {
		d3_value = "D3";
	}

	void show() {
		B3::show();

		cout << "Class D3, value = " << d3_value << endl;
	}
};