#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur par defaut -> call" << std::endl;

}

Fixed::Fixed(const Fixed& other) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur copy -> call" << std::endl;
	*this = other;
}

Fixed::	Fixed(const int n) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur int -> call" << std::endl;
	_fixedPointValue = n << _fractionalBits;
}

Fixed::	Fixed(const float f) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur float -> call" << std::endl;
	_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Copy assignement operateur -> call" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Deconstructeur par defaut -> call" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "getRawBits fonction membre -> call" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}