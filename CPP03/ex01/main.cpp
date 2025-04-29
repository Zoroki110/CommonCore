#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating a ClapTrap..." << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\nCreating a ScavTrap..." << std::endl;
    ScavTrap scav("Scavy");

    std::cout << "\n--- Actions ---\n" << std::endl;

    clap.attack("an enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << std::endl;

    scav.attack("another enemy");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    std::cout << "\n--- End of main ---\n" << std::endl;

    return 0;
}