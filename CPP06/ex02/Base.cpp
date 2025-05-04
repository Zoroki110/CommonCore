#include "Base.hpp"

Base::Base() {}
Base::Base(const Base& copy) { (void)copy; }
Base& Base::operator=(const Base& copy) { (void)copy; return *this; }
Base::~Base() {}
