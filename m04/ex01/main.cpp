#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	    Animal  *animal = new Animal();
	    Animal  *cat = new Cat();
	    Animal  *dog = new Dog();

		animal->makeSound();
		cat->makeSound();
		dog->makeSound();

		cat->Animal::makeSound();

		std::cout << "Animal type: " << animal->getType() << std::endl;
		std::cout << "Dog type: " << dog->getType() << std::endl;
		std::cout << "Cat type: " << cat->getType() << std::endl;

		// NOTE: Checking if the copy is shallow
		Dog	dogval;
		Cat	catval;
		{
			Dog tmpdog = dogval;
			Cat tmpcat(catval);
			std::cout << "Dogval idea: " << dogval.getIdea(5) << std::endl;
			std::cout << "tmpdog idea: " << tmpdog.getIdea(5) << std::endl;
			std::cout << "catval idea: " << catval.getIdea(5) << std::endl;
			std::cout << "tmpcat idea: " << tmpcat.getIdea(5) << std::endl;
			Cat	*newcat = new Cat;
			Cat	*newcat2 = new Cat();
			*newcat = *newcat2;
			delete newcat;
			delete newcat2;
		}

		std::cout << "Dogval idea: " << dogval.getIdea(5) << std::endl;
		std::cout << "catval idea: " << catval.getIdea(5) << std::endl;

	    delete animal;
    	delete cat;
    	delete dog;
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "Subject main: " << std::endl;

		Animal	*arr[10];
		for (int i = 0; i < 10; i++) {
			if (i < 10 / 2)
				arr[i] = new Cat;
			else
				arr[i] = new Dog;
		}

		std::cout << "Index 0 type: " << arr[0]->getType() << std::endl;
		std::cout << "Index 5 type: " << arr[5]->getType() << std::endl;

		for (int i = 0; i < 10; i++)
			delete arr[i];
	}

    return (0);
}
