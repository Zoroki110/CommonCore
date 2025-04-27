
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

// +------------------+
// |    main.cpp       |
// |------------------ |
// | - Calls newZombie()|
// | - Calls randomChump()|
// +------------------+
// 		 |
// -----------------------------------------
// |                                       |
// +----------------------+                +----------------------+
// |   newZombie.cpp       |                |  randomChump.cpp      |
// |----------------------|                |----------------------|
// | - Creates Zombie*     |                | - Creates Zombie     |
// |   on the HEAP         |                |   on the STACK       |
// | - Calls Zombie(name)  |                | - Calls announce()   |
// |   constructor         |                |                      |
// +----------------------+                +----------------------+
// |                                       |
// |                                       |
// |                                       
// +------------------------+             +------------------------+
// |      Zombie.cpp         |             |       Zombie.cpp        |
// |------------------------|             |-------------------------|
// | - Zombie(name) constructor             |
// | - announce() method                     |
// | - ~Zombie() destructor                  |
// +------------------------+             +-------------------------+

// (Zombie.hpp = Class Declaration)
