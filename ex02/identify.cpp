#include <iostream>
#include <string>
#include "Base.hpp"
#include "Derived.hpp"

int main(void) {
	std::cout << "--- Test begin ---" << std::endl;
	Base* b;

	b = new A();
	identify(b);
	identify(*b);
	delete b;

	b = new B();
	identify(b);
	identify(*b);
	delete b;

	b = new C();
	identify(b);
	identify(*b);
	delete b;

	std::cout << std::string(19, '-') << std::endl;

	size_t const count = 7;
	Base* ptr;

	for (size_t i = 0; i < count; i++)
	{
		ptr = generate();
		if (!ptr)
			return 1;
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}

	std::cout << "--- Test end ---" << std::endl;
}
