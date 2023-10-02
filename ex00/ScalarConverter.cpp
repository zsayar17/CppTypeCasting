#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	static_cast<void>(other);
	return (*this);
}

void ScalarConverter::convert(std::string str) {
	Cast cast(str);

	try
	{
		cast.setValue();
		cast.printValues();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

