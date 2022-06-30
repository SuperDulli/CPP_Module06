#include <stdlib.h> // rand
#include <iostream>
#include "Color.hpp"
#include "Base.hpp"
#include "Derived.hpp"

Base::~Base(void) {}

Base* generate(void) {
	Base* result;

	switch ( rand() % 3) {
		case 0:
			result = new A();
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
			break;
		default:
			std::cerr << "RNG out of bounds" << std::endl;
			result = NULL;
			break;
	}
	return result;
}

void identify(Base* p) {
	A* ptrA = dynamic_cast<A*>(p);
	B* ptrB = dynamic_cast<B*>(p);
	C* ptrC = dynamic_cast<C*>(p);

	std::cout << Color::Modifier(Color::FG_GREEN);
	if (ptrA) std::cout << "A";
	if (ptrB) std::cout << "B";
	if (ptrC) std::cout << "C";
	std::cout << Color::Modifier() << std::endl;
}

void identify(Base& p) {
	std::cout << Color::Modifier(Color::FG_BLUE);
	try {
		dynamic_cast<A&>(p);
		std::cout << "A";
	} catch (std::exception& e) {
		static_cast<void>(e); // to make the compiler happy
		try {
			dynamic_cast<B&>(p);
			std::cout << "B";
		} catch (std::exception& e2) {
			static_cast<void>(e2); // to make the compiler happy
			try {
				dynamic_cast<C&>(p);
				std::cout << "C";
			} catch (std::exception& e3) {
				std::cerr << e3.what() << std::endl;
				std::cerr << "Couldn't identify p:" << &p << std::endl;
			}
		}
	}
	std::cout << Color::Modifier() << std::endl;
}
