#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
	public :
		static void convert(const std::string& str);
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);

		static void fromChar(char c);
		static void fromInt(int i);
		static void fromFloat(float f);
		static void fromDouble(double d);
};


#endif