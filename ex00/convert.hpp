#ifndef CONVERT_H
#define CONVERT_H

#include <string>

namespace ft_literal
{
	enum type {
		UNKOWN,
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO_FLOAT,
		PSEUDO_DOUBLE
	};
	type detectType(std::string const& s);
	void convert(char val);
	void convert(int val);
	void convert(float val);
	void convert(double val);
} // namespace literal


#endif
