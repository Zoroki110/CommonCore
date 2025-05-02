#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created with a brain!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copied with a brain!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned!" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed and brain deleted!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wouaf Wouaf!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
