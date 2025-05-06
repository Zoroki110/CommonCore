#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        this->_vect = copy._vect;
        this->_deq = copy._deq;
    }
    return *this;
}

void PmergeMe::process(int ac, char **av) {
	parseInput(ac, av);					//parse les arguments
	printResults("Before: ", _vect);    //affiche vecteur avant tri

	clock_t startVec = clock();  
	mergeSortVector(_vect);       // tri Vector et clock pour avoir le temps
	clock_t endVec = clock();
	clock_t startDeq = clock();
	mergeSortDeque(_deq);		// tri Deque et clock pour avoir le temps
	clock_t endDeq = clock();

	printResults("After: ", _vect);    //affiche vecteur apres tri
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6; //pour avoir le temps en microsecondes
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6; //static_cast pour assurer le bon type

	std::cout << "Time to process a range of " << _vect.size()
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::parseInput(int ac, char **av) {
	for (int i = 1; i < ac; ++i) { 
		std::string arg(av[i]); // converti argument en string
		validateNumber(arg); //check si entier positif
		int num = std::atoi(arg.c_str()); //converti string en int
		_vect.push_back(num); //ajoute et stock dans vector
		_deq.push_back(num); //ajoute et stock dans deque
	}
}

void PmergeMe::validateNumber(const std::string& arg) {
	for (size_t i = 0; i < arg.length(); ++i) {
		if (!std::isdigit(arg[i])) //check si chaye char est un nombre
			throw std::invalid_argument("Invalid argument => " + arg);
	}
	long val = std::atol(arg.c_str());
	if (val < 0 || val > INT_MAX) //check si positif et dans la limite
		throw std::out_of_range("Number out of range => " + arg);
}

void PmergeMe::printResults(const std::string& label, const std::vector<int> &seq) {
	std::cout << label << " "; //label = "Before: " ou "After: "
	for (size_t i = 0; i < 6; ++i) {
		std::cout << seq[i];
		if (i < seq.size() - 1)
			std::cout << " ";
	} 
	std::cout << "... ";
	std::cout << std::endl;
}

void PmergeMe::mergeSortVector(std::vector<int> &vec) { //tri fusion recursive
	if (vec.size() <= 1)
		return;
	
	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2); //separe le container en deux  
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());  //moitie a gauche moitie a droite

	mergeSortVector(left); //on appelle en recursive encore et encore 
	mergeSortVector(right); //jusqu'a ce que le container soit de taille 1

	vec.clear(); //on vide le container pour le remplir trie
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec)); //merge les deux containers trie dans vector 
}

void PmergeMe::mergeSortDeque(std::deque<int> &deq) { //same shit
	if (deq.size() <= 1)
		return;

	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2); //same shit
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end()); //same shit

	mergeSortDeque(left); //same shit
	mergeSortDeque(right); //same shit

	deq.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deq)); //same shit
}