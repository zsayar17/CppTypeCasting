#include "DoubleClass.hpp"

DoubleClass::DoubleClass() {
	setDoubleValue(0.0);
}

DoubleClass::DoubleClass(const DoubleClass& other) : BaseCastClass(other.getStr()) {
	*this = other;
}

DoubleClass& DoubleClass::operator=(const DoubleClass& other) {
	BaseCastClass::operator=(static_cast<BaseCastClass>(other));
	setDoubleValue(other.getDoubleValue());
	return (*this);
}

void DoubleClass::setPseudo() {
	if (!getStr().compare("-inf")) setDoubleValue(static_cast<double>(-INFINITY));
	else if (!getStr().compare("nan")) setDoubleValue(static_cast<double>(NAN));
	else if (!getStr().compare("+inf") || !getStr().compare("inf") ) setDoubleValue(static_cast<double>(INFINITY));
}

int DoubleClass::getFrictonalPartCount() {
	double				d;
	std::ostringstream	stream;
	int					frictonal_part;


	if (getDoubleValue() < 0.0) d = std::ceil(getDoubleValue());
	else d = std::floor(getDoubleValue());
	d = std::fabs(d - getDoubleValue());
	stream << d;
	frictonal_part = static_cast<int>(stream.str().length());

	frictonal_part != 1 ? frictonal_part -= 2 : frictonal_part;
	return (frictonal_part);
}

void DoubleClass::printDouble() {
	std::cout << "double: ";
	try
	{
		checkOverflow();
		std::cout << std::fixed << std::setprecision(getFrictonalPartCount());
		std::cout << getDoubleValue() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

bool DoubleClass::IsDouble() {
	checkOverflow();
	setType(DOUBLE);
	if (getIsSpecial()) setPseudo();
	else setDoubleValue(strtod(getStr().c_str(), NULL));
	return (true);
}

void DoubleClass::checkOverflow() {
	errno = 0;
	strtod(getStr().c_str(), NULL);
	if (errno == ERANGE) {
		if (getType() == NON) std::cout << "double: ";
		throw(OutOfRange());
	}
}

DoubleClass::~DoubleClass() {

}

double DoubleClass::getDoubleValue() const {
	return (this->double_value);
}

void DoubleClass::setDoubleValue(double double_value) {
	this->double_value = double_value;
}

