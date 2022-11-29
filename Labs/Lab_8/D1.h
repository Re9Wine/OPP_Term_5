using namespace std;

#pragma once
#include <string>
#include <iostream>
#include "B1.h"
#include "B2.h"
#include "B3.h"

class D1 : private B1, protected B3, public B2
{
private:
	string d1_value;

public:
	D1() {
		d1_value = "D1";
	}

	void show(){
		B1::show();
		B2::show();
		B3::show();

		cout << "Class D1, value = " << d1_value << endl;
	}
};