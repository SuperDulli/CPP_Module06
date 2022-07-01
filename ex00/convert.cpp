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

	switch (typeOfInput)
	{		
	case ft_literal::CHAR:
		ft_literal::convert(input.at(0));
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
	case ft_literal::NAN_FLOAT:
		ft_literal::convert(std::numeric_limits<float>::quiet_NaN());
		break;
	case ft_literal::INF_FLOAT:
		ft_literal::convert(std::numeric_limits<float>::infinity());
		break;
	case ft_literal::N_INF_FLOAT:
		ft_literal::convert(-std::numeric_limits<float>::infinity());
		break;
	case ft_literal::NAN_DOUBLE:
		ft_literal::convert(std::numeric_limits<double>::quiet_NaN());
		break;
	case ft_literal::INF_DOUBLE:
		ft_literal::convert(std::numeric_limits<double>::infinity());
		break;
	case ft_literal::N_INF_DOUBLE:
		ft_literal::convert(-std::numeric_limits<double>::infinity());
		break;
	default:
		std::cerr
		<< "Unkown input literal: '" << input
		<< "'. Supported types are char, int, float (with -inff, +inff, nanf)"
		<< " and double (with -inf, +inf, nan)"
		<< std::endl;
		return 1;
		break;
	}
	return 0;
}

void ft_literal::showError(std::string const& type, std::string msg) {
	std::cout << type << ": " << msg << std::endl;
}

void ft_literal::showChar(char c) {
	if (!isprint(c)) {
		ft_literal::showError("char", "Non displayable");
		return;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void ft_literal::showInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ft_literal::showFloat(float f) {
	std::cout << "float: " << std::showpoint << f << "f" << std::endl;
	std::cout << std::noshowpoint;
}

void ft_literal::showDouble(double d) {
	std::cout << "double: " << std::showpoint << d << std::endl;
	std::cout << std::noshowpoint;
}

ft_literal::type ft_literal::detectType(std::string const& s) {
	if (s.length() == 1) {
		if (isdigit(s.front())) return ft_literal::INT;
		return ft_literal::CHAR;
	}
	if (s == "nanf") return ft_literal::NAN_FLOAT;
	if (s == "-inff") return ft_literal::N_INF_FLOAT;
	if (s == "+inff") return ft_literal::INF_FLOAT;

	if (s == "nan") return ft_literal::NAN_DOUBLE;
	if (s == "-inf") return ft_literal::N_INF_DOUBLE;
	if (s == "+inf") return ft_literal::INF_DOUBLE;

	size_t i = 0;
	while (i < s.length() && isspace(s.at(i))) i++; // ignore leading whitespaces
	if (i == s.length()) return ft_literal::UNKOWN;
	if (s.at(i) == '+' || s.at(i) == '-') i++; // optional sign
	if (i == s.length()) return ft_literal::UNKOWN;
	while (i < s.length() && isdigit(s.at(i))) i++; // digit sequence
	if (i == s.length()) return ft_literal::INT;
	if (s.at(i) == '.') {
		i++;
		if (i == s.length()) return ft_literal::DOUBLE; // no suffix
		while (i < s.length() && isdigit(s.at(i))) i++; // digit sequence
		if (i == s.length()) return ft_literal::DOUBLE; // no suffix
		if (s.at(i) == 'e' || s.at(i) == 'E') { // exponent
			i++;
			if (s.at(i) == '+' || s.at(i) == '-') i++; // optional sign
			if (i == s.length()) return ft_literal::UNKOWN;
			while (i < s.length() && isdigit(s.at(i))) i++; // digit sequence
			if (i == s.length()) return ft_literal::DOUBLE;
		}
		if (isalpha(s.at(i) && s.at(i) != 'f' && s.at(i) != 'F')) // unkown suffix
			return ft_literal::UNKOWN;
		while (i < s.length() && isdigit(s.at(i))) i++; // digit sequence
		if (i == s.length()) return ft_literal::DOUBLE; // no suffix
		if (i == s.length() - 1 && (s.at(i) == 'f' || s.at(i) == 'F')) // float suffix
			return ft_literal::FLOAT;
	}
	return ft_literal::UNKOWN;
}

void ft_literal::convert(char val) {
	char const		c = static_cast<char>(val);
	int const		i = static_cast<int>(val);
	float const		f = static_cast<float>(val);
	double const	d = static_cast<double>(val);
	ft_literal::showChar(c);
	ft_literal::showInt(i);
	ft_literal::showFloat(f);
	ft_literal::showDouble(d);
}

void ft_literal::convert(int val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		ft_literal::showChar(static_cast<char>(val));
	} else {
		ft_literal::showError("char", "impossible");
	}	
	ft_literal::showInt(static_cast<int>(val));
	ft_literal::showFloat(static_cast<float>(val));
	ft_literal::showDouble(static_cast<double>(val));
}

void ft_literal::convert(float val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		ft_literal::showChar(static_cast<char>(val));
	} else {
		ft_literal::showError("char", "impossible");
	}
	// int
	if (val < static_cast<float>(std::numeric_limits<int>::max())
		&& val > static_cast<float>(std::numeric_limits<int>::min())) {
		ft_literal::showInt(static_cast<int>(val));
	} else {
		ft_literal::showError("int", "impossible");
	}
	ft_literal::showFloat(static_cast<float>(val));
	ft_literal::showDouble(static_cast<double>(val));
}

void ft_literal::convert(double val) {
	// char
	if (val < std::numeric_limits<char>::max()
		&& val > std::numeric_limits<char>::min()) {
		ft_literal::showChar(static_cast<char>(val));
	} else {
		ft_literal::showError("char", "impossible");
	}
	// int
	if (val < static_cast<float>(std::numeric_limits<int>::max())
		&& val > static_cast<float>(std::numeric_limits<int>::min())) {
		ft_literal::showInt(static_cast<int>(val));
	} else {
		ft_literal::showError("int", "impossible");
	}
	// float
	if (val < static_cast<double>(std::numeric_limits<float>::max())
		&& val > static_cast<double>(std::numeric_limits<float>::min())) {
		ft_literal::showFloat(static_cast<float>(val));
	} else {
		ft_literal::showError("float", "impossible");
	}
	ft_literal::showDouble(static_cast<double>(val));
}
