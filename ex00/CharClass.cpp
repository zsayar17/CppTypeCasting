#include "CharClass.hpp"

CharClass::CharClass() {
	setCharValue('\0');
}

CharClass::CharClass(const CharClass& other) : BaseCastClass(other.getStr()) {
	*this = other;
}

CharClass& CharClass::operator=(const CharClass& other) {
	BaseCastClass::operator=(static_cast<BaseCastClass>(other));
	setCharValue(other.getCharValue());
	return (*this);
}

CharClass::~CharClass() {

}

bool CharClass::isChar() {
	if (getStr().length() != 1 || (getStr()[0] >= '0' && getStr()[0] <= '9')) return (false);
	checkOverflow();
	setType(CHAR);
	setCharValue(getStr()[0]);
	return (true);
}

void CharClass::checkOverflow() {
	double d, d_min, d_max;

	if (getStr().length() == 1 && !(getStr()[0] >= '0' && getStr()[0] <= '9')) return ;
	errno = 0;
	d = strtod(getStr().c_str(), NULL);
	d_max = static_cast<double>(CHAR_MAX);
	d_min = static_cast<double>(CHAR_MIN);
	if (errno == ERANGE || d >=  d_max + 1.0 || d <= d_min - 1.0) {
		if (getType() == NON) std::cout << "char: ";
		throw(OutOfRange());
	}
}

void CharClass::printChar() {
	std::cout << "char: ";
	try
	{
		if (getIsSpecial()) throw (ImpossibleError());
		checkOverflow();
		isPrintable();
		std::cout << "'" << getCharValue() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

char CharClass::getCharValue() const {
	return (this->char_value);
}

void CharClass::setCharValue(char char_value) {
	this->char_value = char_value;
}

void CharClass::isPrintable() {
	if (getCharValue() < ' ' || getCharValue() > '~') throw(NonDisplayable());
}

const char* CharClass::NonDisplayable::what() const throw() {
	return ("Non displayable");
}
