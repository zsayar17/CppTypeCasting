#include "Cast.hpp"

Cast::Cast() {

}

Cast::Cast(std::string str) : BaseCastClass(str) {

}

Cast::Cast(const Cast& other) : BaseCastClass(other.getStr()), CharClass(), IntClass(), FloatClass(), DoubleClass() {
	*this = other;
}

Cast& Cast::operator=(const Cast& other) {
	setCharValue(other.getCharValue());
	setIntValue(other.getIntValue());
	setFloatValue(other.getFloatValue());
	setDoubleValue(other.getDoubleValue());
	BaseCastClass::operator=(static_cast<BaseCastClass>(other));
	return (*this);
}

Cast::~Cast() {

}

void Cast::setValue() {
	isValid();
	if (isChar() || isInt() || IsFloat() || IsDouble()) return;
}

void Cast::printValues() {
	if (getType() == CHAR)
	{
		setIntValue(static_cast<int>(getCharValue()));
		setFloatValue(static_cast<float>(getCharValue()));
		setDoubleValue(static_cast<double>(getCharValue()));
	}
	else if (getType() == INT)
	{
		setCharValue(static_cast<char>(getIntValue()));
		setFloatValue(static_cast<float>(getIntValue()));
		setDoubleValue(static_cast<double>(getIntValue()));
	}
	else if (getType() == FLOAT)
	{
		setCharValue(static_cast<char>(getFloatValue()));
		setIntValue(static_cast<int>(getFloatValue()));
		setDoubleValue(static_cast<double>(getFloatValue()));
	}
	else if (getType() == DOUBLE)
	{
		setCharValue(static_cast<char>(getDoubleValue()));
		setIntValue(static_cast<int>(getDoubleValue()));
		setFloatValue(static_cast<float>(getDoubleValue()));
	}

	printChar();
	printInt();
	printFloat();
	printDouble();
}
