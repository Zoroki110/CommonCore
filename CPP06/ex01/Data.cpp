#include "Data.hpp"

Data::Data() : number(0), text("default") {}
Data::Data(const Data& copy) : number(copy.number), text(copy.text) {}
Data& Data::operator=(const Data& copy) {
	if (this != &copy){
		number = copy.number;
		text = copy.text;
	}
	return *this;
}
Data::~Data() {}