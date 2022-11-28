#include <iostream>
#include "Pet.h"
#include "Cat.h"

int main(){
	try
	{
		Cat cat = Cat();

		cout << cat << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}
}
