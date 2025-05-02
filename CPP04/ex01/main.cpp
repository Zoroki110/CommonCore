#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int size = 4;
    Animal* animals[size];

    std::cout << "\n=== Creating Animals ===" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Catch the ball!");

    Dog dog2 = dog1; // appel au constructeur de copie
    dog2.getBrain()->setIdea(0, "Sleep in the sun");

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
