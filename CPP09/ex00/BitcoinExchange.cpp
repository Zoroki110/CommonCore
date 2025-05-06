#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){ *this = copy; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
	if (this != &copy) 
		this->_rates = copy._rates;
	return *this;
}

void BitcoinExchange::launchDataBase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); //Saute la 1er ligne

	while (std::getline(file, line)) //lit chaque ligne
	{
		std::istringstream ss(line); // transforme la ligne en stream 
		std::string date, valueStr;
		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) //recup date et valeur du btc 
		{
			float value = std::atof(valueStr.c_str()); //converti valeur en float
			_rates[date] = value; //ajoute date et valeur dans container map
		}
	}
}

float  BitcoinExchange::getExchangeRate(const std::string& date) {
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date) // si on trouve la date =it->first exacte on retourne la value = it->second
		return it->second;
	if (it == _rates.begin()) {
		std::cerr << "Error: date earlier not found" << std::endl;
		return 0.0f;
	}
	--it; //recule a la date d'avant
	return it->second; //retourne la value de la date d'avamnt
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') //check si longueur est good
		return false;

	std::string year = date.substr(0, 4); //recup annee
	std::string month = date.substr(5, 2); //recup mois
	std::string day = date.substr(8, 2); //recup jour

	if (year < "2009" || month < "01" || month > "12" || day < "01" || day > "31") //check les valeur
		return false;
	if ((month == "02" && day > "29") ||
		(month == "04" && day > "30") ||
		(month == "06" && day > "30") ||
		(month == "09" && day > "30") ||
		(month == "11" && day > "30")) //verif des mois a 30j et fevrier a 29j max
		return false;
	return true;
}

bool BitcoinExchange::_isValidValue(const std::string&  value) const {
	char* endPtr;
	double val = std::strtod(value.c_str(), &endPtr); //converti en float

	if (*endPtr != '\0' || value.empty()) //check si la converstion c'est bien passe
		return false;
	if (val < 0.0 || val > 1000.0)
		return false;
	return true;
}