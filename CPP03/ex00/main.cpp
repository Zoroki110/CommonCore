#include "ClapTrap.hpp"

int main() {
	ClapTrap bob("Bob");
	ClapTrap alice("Alice");

	std::cout << std::endl;

	bob.attack("Alice");
	alice.takeDamage(3);

	alice.attack("Bob");
	bob.takeDamage(4);

	bob.beRepaired(2);
	alice.beRepaired(1);

	std::cout << std::endl;

	for (int i = 0; i < 11; i++){
		bob.attack("Alice");
	}
	alice.takeDamage(20);
	alice.attack("Bob");

	return 0;
}