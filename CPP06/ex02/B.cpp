#include "B.hpp"

B::B() {}
B::B(const B& other) { (void)other; }
B& B::operator=(const B& other) {
    (void)other;
    return *this;
}
B::~B() {}