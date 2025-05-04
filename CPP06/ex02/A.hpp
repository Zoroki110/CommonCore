#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public :
	A();
	A(const A& copy);
	A& operator=(const A& copy);
	~A();
};

#endif