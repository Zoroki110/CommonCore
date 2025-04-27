#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	private : 
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void)const ;
	public :
		Harl();
		~Harl();

		void complain(std::string level);
};


#endif