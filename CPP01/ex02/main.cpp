#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Address de brain:       " << &brain << std::endl;
    std::cout << "Address pointe par PTR: " << stringPTR << std::endl;
    std::cout << "Address pointe par REF: " << &stringREF << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    std::cout << "Valeur de brain:         " << brain << std::endl;
    std::cout << "Valeur pointe de PTR:    " << *stringPTR << std::endl;
    std::cout << "Valeur reference de REF: " << stringREF << std::endl;

    return 0;
}
