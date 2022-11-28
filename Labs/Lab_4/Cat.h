using namespace std;

#pragma once
#include "Pet.h"


class Cat : public Pet
{
private:
	string breed;

public:
	Cat();
	Cat(string breed, string name);
	string getBreed() const;
	friend ostream& operator << (ostream& out, const Cat& cat);
};
