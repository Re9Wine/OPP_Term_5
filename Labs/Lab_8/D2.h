using namespace std;

#pragma once
#include <string>
#include <iostream>
#include "D1.h"
#include "D3.h"

class D2 : private D3, public D1
{
private:
	string d2_value;

public:
	D2() {
		d2_value = "D2";
	}

	void show(){
		D1::B1::show();
		D1::B2::show();
		D3::show();

		cout << "Class D2, value = " << d2_value << endl;
	}
};
