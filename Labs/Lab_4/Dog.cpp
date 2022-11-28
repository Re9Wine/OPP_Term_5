using namespace std;

#include "Dog.h"
#include <iostream>

Dog::Dog(string name) : Pet("Dog", name)
{
}

Dog::Dog() : Dog("Leo")
{
}

void Dog::feed(double food)
{
	satiety += food * 0.25;

	cout << "You feed " << name << "\n" << endl;

	if (satiety >= 100) {
		satiety = 100;

		cout << name << "is full\n" << endl;
	}
}

void Dog::play()
{
	srand(time(0));

	bool wasSuccess = rand() % 10;

	if (wasSuccess > 3) {
		cout << "You played well with " << name << "\n" << endl;

		health += 7;

		if (health >= 100) {
			health = 100;

			cout << name << "is healthy\n" << endl;
		}
	}
	else {
		cout << name << " got hurt while playing\n" << endl;

		health -= 16;

		if (health <= 0) {
			delete this;
		}
	}

	satiety -= 15;

	if (satiety <= 0) {
		satiety = 0;

		cout << name << "was hungry\n" << endl;
	}
}

