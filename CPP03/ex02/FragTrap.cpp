#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::	FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " succesfully copied" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap " << other._name << " assigned" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0){
		std::cout << "FragTrap " << _name << " can't attack, no energy or dead" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " heavily attacks " << target
			  << ", causing " << _attackDamage << " damage" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " want to high five everyone" << std::endl;
}