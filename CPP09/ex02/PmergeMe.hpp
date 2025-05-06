#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>

class PmergeMe {
	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);

		void process(int ac, char **av); //point entre pour connecter le reste
	private :
		std::vector<int> _vect;
		std::deque<int> _deq;

		void parseInput(int ac, char **av); //convertit les arguments en int et stock dans les vecteurs
		void validateNumber(const std::string& arg); //check si entier est positif
		void mergeSortVector(std::vector<int> &vec); // tri pour vector
		void mergeSortDeque(std::deque<int> &deq); //tri pour deque
		void printResults(const std::string& label, const std::vector<int> &seq); //show le result
};

#endif