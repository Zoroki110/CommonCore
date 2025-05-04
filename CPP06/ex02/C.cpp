#include "C.hpp"

C::C() {}
C::C(const C& other) { (void)other; }
C& C::operator=(const C& other) {
    (void)other;
    return *this;
}
C::~C() {}