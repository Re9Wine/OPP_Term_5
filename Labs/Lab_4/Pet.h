using namespace std;

#pragma once
#include <iostream>
#include <string>

class Pet
{
private:
	string kind;
	string name;
	double health;
	double satiety;

public:
	Pet(string kind, string name);
	Pet();
	~Pet();
	void setKind(string kind);
	void setName(string name);
	void setHealth(double health);
	void setStaiety(double satiety);
	string getKind() const;
	string getName() const;
	double getHealth() const;
	double getStaiety() const;
	void feed(double food);
	void play();
	friend ostream& operator << (ostream& out, const Pet& pet);
};
