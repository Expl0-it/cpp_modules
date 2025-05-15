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

	

	    delete animal;
    	delete cat;
    	delete dog;
	}

	{
		WrongAnimal	*wronganimal = new WrongAnimal();
		WrongAnimal	*wrongcat = new WrongCat();

		wronganimal->makeSound();
		wrongcat->makeSound();

		std::cout << "WrongAnimal type: " << wronganimal->getType() << std::endl;
		std::cout << "WrongCat type: " << wrongcat->getType() << std::endl;
		

		delete wronganimal;
		delete wrongcat;
	}


    return (0);
}
