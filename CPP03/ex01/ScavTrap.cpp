#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copied" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap " << _name << " assigned" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0){
		std::cout << "ScavTrap " << _name << " can't attack, no energy or dead" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " viciously attacks " << target
			  << ", causing " << _attackDamage << " point of damage" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "Scavtrap " << _name << " now is in gate keeper mode" << std::endl;	
}