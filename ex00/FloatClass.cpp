#include "FloatClass.hpp"

FloatClass::FloatClass() {
	setFloatValue(0.0f);
}

FloatClass::FloatClass(const FloatClass& other) : BaseCastClass(other.getStr()) {
	*this = other;
}

FloatClass& FloatClass::operator=(const FloatClass& other) {
	BaseCastClass::operator=(static_cast<BaseCastClass>(other));
	setFloatValue(other.getFloatValue());
	return (*this);
}

FloatClass::~FloatClass() {

}

void FloatClass::setPseudo() {
	if (!getStr().compare("-inff")) setFloatValue(-INFINITY);
	else if (!getStr().compare("nanf")) setFloatValue(NAN);
	else if (!getStr().compare("+inff") || !getStr().compare("inff") ) setFloatValue(INFINITY);
}

int FloatClass::getFrictonalPartCount() {
	float				f;
	std::ostringstream stream;
	int			frictonal_part;


	if (getFloatValue() < 0.0f) f = std::ceil(getFloatValue());
	else f = std::floor(getFloatValue());
	f = std::fabs(f - getFloatValue());
	stream << f;

	frictonal_part = static_cast<int>(stream.str().length());
	frictonal_part != 1 ? frictonal_part -= 2 : frictonal_part;
	return (frictonal_part);
}

void FloatClass::printFloat() {
	std::cout << "float: ";
	try
	{
		checkOverflow();
		std::cout << std::fixed << std::setprecision(getFrictonalPartCount());
		std::cout << getFloatValue() << 'f' << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

bool FloatClass::IsFloat() {
	if (static_cast<char>(*(getStr().end() - 1)) != 'f'
		|| !getStr().compare("+inf") || !getStr().compare("-inf")
			|| !getStr().compare("inf")) return (false);
	checkOverflow();

	setType(FLOAT);
	if (getIsSpecial()) setPseudo();
	else setFloatValue(strtof(getStr().c_str(), NULL));
	return (true);
}

void FloatClass::checkOverflow() {
	errno = 0;
	strtof(getStr().c_str(), NULL);
	if (errno == ERANGE) {
		if (getType() == NON) std::cout << "float: ";
		throw(OutOfRange());
	}
}

float FloatClass::getFloatValue() const {
	return (this->float_value);
}

void FloatClass::setFloatValue(float float_value) {
	this->float_value = float_value;
}

