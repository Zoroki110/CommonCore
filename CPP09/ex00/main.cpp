#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int ac, char **av) 
{
	if (ac != 2) {
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1; //check si nb argument good
	}
	std::ifstream input(av[1]); //ouvre le fichier
	if (!input.is_open()) {
		std::cerr << "Error: could not open file " << av[1] << std::endl;
		return 1; //check si fichier s'est ouvert
	}
	BitcoinExchange btc; //cree un objet class
	btc.launchDataBase("data.csv"); //lance la base de donnee
	std::string line; //creer une string pour stocker les lignes
	std::getline(input, line); //Ignore 1er ligne
	while (std::getline(input, line)) 
	{
		std::istringstream ss(line); //transforme ligne en stream
		size_t sep = line.find('|'); //trouve separateur
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; //check si '|' existe
		}
		std::string date = line.substr(0, sep - 1); //recup date
		std::string value = line.substr(sep + 2);	//recup valeur
		if (!btc._isValidDate(date)) {
			std::cerr << "Error: bad date => " << date << std::endl;
			continue; //check si date valid
		}
		if (!btc._isValidValue(value)) {
			double val = atof(value.c_str());
            if (val < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue; //check si valeur valid
		}
		float rate = btc.getExchangeRate(date); //recup date et valeur
		float val = atof(value.c_str()); //converti la valeur en float
		std::cout << date << " => " << value << " = " << rate * val << std::endl; //affiche le resultat
	}
	return 0;
}