#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur par defaut -> call" << std::endl;

}

Fixed::Fixed(const Fixed& other) {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Constructeur copy -> call" << std::endl;
	*this = other;
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