#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");

    std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Scavy");

    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n--- Actions ---\n" << std::endl;

    clap.attack("target A");
    scav.attack("target B");
    frag.attack("target C");

    std::cout << std::endl;

    scav.guardGate();
    frag.highFivesGuys();

    std::cout << "\n--- End of main ---\n" << std::endl;

    return 0;
}
