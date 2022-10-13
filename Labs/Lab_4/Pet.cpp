using namespace std;

#include "Pet.h"
#include <iostream>
#include <string>

Pet::Pet(string kind, string name)
{
	this->kind = kind;
	this->name = name;
	health = 10;
	satiety = 100;
}

Pet::Pet() : Pet("Dog", "Leo")
{
}

Pet::~Pet() {
	cout << getName() << " is dead" << endl;
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
	if (health <= 0) {
		delete this;
	}
	else if (health > 100) {
		this->health = 100;

		throw getName() + "is healthy";
	}
	else {
		this->health = health;
	}
}

void Pet::setStaiety(double satiety) {
	if (satiety <= 0) {
		throw getName() + "is hungry";
		setStaiety(0);
	}
	else if (satiety > 100) {
		this->satiety = 100;

		throw getName() + "is full";
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
	setStaiety(servingSize * 0.1 + getStaiety());

	cout << "You conquered " << getName() << ". His satiety = " << getStaiety() << endl;
}

void Pet::play() {
	bool wasSuccess = rand() % 2;

	if (wasSuccess) {
		cout << "You played well with " << getName() << endl;

		setHealth(getHealth() + 5);
	}
	else {
		cout << getName() << " got hurt while playing" << endl;

		setHealth(getHealth() - 4);
	}

	setStaiety(getStaiety() - 7);
}

void Pet::state() {
	cout << "Pet kind: " << getKind() << "\n"
		<< "Name: " << getName() << "\n"
		<< "Staiety: " << getStaiety() << "%" << "\n"
		<< "Health: " << getHealth() << "%" << endl;
}