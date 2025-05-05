#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> a(5);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        std::cout << "Contenu de a : ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        // Test copie
        Array<int> b = a;
        b[0] = 42;

        std::cout << "Contenu de b (copie modifiée) : ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Contenu de a (vérif non modifiée) : ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        // Accès hors-limite
        std::cout << "Accès a[999] : " << a[999] << std::endl; // Exception ici

    } catch (std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}
