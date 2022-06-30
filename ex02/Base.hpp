#ifndef BASE_H
#define BASE_H

class Base
{
public:

	virtual ~Base(void);

};

// randomly instanciates A, B or C and returns the instance as a Base pointer.
Base* generate(void);

// prints the actual type of the object pointed to by p: 'A', 'B' or 'C'.
void identify(Base* p);

// prints the actual type of the object pointed to by p: 'A', 'B' or 'C'.
void identify(Base& p);

#endif
