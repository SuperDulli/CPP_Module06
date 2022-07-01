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

	// reads the string and returns a number to indicate the type of the literal
	type detectType(std::string const& s);

	// convert will cast val into all the other types if possible

	void convert(char val);
	void convert(int val);
	void convert(float val);
	void convert(double val);

	// display results

	void showError(std::string const& type, std::string msg);
	void showChar(char c);
	void showInt(int i);
	void showFloat(float f);
	void showDouble(double d);

} // namespace literal

#endif
