using namespace std;

#include "Pet.h"
#include <iostream>
#include <string>

Pet::Pet(string kind, string name)
{
	this->kind = kind;
	this->name = name;
	health = 50;
	satiety = 100;
}

Pet::Pet() : Pet("Dog", "Leo")
{
}

Pet::~Pet() {
	cout << name << " is dead\n" << endl;
}

void Pet::setName(string name) {
	if (name.empty()) {
		throw "Name cannot be empty";
	}
	else {
		this->name = name;
	}
}

string Pet::getKind() const { return this->kind; }

string Pet::getName() const { return this->name; }

double Pet::getHealth() const { return this->health; }

double Pet::getSatiety() const { return this->satiety; }

void Pet::state()
{
	cout << "Pet kind: " << kind << "\n"
		 << "Name: " << name << "\n"
		 << "Satiety: " << satiety << "%" << "\n"
		 << "Health: " << health << "%\n" << endl;
}