#include <iostream>
#include <string>
#include "Color.hpp"
#include "Data.hpp"

void compare(Data* lhs, Data* rhs) {
	bool compare = (lhs == rhs);

	std::cout
	<< ((compare) ? Color::Modifier(Color::FG_GREEN) : Color::Modifier(Color::FG_RED))
	<< ((compare) ? "equal" : "not equal")
	<< Color::Modifier()
	<< std::endl;
}


int main(void) {
	std::cout << "--- Test begin ---" << std::endl;

	Data* a = new Data(1, "Alice");
	Data* b = new Data(2, "Bob");
	uintptr_t ptrA = serialize(a);
	uintptr_t ptrB = serialize(b);

	std::cout << "a: " << *a << " at " << a << std::endl;
	std::cout << "b: " << *b << " at " << b << std::endl;
	std::cout << "ptrA: " << ptrA << std::endl;
	std::cout << "ptrB: " << ptrB << std::endl;

	std::cout << "---" << std::endl;

	std::cout << "a == deserialize(ptrA):" << std::endl;
	compare(a, deserialize(ptrA));
	std::cout << "b == deserialize(ptrB):" << std::endl;
	compare(b, deserialize(ptrB));

	std::cout << "a == deserialize(ptrB):" << std::endl;
	compare(a, deserialize(ptrB));
	std::cout << "b == deserialize(ptrA):" << std::endl;
	compare(b, deserialize(ptrA));

	delete a;
	delete b;

	std::cout << "--- Test end ---" << std::endl;
}
