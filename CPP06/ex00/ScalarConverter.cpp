#include "ScalarConverter.hpp"
#include <climits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {
	try {
		if (isChar(str))
			fromChar(str[0]);
		else if (isInt(str))
			fromInt(std::atoi(str.c_str()));
		else if (isFloat(str))
			fromFloat(std::strtof(str.c_str(), NULL));
		else if (isDouble(str))
			fromDouble(std::strtod(str.c_str(), NULL));
		else
			std::cerr << "Invalid input" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& str) {
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& str) {
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ( i >= str.length() || !std::isdigit(str[i]))
		return false;
	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	bool hasDot = false;
	size_t len = str.length();
	if (len < 2 || str[len - 1] != 'f')
		return false;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < len - 1; i++) {
		if (str[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	bool hasDot = false;
	size_t len = str.length();
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < len; i++) {
		if (str[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (!isdigit(str[i])) {
			return false;
		}
	}
	return hasDot;
}

void ScalarConverter::fromChar(char c) {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(int i) {
	if (i < 0 || i > 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::fromFloat(float f) {
	//pour char
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else	
		std::cout << "char: non displayable" << std::endl;
	//pour int
	if (std::isnan(f) || std::isinf(f) || f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(double d) {
    // char
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // int
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
	std::cout << "int: impossible" << std::endl;
    else
	{
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
        	std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
