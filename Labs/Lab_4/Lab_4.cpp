#include <iostream>
#include "Pet.h"

int main(){
	try
	{
		Pet pets[2] = { Pet(), Pet("Cat", "Tom") };

		for (Pet pet : pets)
		{
			pet.state();
			cout << endl;
		}
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}
}
