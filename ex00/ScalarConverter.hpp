#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include "Cast.hpp"

class ScalarConverter
{
	private:
	/* data */
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(std::string str);
};


#endif
