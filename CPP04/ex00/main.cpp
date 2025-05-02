#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== GOOD ANIMALS ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTypes:\n";
    std::cout << "j: " << j->getType() << std::endl;
    std::cout << "i: " << i->getType() << std::endl;

    std::cout << "\nSounds:\n";
    i->makeSound(); // Cat miaow
    j->makeSound(); // Dog wouf
    meta->makeSound(); // Animal generic 

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== WRONG ANIMALS ===" << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nTypes:\n";
    std::cout << "wrongCat: " << wrongCat->getType() << std::endl;

    std::cout << "\nSounds:\n";
    wrong->makeSound();     // Bon son 
    wrongCat->makeSound();  // affichera WrongAnimal son

    delete wrong;
    delete wrongCat;

    return 0;
}
