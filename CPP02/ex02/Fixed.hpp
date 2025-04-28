#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
private :

	int _fixedPointValue;
	static const int _fractionalBits = 8;

public :
//constructeur :
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
//convertion fonction :
	float toFloat(void) const;
	int toInt(void) const;
//get + set fonction :
	int getRawBits(void) const;
	void setRawBits(int const raw);
//Comparaisons:
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
//Operateur = +, -, /, *:
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
//Incrementation and decrementation :
	Fixed& operator++();	//++i
	Fixed operator++(int);	//i++
	Fixed& operator--();	//--i
	Fixed operator--(int); //i--
//Function min and max:
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed&a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed&a, const Fixed& b);
};
// Surcharge de l’opérateur <<
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif