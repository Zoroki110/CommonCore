#include "Serializer.hpp"

Serializer::Serializer() {};
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* p) {
	return reinterpret_cast<uintptr_t>(p);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}