#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

// int main() {
// 	{
// 		Weapon arme = Weapon("Mitrailleuse M249");
// 		HumanA bob("Bob", arme);
// 		bob.attack();
// 		arme.setType("Glock 19");
// 		bob.attack();
// 	}
// 	std::cout << std::endl;
// 	{
// 		Weapon arme = Weapon("Bazooka");
// 		HumanB jim("Jim");
// 		jim.setWeapon(arme);
// 		jim.attack();
// 		arme.setType("Tapette a mouche");
// 		jim.attack();
// 	}
// 	return 0;
// }
int main()
{
    std::cout << "=== Test de HumanA (toujours armé) ===" << std::endl;
    {
        Weapon sword("Mitrailleuse M249");
        HumanA arthur("Arthur", sword);
        arthur.attack();
        sword.setType("Bombe atomique");
        arthur.attack();
    }

    std::cout << "\n=== Test de HumanB (peut être désarmé) ===" << std::endl;
    {
        Weapon axe("hache");
        HumanB lancelot("Lancelot");
        lancelot.attack(); // Doit dire qu’il n'a pas d'arme
        lancelot.setWeapon(axe);
        lancelot.attack();
        axe.setType("hache double");
        lancelot.attack();
    }

    std::cout << "\n=== Test de HumanB sans jamais lui donner d'arme ===" << std::endl;
    {
        HumanB merlin("Jack");
        merlin.attack(); // Doit dire qu’il n'a pas d'arme
    }

    std::cout << "\n=== Test de plusieurs humains partageant la même arme ===" << std::endl;
    {
        Weapon club("Bazooka");

        HumanA bob("Bob", club);
        HumanB jim("Jim");

        jim.setWeapon(club);

        bob.attack();
        jim.attack();
		std::cout << std::endl;
        club.setType("Glock 19");

        bob.attack();
        jim.attack();
    }

    return 0;
}