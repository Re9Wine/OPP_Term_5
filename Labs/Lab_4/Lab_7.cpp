#include <iostream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"

int main(){
	try
	{
		srand(time(NULL));

		Cat gray("Gray");
		Dog zeus("Zeus");
		Pet* pets[] = { &gray, &zeus };

		for (int i = 0; i < size(pets); i++) {
			pets[i]->play();
			pets[i]->state();
			pets[i]->feed(10);
			pets[i]->state();
		}

	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}
}
