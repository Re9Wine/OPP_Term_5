using namespace std;

#include "Cat.h"
#include <iostream>

Cat::Cat(string name) : Pet("Cat", name)
{
}

Cat::Cat() : Cat("Alex")
{
}

void Cat::feed(double food)
{
	satiety += food * 0.5;

	cout << "You feed " << name << "\n" << endl;

	if (satiety >= 100) {
		satiety = 100;

		cout << name << "is full\n" << endl;
	}
}

void Cat::play()
{
	cout << "You played with " << name << "\n" << endl;

	satiety -= 10;

	if (satiety <= 0) {
		satiety = 0;

		cout << name << "was hungry\n" << endl;
	}
}
