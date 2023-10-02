#include "IntClass.hpp"

IntClass::IntClass() {
	setIntValue(0);
}

IntClass::IntClass(const IntClass& other) : BaseCastClass(other.getStr()) {
	*this = other;
}

IntClass& IntClass::operator=(const IntClass& other) {
	BaseCastClass::operator=(static_cast<BaseCastClass>(other));
	setIntValue(other.getIntValue());
	return (*this);
}

IntClass::~IntClass() {

}

void IntClass::printInt() {
	std::cout << "int: ";
	try
	{
		if (getIsSpecial()) throw (ImpossibleError());
		checkOverflow();
		std::cout << getIntValue() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

bool IntClass::isInt() {
	if (getIsSpecial() || *(getStr().end() - 1) == 'f' || getStr().find('.') != std::string::npos) return (false);
	checkOverflow();
	setIntValue(std::atoi(getStr().c_str()));
	setType(INT);
	return (true);
}

void IntClass::checkOverflow() {
	double	d, d_max, d_min;
	char	*end_ptr;

	if (getType() == CHAR) return;
	d_max = static_cast<double>(INT_MAX);
	d_min = static_cast<double>(INT_MIN);
	errno = 0;
	d = strtod(getStr().c_str(), &end_ptr);
	if (errno == ERANGE || d >= d_max + 1 || d <= d_min - 1) {
		if (getType() == NON) std::cout << "int: ";
		throw(OutOfRange());
	}
}

int IntClass::getIntValue() const {
	return (this->int_value);
}

void IntClass::setIntValue(int int_value) {
	this->int_value = int_value;
}

