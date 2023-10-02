#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& other) {
	*this = other;
}

Serializer::~Serializer() {

}

Serializer& Serializer::operator=(const Serializer& other) {
	other.~Serializer();
	return (*this);
}

unsigned long int Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<unsigned long int>(ptr));
}

Data* Serializer::deserialize(unsigned long int  raw) {
	return (reinterpret_cast<Data *>(raw));
}
