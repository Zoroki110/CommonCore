#include <cstdlib>
#include <ctime>
#include <iostream>


#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate() {
	std::srand(std::time(NULL));
	int r = std::rand() % 3;

	switch (r) {
		case 0 : 
			std::cout << "Generate A" << std::endl;
			return new A();
		case 1 :
			std::cout << "Generate B" << std::endl;
			return new B();
		default :
			std::cout << "Generate C" << std::endl;
			return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p)) 
		std::cout << "Type is C" << std::endl;
	else	
		std::cout << "Type is unknown" << std::endl;
}

void identify(Base& p) {
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type is B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type is C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}

int main() {
	Base* p = generate();
	std::cout << "Identification avec pointeur" << std::endl;
	identify(p);

	std::cout << "Identification avec reference//adresse" << std::endl;
	identify(*p);

	delete p;
	return 0;
}