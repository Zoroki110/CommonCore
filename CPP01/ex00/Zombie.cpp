#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : _name(name){
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " is dead!" << std::endl;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}