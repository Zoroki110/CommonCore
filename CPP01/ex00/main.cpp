#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;
	std::cout << "---------------------------------" << std::endl;
	randomChump("StackZombie");
	return 0;
}