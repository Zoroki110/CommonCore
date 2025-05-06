#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	public : 
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		void launchDataBase(const std::string& filename);
		float getExchangeRate(const std::string& date);
		bool _isValidDate(const std::string& date) const;
		bool _isValidValue(const std::string& value) const;
	private :
		std::map<std::string, float> _rates;
};

#endif