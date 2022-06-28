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
		NAN_FLOAT,
		INF_FLOAT,
		N_INF_FLOAT,
		NAN_DOUBLE,
		INF_DOUBLE,
		N_INF_DOUBLE,
	};
	type detectType(std::string const& s);
	void convert(char val);
	void convert(int val);
	void convert(float val);
	void convert(double val);
} // namespace literal


#endif
