#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copied!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assigned!" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "* WRONG generic animal sound *" << std::endl;
}
