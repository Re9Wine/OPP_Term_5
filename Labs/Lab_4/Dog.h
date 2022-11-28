using namespace std;

#pragma once
#include "Pet.h"

class Dog : public Pet
{
public:
	Dog(string name);
	Dog();
	void feed(double food) override;
	void play() override;
};

