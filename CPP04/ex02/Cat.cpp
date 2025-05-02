#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat created with a brain!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copied with a brain!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned!" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed and brain deleted!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miaouuu ~" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}
