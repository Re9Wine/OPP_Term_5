using namespace std;

#include "Pet.h"
#include <iostream>
#include <string>

Pet::Pet(string kind, string name)
{
	this->kind = kind;
	this->name = name;
	health = 100;
	satiety = 100;
}

Pet::Pet() : Pet("Dog", "Leo")
{
}

void Pet::setKind(string kind) {
	if (kind.empty()) {
		throw "Kind cannot be empty";
	}
	else {
		this->kind = kind;
	}
}

void Pet::setName(string name) {
	if (name.empty()) {
		throw "Name cannot be empty";
	}
	else {
		this->name = name;
	}
}

void Pet::setHealth(double health) {
	if (health < 0) {
		throw "Health cannot be negative";
	}
	else if (health > 100) {
		throw "Health cannot be more than 100%";
	}
	else {
		this->health = health;
	}
}

void Pet::setStaiety(double satiety) {
	if (satiety > 0) {
		throw "Satiety cannot be negative";
	}
	else if (satiety > 100) {
		throw "Satiety cannot be more than 100%";
	}
	else {
		this->satiety = satiety;
	}
}

string Pet::getKind() {
	return this->kind;
}

string Pet::getName() {
	return this->name;
}

double Pet::getHealth() {
	return this->health;
}

double Pet::getStaiety() {
	return this->satiety;
}

void Pet::feed(double servingSize)
{
	setStaiety(servingSize * 0.1);

	cout << "You conquered " << getName() << ". His satiety = " << getStaiety() << endl;
}