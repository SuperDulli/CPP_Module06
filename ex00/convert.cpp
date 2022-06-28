#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "convert.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "usage: covert <literal>" << std::endl;
		return 1;
	}
	std::string const input = argv[1];
	ft_literal::type const typeOfInput = ft_literal::detectType(input);
	std::cout << typeOfInput << std::endl;

	std::cout << (int) std::numeric_limits<char>::min() << std::endl;
	std::cout << (int) std::numeric_limits<char>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;
	std::cout << std::setprecision(9) << static_cast<float>(std::numeric_limits<int>::max()) << std::endl;

	// char c;
	// int i;
	// float f;
	// double d;

	switch (typeOfInput)
	{
	case ft_literal::UNKOWN:
		std::cerr
		<< "Unkown input literal: '" << input
		<< "'. Supported types are char, int, float (with -inff, +inff, nanf)"
		<< "and double (with -inf, +inf, nan)"
		<< std::endl;
		return 1;
		break;
	case ft_literal::CHAR:
		ft_literal::convert(input.front());
		break;
	case ft_literal::INT:
		ft_literal::convert(atoi(input.c_str()));
		break;
	case ft_literal::FLOAT:
		ft_literal::convert(strtof(input.c_str(), NULL));
		break;
	case ft_literal::DOUBLE:
		ft_literal::convert(strtod(input.c_str(), NULL));
		break;
	default:
		break;
	}
	return 0;
}

void showError(std::string const& type, std::string msg) {
	std::cout << type << ": " << msg << std::endl;
}

void showChar(char c) {
	if (!isprint(c)) {
		showError("char", "Non displayable");
		return;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void showInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void showFloat(float f) {
	std::cout << "float: " << std::showpoint << f << "f" << std::endl;
	std::cout << std::noshowpoint;
}

void showDouble(double d) {
	std::cout << "double: " << std::showpoint << d << std::endl;
	std::cout << std::noshowpoint;
}

ft_literal::type ft_literal::detectType(std::string const& s) {
	if (s.length() == 1) {
		if (isdigit(s.front())) return ft_literal::INT;
		return ft_literal::CHAR;
	}
	if (s == "nanf" || s == "-inff" || s == "+inff") {
		return ft_literal::PSEUDO_FLOAT;
	}
	if (s == "nan" || s == "-inf" || s == "+inf") {
		return ft_literal::PSEUDO_DOUBLE;
	}

	size_t i = 0;
	while (i < s.length() && isspace(s.at(i))) i++; 
	if (i == s.length()) return ft_literal::UNKOWN;
	if (s.at(i) == '+' || s.at(i) == '-') i++;
	if (i == s.length()) return ft_literal::UNKOWN;
	while (i < s.length() && isdigit(s.at(i))) i++;
	if (i == s.length())
		return ft_literal::INT;
	if (s.at(i) == '.') {
		i++;
		if (i == s.length()) return ft_literal::DOUBLE;
		if (isalpha(s.at(i) && s.at(i) != 'f')) return ft_literal::UNKOWN;
		while (i < s.length() && isdigit(s.at(i))) i++;
		if (i == s.length()) return ft_literal::DOUBLE;
		if (i == s.length() - 1 && s.at(i) == 'f') return ft_literal::FLOAT;
	}
	return ft_literal::UNKOWN;
}

void ft_literal::convert(char val) {
	char const		c = static_cast<char>(val);
	int const		i = static_cast<int>(val);
	float const		f = static_cast<float>(val);
	double const	d = static_cast<double>(val);
	showChar(c);
	showInt(i);
	// std::cout << std::setprecision(1) << std::fixed;
	showFloat(f);
	showDouble(d);
}

void ft_literal::convert(int val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		showChar(static_cast<char>(val));
	} else {
		showError("char", "impossible");
	}	
	showInt(static_cast<int>(val));
	showFloat(static_cast<float>(val));
	showDouble(static_cast<double>(val));
}

void ft_literal::convert(float val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		showChar(static_cast<char>(val));
	} else {
		showError("char", "impossible");
	}
	// int
	if (val < static_cast<float>(std::numeric_limits<int>::max())
		&& val > static_cast<float>(std::numeric_limits<int>::min())) {
		showInt(static_cast<int>(val));
	} else {
		showError("int", "impossible");
	}
	showFloat(static_cast<float>(val));
	showDouble(static_cast<double>(val));
}

void ft_literal::convert(double val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		showChar(static_cast<char>(val));
	} else {
		showError("char", "impossible");
	}
	// int
	if (val < static_cast<float>(std::numeric_limits<int>::max())
		&& val > static_cast<float>(std::numeric_limits<int>::min())) {
		showInt(static_cast<int>(val));
	} else {
		showError("int", "impossible");
	}
	// float
	if (val < static_cast<double>(std::numeric_limits<float>::max())
		&& val > static_cast<double>(std::numeric_limits<float>::min())) {
		showFloat(static_cast<float>(val));
	} else {
		showError("float", "impossible");
	}
	showDouble(static_cast<double>(val));
}
