#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== TEST 1: Formulaire valide signé par un bureaucrate suffisant ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        Form contrat("Contrat", 42, 30);
        std::cout << contrat << std::endl;

        alice.signForm(contrat);  // Réussite attendue
        std::cout << contrat << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Bureaucrat avec grade trop bas pour signer ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form attestation("Attestation", 50, 20);
        bob.signForm(attestation); // Échec attendu
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Création d'un formulaire invalide ===" << std::endl;
    try {
        Form erreur("Erreur", 0, 151); // Trop haut et trop bas
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Double signature d'un même formulaire ===" << std::endl;
    try {
        Bureaucrat charles("Charles", 10);
        Form papier("Papier", 50, 20);
        charles.signForm(papier);
        charles.signForm(papier); // Pas d’erreur, mais déjà signé
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
