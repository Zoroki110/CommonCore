#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
	public :
		static uintptr_t serialize(Data* p);
		static Data* deserialize(uintptr_t raw);
	private :
	    Serializer();
	    Serializer(const Serializer&);
	    Serializer& operator=(const Serializer&);
	    ~Serializer();
};

#endif