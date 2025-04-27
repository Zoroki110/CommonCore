#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string&name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon){
	_weapon = &weapon;
}

void HumanB::attack() const {
	if (_weapon)
		std::cout << _name << " DEFONCE LE avec " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " Sans Arme il ne lui reste plus qu'a fuir" << std::endl;
}