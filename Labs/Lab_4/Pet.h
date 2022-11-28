using namespace std;

#pragma once
#include <string>

class Pet
{
protected:
	string kind;
	string name;
	double health;
	double satiety;

public:
	Pet(string kind, string name);
	Pet();
	~Pet();
	void setName(string name);
	string getKind() const;
	string getName() const;
	double getHealth() const;
	double getSatiety() const;
	virtual void feed(double food) = 0;
	virtual void play() = 0;
	void state();
};
