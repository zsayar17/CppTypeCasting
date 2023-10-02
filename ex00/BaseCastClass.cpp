#include "BaseCastClass.hpp"

BaseCastClass::BaseCastClass() {

}

BaseCastClass::BaseCastClass(std::string str) {
	setStr(str);
	setIsSpecial(false);
	setType(NON);
}

BaseCastClass::BaseCastClass(const BaseCastClass& other) {
	*this = other;
}

BaseCastClass& BaseCastClass::operator=(const BaseCastClass& other) {
	setStr(other.getStr());
	setIsSpecial(other.getIsSpecial());
	setType(other.getType());
	return (*this);
}

BaseCastClass::~BaseCastClass() {

}

void BaseCastClass::checkPseudo() {
	if (!str.compare("nan") || !str.compare("nanf"));
	else if (!str.compare("-inf") || !str.compare("-inff"));
	else if (!str.compare("inf") || !str.compare("inff"));
	else if (!str.compare("+inf") || !str.compare("+inff"));
	else return ;
	setIsSpecial(true);
}

void BaseCastClass::isValid() {
	char	*end_ptr;

	checkPseudo();
	if (str.length() == 1 || getIsSpecial()) return;
	strtod(str.c_str(), &end_ptr);
	if (!(*end_ptr == '\0' || (*end_ptr == 'f' && *(end_ptr + 1) == '\0'))) throw (InvalidArg());
}

bool BaseCastClass::getIsSpecial() const {
	return (this->is_special);
}

int BaseCastClass::getType() const {
	return (this->type);
}

std::string BaseCastClass::getStr() const {
	return (this->str);
}

void BaseCastClass::setIsSpecial(bool is_special) {
	this->is_special = is_special;
}

void BaseCastClass::setType(int type) {
	this->type = type;
}

void BaseCastClass::setStr(std::string str) {
	this->str = str;
}

const char* BaseCastClass::OutOfRange::what() const throw() {
	return ("Out Of Range");
}

const char* BaseCastClass::InvalidArg::what() const throw() {
	return ("Invalid Argument");
}

const char* BaseCastClass::ImpossibleError::what() const throw() {
	return ("impossible");
}
