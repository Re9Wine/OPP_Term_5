using namespace std;

#pragma once
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
	void setKind(string kind);
	void setName(string name);
	void setHealth(double health);
	void setStaiety(double satiety);
	string getKind();
	string getName();
	double getHealth();
	double getStaiety();
	void feed(double food);
};
