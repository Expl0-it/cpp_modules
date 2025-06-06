#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cassert>
//#define NDEBUG

Base*	generate(void) {
	switch (rand() % 3) {
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
		default: return (NULL);
	}
}

void	identyfy(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer points to class A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer points to class B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer points to class C" << std::endl;
}

void	identyfy(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference to class A" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		B b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference to class B" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		C c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference to class C" << std::endl;
	} catch (std::exception& e) {
	}
}

int main(void) {
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		Base* p = generate();
		assert((NULL != p));
		identyfy(p);
		identyfy(*p);
		delete p;
	}
}
