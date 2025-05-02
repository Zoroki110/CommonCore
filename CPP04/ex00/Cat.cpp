#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned!" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miaouuu ~" << std::endl;
}
