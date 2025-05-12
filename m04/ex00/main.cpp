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

    delete animal;
    delete cat;
    delete dog;
	}

	{
		WrongAnimal	*wronganimal = new WrongAnimal();
		WrongAnimal	*wrongcat = new WrongCat();

		wronganimal->makeSound();
		wrongcat->makeSound();

		delete wronganimal;
		delete wrongcat;
	}


    return (0);
}
