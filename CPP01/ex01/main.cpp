#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int numberOfZombies = 5;

    Zombie* horde = zombieHorde(numberOfZombies, "Zombie");

    if (horde != NULL) {
        for (int i = 0; i < numberOfZombies; ++i) {
            horde[i].announce();
        }
    }

    delete[] horde;

    return 0;
}