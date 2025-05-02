#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "Animal created (default)" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assigned" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "* generic animal sound *" << std::endl;
}