using namespace std;

#pragma once
#include "Pet.h"

class Cat : public Pet
{
public:
	Cat(string name);
	Cat();
	void feed(double food) override;
	void play() override;
};

