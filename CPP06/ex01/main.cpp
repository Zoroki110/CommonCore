#include <iostream>
#include "Serializer.hpp"

int main() {
    // Création d’un objet Data
    Data original;
    original.number = 42;
    original.text = "Hello serialization";

    // Affichage de l’adresse d’origine
    std::cout << "Original Data address : " << &original << std::endl;
    std::cout << "Original number       : " << original.number << std::endl;
    std::cout << "Original text         : " << original.text << std::endl;

    // Sérialisation
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\nSerialized value (uintptr_t) : " << raw << std::endl;

    // Désérialisation
    Data* copy = Serializer::deserialize(raw);

    // Vérification
    std::cout << "\nDeserialized Data address : " << copy << std::endl;
    std::cout << "Deserialized number       : " << copy->number << std::endl;
    std::cout << "Deserialized text         : " << copy->text << std::endl;

    // Test final
    if (copy == &original)
        std::cout << "\n✅ Same address! Serialization works." << std::endl;
    else
        std::cout << "\n❌ Error: addresses differ!" << std::endl;

    return 0;
}