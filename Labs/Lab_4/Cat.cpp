using namespace std;

#include "Cat.h"
#include <iostream>
#include <string>

Cat::Cat(string breed, string name) : Pet("Cat", name), breed(breed) {
}

Cat::Cat() : Cat("Munchkin", "Alex") {
}

string Cat::getBreed() const { return this->breed; }

ostream& operator<<(ostream& out, const Cat& cat)
{
	out << "Pet kind: " << cat.getKind() << "\n"
		<< "Name: " << cat.getName() << "\n"
		<< "Breed: " << cat.getBreed() << "\n"
		<< "Staiety: " << cat.getStaiety() << "%" << "\n"
		<< "Health: " << cat.getHealth() << "%" << endl;

	return out;
}
