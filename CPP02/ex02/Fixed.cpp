#include "Fixed.hpp"
#include <cmath>

////constructeur :
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
///////////////////////////////////////////////////////////////////////////
////get + set fonction :
int Fixed::getRawBits(void) const {
	std::cout << "-------------------------------" << std::endl;
	std::cout << "getRawBits fonction membre -> call" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}
////////////////////////////////////////////////////////////////////////////
////convertion fonction :
float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}
///////////////////////////////////////////////////////////////////////////
////Comparaisons:
bool Fixed::operator>(const Fixed& other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}
bool Fixed::operator<(const Fixed& other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}
bool Fixed::operator>=(const Fixed& other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}
bool Fixed::operator<=(const Fixed& other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}
bool Fixed::operator==(const Fixed& other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}
bool Fixed::operator!=(const Fixed& other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}
/////////////////////////////////////////////////////////////////////////////
////Operateur = +, -, /, *:
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
/////////////////////////////////////////////////////////////////////////////
////Incrementation and decrementation :
Fixed& Fixed::operator++() {
	++this->_fixedPointValue;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}
Fixed& Fixed::operator--() {
	--this->_fixedPointValue;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}
////////////////////////////////////////////////////////////////////////////////
////Function min and max:
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
////////////////////////////////////////////////////////////////////////////
//// Surcharge de l’opérateur <<
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}