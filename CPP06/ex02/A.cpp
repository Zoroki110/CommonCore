#include "A.hpp"
#include "Base.hpp"

A::A() {}
A::A(const A& other) { (void)other; }
A& A::operator=(const A& other) {
    (void)other;
    return *this;
}
A::~A() {}