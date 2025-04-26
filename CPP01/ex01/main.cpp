#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Address of brain:    " << &brain << std::endl;
    std::cout << "Address held by PTR: " << stringPTR << std::endl;
    std::cout << "Address held by REF: " << &stringREF << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    std::cout << "Value of brain:       " << brain << std::endl;
    std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF: " << stringREF << std::endl;

    return 0;
}
